#include <stdio.h>

int main()
{
    int a, b;
    char cal;
    scanf("%d %c %d", &a, &cal, &b);
    if(cal == '+')
        printf("%d\n", a+b);
    else if(cal == '-')
        printf("%d\n", a-b);
    else if(cal == '*')
        printf("%d\n", a*b);
    else if(cal == '/')
        printf("%d\n", a/b);
    else if(cal == '%')
        printf("%d\n", a%b);
    else
        printf("입력이 잘못되었습니다.\n");
    return 0;
}
