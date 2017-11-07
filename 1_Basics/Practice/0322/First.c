#include <stdio.h>

int main()
{
    int num1, num2, sum;

    printf("정수 두 개를 입력하세요 : ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    float avg = (float)sum/2;
    printf("두 수의 합은 %d입니다. \n", sum);
    printf("두 수의 합은 %.2f입니다. \n", avg);
    return 0;
}
