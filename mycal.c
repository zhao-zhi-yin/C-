#include <stdio.h>
#include <string.h>
int main()
{
    const char *temp = "mycal";
    char temp_1[20];
    while (1)
    {
        gets(temp_1);
        if (strstr(temp_1, temp) != NULL)
        {
            int j = strspn(temp_1, temp);
            int m = 0, n = 0;
            char t_ = 1;
            if (temp_1[j] == ' ')
            {
                j++;
                char le = 0;
                char *p = &temp_1[j];
                while (*p != '\0')
                {
                    if (*p > 47 && *p < 58)
                    {
                        if (t_)
                            m = m * 10 + (*p - 48);
                        else
                        {
                            n = n * 10 + (*p - 48);
                        }
                    }
                    else if (*p == '+')
                    {
                        le = 1;
                        t_ = 0;
                    }
                    else if (*p == '-')
                    {
                        le = 2;
                        t_ = 0;
                    }
                    else if (*p == '*')
                    {
                        le = 3;
                        t_ = 0;
                    }
                    else if (*p == '/')
                    {
                        le = 4;
                        t_ = 0;
                    }
                    p++;
                }
                switch (le)
                {
                case 1:
                    printf("%d\n", m + n);
                    break;
                case 2:
                    printf("%d\n", m - n);
                    break;
                case 3:
                    printf("%d\n", m * n);
                    break;
                case 4:
                    printf("%d\n", m / n);
                    break;
                default:
                    printf("error\n");
                    break;
                }
            }
        }else if (temp_1[0] == 'Y')
            break;

    }
    printf("END!\n");
    return 0;
}
