/*
C语言实现
*/

#include<stdio.h>

struct Bird{
    char name[20];
    char color;
    char addr[30];
    int weight;
    int other;
    void (*print)(void *p);
};

struct fBird{
    struct Bird p;
    char fly[20];
    int scream;
};

/*
struct fBird s;
s.p.name = "bird";
s.p.color = 'b';
s.p.other = 25;
s.p.weight = 65;
s.fly = "0618";
s.scream = 90;
*/

void printBird(void *bird)
{
    if(NULL==bird)
        return;
    struct Bird *p=(struct Bird*)bird;
    printf("run in the Bird\n");
}
void printfBird(void * bird)
{
    if(NULL==bird)
        return;
    struct Bird *p=(struct Bird*)bird;
    printf("run in the fBird\n");
}

void print(void *bird)
{
    if(NULL==bird)
        return;
    struct Bird *p=(struct Bird*)bird;
    p->print(bird);
}

int main()
{
    struct Bird bird;
    struct fBird fbird;
    /*
    fbird.p.name = "bird";
    fbird.p.color = 'b';
    fbird.p.other = 25;
    fbird.p.weight = 65;
    fbird.fly = "0618";
    fbird.scream = 90;  
    */
    bird.print=printBird;
    fbird.p.print=printfBird;
    print(&bird);
    print(&fbird);

    return 0;
}

