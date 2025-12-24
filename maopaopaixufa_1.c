#include<stdio.h>
#include<string.h>//发现strcmp函数必须和string.h;
#include<stdlib.h>
void paixu(int n,int*p[])
{
     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
     {
        p[i]=getchar();
        p[j]=getchar();
        if(strcmp(p[i],p[j])<0)
        {
            char t;
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
     }
     return p;
}
int main()
{
    char p[9]={'zhang','gou','xu','zheng','mao','zhao','li','bai','qing'};//attention!,单引号；而且字符数组的元素是字符，而不是字符串；
    printf("%c",p);
    paixu(9,p[9]);
    printf("%c",p);
}