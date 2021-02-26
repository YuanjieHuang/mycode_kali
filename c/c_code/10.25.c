#include <stdio.h>
#include <string.h>                            /*����string.hͷ�ļ���*/
void main()
{
   char *p;                                 /*����1��ָ���ַ���ָ�롣*/
   char a[20]="asdfg";                        /*����һ���ַ������Ҹ���ֵ��*/
   char b[20]="hjklm" ;
   printf("%s\n",a);                        /*���ԭ�����ַ�����*/
   printf("%s\n",b);
   p=strcat(a,b);                            /*���ַ���b���ӵ��ַ���a���档*/
   printf("%s\n",a);                        /*��������Ժ���ַ�����*/
   printf("%s\n",b);
   printf("%s\n",p);                        /*���ָ��pָ����ַ�����*/
}

