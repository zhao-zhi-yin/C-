#include <stdio.h>

int main()
{
   float a,b;
   char x;
   printf("��������Ҫ�������ʽ:\n");
   scanf("%f%c%f",&a,&x,&b);
   switch(x)
   {
        case '+':
         printf("�����:%f\n",a+b);
        break;
        case '-':
         printf("�����:%f\n",a-b);
        break;
        case '*':
         printf("�����:%f\n",a*b);
        break;
        case '/':
          if (b == 0) 
        {
            printf("��������Ϊ0");   
            return 0;
        }
        else printf("�����:%f\n",a/b);
        break;
        default:
         printf("�޷�����!");
   }
   return 0;
}
