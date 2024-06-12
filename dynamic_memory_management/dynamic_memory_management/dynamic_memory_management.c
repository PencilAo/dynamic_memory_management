#define _CRT_SECURE_NO_WARNINGS
 //动态内存管理
 //
 //局部变量,函数的形式参数都在栈区 在栈区里申请的空间一般不能变
 //动态内存管理(重要函数)  - 所申请的空间全在堆区，堆区可变
 //malloc , calloc , realloc , free


                       //malloc - void* malloc (size_t size)
#include <errno.h>
#include <string.h>
#include <stdlib.h>
            //c99标准支持的变长数组 - 不意味着长度可变
            //int n;
            //scanf("%d", &n);
            //int arr2[n];
int main()
{
    int arr[10];   //之前的在内存中申请40个字节的方法，弊端：无法灵活改变 
    int*p = (int*)malloc(40);   //当开辟空间失败则返回NULL 要引头文件 stdlib.h
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1; //开辟失败则返回1
    }
    //开辟成功，使用内存
    int i;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    //没有free,并不意味则内存就不回收了,当程序退出的时候，系统会自动回收内存空间,free释放动态开辟的空间
    //free(p);  把p指向的空间释放，即p里的数都被释放，但p的地址没变，p就会变成野指针，所以一般使用后要把p变成NULL ， p = NULl
    //p = NULL;
    return 0;
}
 
int main()
{
    int* p = (int*)malloc(INT_MAX);   // int类型的最大数
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    } //开辟失败例子
    return 0;
}




                           //calloc - void* calloc (size_t num, size_t size);
              //如果使用前要初始化就用calloc，反之则用malloc
              
//开辟10个整形的空间
int main()
{
    int* p = (int*)calloc(10, sizeof(int));
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    } //打印出10个0,说明calloc在开辟空间之前会把内容初始化0
    free(p);
    p = NULL;
    return 0;
}






                                   //realloc - void* realloc (void* ptr, size_t size)
int main()
{
    int* p = (int*)malloc(40);
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    }
    int i;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    //扩容
    int* ret = (int*)realloc(p, 80);              //在之前40个字节的基础上在追加40个字节 ， 这里一般不把新开辟的空间重新赋给p因为如果开辟失败就会返回NULL，这样就会把原来开辟空间里的内容置空，所以这里一般赋值给一个新变量
    free(ret);
    ret = NULL;
    return 0;

    //realloc(NULL, 40); == malloc(40)
}