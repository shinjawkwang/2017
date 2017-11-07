#include <stdio.h>

int main(){
    printf("Enter the input size : ");
    int n, sequence = 0, sum = 0, max = 0, result;
    int input1, input2, input3, save1 = 0, save2 = 0;
    scanf("%d", &n);
    while(sequence<n && n>=3){
        if(sequence == 0){
            input1 = 0;
            scanf("%d", &input2);
            if(input2<-10000 || input2>10000)
              break;
            scanf("%d", &input3);
            if(input3<-10000 || input3>10000)
              break;
            }
        else if(sequence != n-1){
            scanf("%d", &input3);
            if(input3<-10000 || input3>10000)
                break;
            }
        else
          input3 = 0;
        if(sequence != 0){
            input1 = save1;
            input2 = save2;
        }
        sum = input1 + input2 + input3;
        if(max <= sum){
            max = sum;
            result = input2;
        }
        sequence ++;
        save1 = input2;
        save2 = input3;
    }
    if(n<3 || ((input1<-10000 || input1>10000) || (input2<-10000 || input2>10000) || (input3<-10000 || input3>10000)))
        printf("Input Error \n");
    else
        printf("Result : %d \n", result);
    return 0;
}
