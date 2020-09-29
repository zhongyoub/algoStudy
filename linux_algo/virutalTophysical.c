/*
1. Linux文件目录中的/proc记录着当前进程的信息，称其为虚拟文件系统。
在/proc下有一个链接目录名为self，这意味着哪一个进程打开了它，self中存储的信息就是所链接进程的。
self中有一个名为pagemap的文件，专门用来记录所链接进程的物理页号信息。这样通过/proc/pid/pagemap文件，
允许一个用户态的进程查看到每个虚拟页映射到的物理页

2. /proc/pid/pagemap中的每一项都包含了一个64位的值，这个值内容如下所示。
每一项的映射方式不同于真正的虚拟地址映射，其文件中遵循独立的对应关系，
即虚拟地址相对于0x0经过的页面数是对应项在文件中的偏移量
 /proc/pid/pagemap.  This file lets a userspace process find out which
   physical frame each virtual page is mapped to.  It contains one 64-bit
   value for each virtual page, containing the following data (from
   fs/proc/task_mmu.c, above pagemap_read):

    * Bits 0-54  page frame number (PFN) if present//present为1时，bit0-54表示物理页号
    * Bits 0-4   swap type if swapped
    * Bits 5-54  swap offset if swapped
    * Bit  55    pte is soft-dirty (see Documentation/vm/soft-dirty.txt)
    * Bit  56    page exclusively mapped (since 4.2)
    * Bits 57-60 zero
    * Bit  61    page is file-page or shared-anon (since 3.5)
    * Bit  62    page swapped
    * Bit  63    page present//如果为1，表示当前物理页在内存中；为0，表示当前物理页不在内存中

3. 在计算物理地址时，只需要找到虚拟地址的对应项，再通过对应项中的bit63判断此物理页是否在内存中，
若在内存中则对应项中的物理页号加上偏移地址，就能得到物理地址

4. 通过程序获取物理地址并验证写时拷贝技术
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdint.h>

/*
虚拟地址转为物理地址
*/
void mem_addr(unsigned long vaddr, unsigned long *paddr)
{
    int pageSize = getpagesize();//调用此函数获取系统设定的页面大小
    unsigned long v_pageIndex = vaddr / pageSize;//计算此虚拟地址相对于0x0的经过的页面数
    unsigned long v_offset = v_pageIndex * sizeof(uint64_t);//计算在/proc/pid/page_map文件中的偏移量
    unsigned long page_offset = vaddr % pageSize;//计算虚拟地址在页面中的偏移量
    uint64_t item = 0;//存储对应项的值

    int fd = open("/proc/self/pagemap", O_RDONLY);  // 以只读方式打开/proc/pid/page_map
    if(fd == -1)//判断是否打开失败
    {
        printf("open /proc/self/pagemap error\n");
        return;
    }

    if(lseek(fd, v_offset, SEEK_SET) == -1)//将游标移动到相应位置，即对应项的起始地址且判断是否移动失败
    {
        printf("sleek error\n");
        return; 
    }

    if(read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t))   //读取对应项的值，并存入item中，且判断读取数据位数是否正确
    {
        printf("read item error\n");
        return;
    }

    if((((uint64_t)1 << 63) & item) == 0)   //判断present是否为0
    {
        printf("page present is 0\n");
        return ;
    }
    uint64_t phy_pageIndex = (((uint64_t)1 << 55) - 1) & item; //计算物理页号，即取item的bit0-54
    *paddr = (phy_pageIndex * pageSize) + page_offset; //再加上页内偏移量就得到了物理地址

}

//全局变量
const int a=100;
int main()
{
    int b=100;
    static int c=100;
    const int d=100;
    char *str="hello world";
    unsigned long phy = 0;//物理地址

    char *p = (char*)malloc(100);//动态内存

    int pid = fork();//创建子进程
    if(pid == 0)
    {
        //p[0] = '1';//子进程中修改动态内存
        mem_addr((unsigned long)&a, &phy);
        printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &a, phy);
    }
    else
    { 
        mem_addr((unsigned long)&a, &phy);
        printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &a, phy);
    }

    sleep(100);
    free(p);
    waitpid();
    return 0;
}