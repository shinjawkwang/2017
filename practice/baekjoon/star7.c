#include <stdio.h>

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=n-i;j>0;j--)
            printf(" ");
        for(k=0;k<2*i-1;k++)
            printf("*");
        printf("\n");
    }
    for(i=1;i<n;i++){
        for(j=1;j<=i;j++)
            printf(" ");
        for(k=0;k<2*(n-i)-1;k++)
            printf("*");
        printf("\n");
    }
    return 0;
}
