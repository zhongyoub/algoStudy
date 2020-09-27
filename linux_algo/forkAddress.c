#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

/*
相同的虚拟地址对不同进程来说，对应的page cache是不一样的
*/
int g_var=0;
void waitall(void)
{
	int pid;
	int status;
    for (;;) {
		pid = wait(&status);
        if (pid == -1) {
			if (errno == ECHILD)
				break;
			perror("wait");
			exit(-1);
		}
	poll(NULL, 0, 1);
	}
}

//计算虚拟地址对应的地址，传入虚拟地址vaddr，通过paddr传出物理地址
void mem_addr(unsigned long vaddr, unsigned long *paddr)
{
    int pageSize = getpagesize();//调用此函数获取系统设定的页面大小

    unsigned long v_pageIndex = vaddr / pageSize;//计算此虚拟地址相对于0x0的经过的页面数
    unsigned long v_offset = v_pageIndex * sizeof(uint64_t);//计算在/proc/pid/page_map文件中的偏移量
    unsigned long page_offset = vaddr % pageSize;//计算虚拟地址在页面中的偏移量
    uint64_t item = 0;//存储对应项的值

    int fd = open("/proc/self/pagemap", O_RDONLY); //以只读方式打开/proc/pid/page_map
    if(fd == -1)//判断是否打开失败
    {
        printf("open /proc/self/pagemap error\n");
        return;
    }

    if(lseek(fd, v_offset, SEEK_SET) == -1) //将游标移动到相应位置，即对应项的起始地址且判断是否移动失败
    {
        printf("sleek error\n");
        return; 
    }

    if(read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t))//读取对应项的值，并存入item中，且判断读取数据位数是否正确
    {
        printf("read item error\n");
        return;
    }

    if((((uint64_t)1 << 63) & item) == 0)//判断present是否为0
    {
        printf("page present is 0\n");
        return ;
    }

    uint64_t phy_pageIndex = (((uint64_t)1 << 55) - 1) & item;//计算物理页号，即取item的bit0-54

    *paddr = (phy_pageIndex * pageSize) + page_offset;//再加上页内偏移量就得到了物理地址
}

int main(int argc, char *argv[])
{
	int i;
	int nforks;
	int pid;
	int stat_val;

    unsigned long phy;

    if (argc != 2) {
		fprintf(stderr, "Usage: %s nforks\n", argv[0]);
		exit(-1);
	}
    nforks = atoi(argv[1]);
	printf("%d fork()s\n", nforks);
    printf("Starting at ");
	fflush(stdout);
	stat_val = system("date");
	if (!WIFEXITED(stat_val) || WEXITSTATUS(stat_val)) {
		fprintf(stderr, "system(\"date\") failed: %x\n", stat_val);
	}
	for (i = 0; i < nforks; i++) {
		pid = fork();
	    if (pid == 0) { /* child */
			g_var = i+1;
			printf("g_var var %d, addr %p\n", g_var, &g_var);
            mem_addr(&g_var, &phy);
            printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &g_var, phy);

			//sleep(30);
			exit(0);
		}
		if (pid < 0) { /* parent, upon error */
			perror("fork");
			exit(-1);
		}
	}
/* parent */
    waitall();
	
    printf("main g_var var %d, addr %p\n", g_var, &g_var);

	mem_addr(&g_var, &phy);
    printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &g_var, phy);

    printf("Finished at ");
	fflush(stdout);
	stat_val = system("date");
	
    if (!WIFEXITED(stat_val) || WEXITSTATUS(stat_val)) {
		fprintf(stderr, "system(\"date\") failed: %x\n", stat_val);
	}
	return 0;
}




