#define _CRT_SECURE_NO_WARNINGS
 //��̬�ڴ����
 //
 //�ֲ�����,��������ʽ��������ջ�� ��ջ��������Ŀռ�һ�㲻�ܱ�
 //��̬�ڴ����(��Ҫ����)  - ������Ŀռ�ȫ�ڶ����������ɱ�
 //malloc , calloc , realloc , free


                       //malloc - void* malloc (size_t size)
#include <errno.h>
#include <string.h>
#include <stdlib.h>
            //c99��׼֧�ֵı䳤���� - ����ζ�ų��ȿɱ�
            //int n;
            //scanf("%d", &n);
            //int arr2[n];
int main()
{
    int arr[10];   //֮ǰ�����ڴ�������40���ֽڵķ������׶ˣ��޷����ı� 
    int*p = (int*)malloc(40);   //�����ٿռ�ʧ���򷵻�NULL Ҫ��ͷ�ļ� stdlib.h
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1; //����ʧ���򷵻�1
    }
    //���ٳɹ���ʹ���ڴ�
    int i;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    //û��free,������ζ���ڴ�Ͳ�������,�������˳���ʱ��ϵͳ���Զ������ڴ�ռ�,free�ͷŶ�̬���ٵĿռ�
    //free(p);  ��pָ��Ŀռ��ͷţ���p����������ͷţ���p�ĵ�ַû�䣬p�ͻ���Ұָ�룬����һ��ʹ�ú�Ҫ��p���NULL �� p = NULl
    //p = NULL;
    return 0;
}
 
int main()
{
    int* p = (int*)malloc(INT_MAX);   // int���͵������
    if (p == NULL)
    {
        printf("%s", strerror(errno));
        return 1;
    } //����ʧ������
    return 0;
}




                           //calloc - void* calloc (size_t num, size_t size);
              //���ʹ��ǰҪ��ʼ������calloc����֮����malloc
              
//����10�����εĿռ�
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
    } //��ӡ��10��0,˵��calloc�ڿ��ٿռ�֮ǰ������ݳ�ʼ��0
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
    //����
    int* ret = (int*)realloc(p, 80);              //��֮ǰ40���ֽڵĻ�������׷��40���ֽ� �� ����һ�㲻���¿��ٵĿռ����¸���p��Ϊ�������ʧ�ܾͻ᷵��NULL�������ͻ��ԭ�����ٿռ���������ÿգ���������һ�㸳ֵ��һ���±���
    free(ret);
    ret = NULL;
    return 0;

    //realloc(NULL, 40); == malloc(40)
}