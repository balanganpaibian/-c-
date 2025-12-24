#include<stdio.h>
#include<string.h>//发现strcmp函数必须和string.h;
#include<stdlib.h>
#define number(p) (sizeof(p)/sizeof(p[0]))//1. 如果数组里的元素很多,手动数个数很容易数错，而用公式精准2. 数组修改时(这里指的是在编代码的时候，初始化的时候)无需同步改数字，公式会自动计算出新的元素个数，减少代码修改的工作量和出错概率。3. 提高代码的通用性这个公式是通用的，把它写成宏或者函数后，能直接用于其他数组的元素个数计算，不用为每个数组单独写死元素数量，让代码更简洁、可复用。4,在C语言中，不能直接写一个通用的函数来计算任意数组的元素个数，因为数组作为函数参数时会退化为指针， sizeof 在函数内只能得到指针的字节数，无法获取数组的总字节数。但可以通过宏定义实现“类似函数”的效果，或者结合数组类型做针对性函数设计。在你定义的 ARRAY_SIZE 宏里，不需要显式定义 arr 是数组。因为宏是预处理阶段的文本替换，不是函数，它不做类型检查，只在展开时把 arr 当成一个符号，替换到 sizeof 表达式中。
void paixu(int n,char*p[])//1. 不能用return带返回值void函数内部可以写 return; （用于提前结束函数），但绝对不能写 return 表达式; ，否则会编译报错。✅ 合法： return; ❌ 非法： return p; （你之前代码里的错误2. 不能作为赋值语句的右值因为没有返回值，所以不能把void函数的调用结果赋值给变量，否则编译报错。❌ 非法： int res = paixu(9, p); ✅ 合法： paixu(9, p); （直接调用，不接收返回值）
{//为什么用void，因为这个函数的作用是排序，拍了字符在指针指向的位置，不要返回值。（总结，类似的有排序，交换等修改原数据的函数）
     for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
     {
        if(strcmp(p[i],p[j])<0)
        {
            char *t;
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
     }
}
int main()
{
    char *p[]= {"zhang", "gou", "xu", "zheng", "mao", "zhao", "li", "bai", "qing"};//attention!,单引号是单个字符，双引号是字符串；而且字符数组的元素是字符，而不是字符串；
    int n=number(p);
    for(int i=0;i<n;i++){
    printf("%s ",p[i]);
    }
    paixu(9,p);
    printf("\n");
    for(int i=0;i<n;i++){
    printf("%s ",p[i]);
    }
    return 0;
}