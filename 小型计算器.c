#include <stdio.h>

int main()
{
   float a,b;
   char x;
   printf("请输入你要计算的算式:\n");
   scanf("%f%c%f",&a,&x,&b);
   switch(x)
   {
        case '+':
         printf("结果是:%f\n",a+b);
        break;
        case '-':
         printf("结果是:%f\n",a-b);
        break;
        case '*':
         printf("结果是:%f\n",a*b);
        break;
        case '/':
          if (b == 0) 
        {
            printf("除数不能为0");   
            return 0;
        }
        else printf("结果是:%f\n",a/b);
        break;
        default:
         printf("无法计算!");
   }
   return 0;
}
