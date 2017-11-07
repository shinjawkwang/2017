#include <stdio.h>

int main()
{
    int num, div = 1, divisors = 0;
    printf("input a integer : ");
    scanf("%d", &num);
    while(1)
    {
        if(num % div == 0)
            divisors++;
        div ++;
        if(div == num + 1)
            break;
    }
    if(num % divisors == 0)
        printf("This number is a repeated division number. \n");
    else
        printf("This number is not a repeated division number. \n");
    return 0;
}
