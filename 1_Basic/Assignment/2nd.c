#include <stdio.h>

int main(){
  int n, m, k, condition, result=0;
  printf("Enter the input N, M, K : ");
  scanf("%d%d%d", &n, &m, &k);
  condition = n;
  while(n<=5000000 && m<=5000000 && k<=condition && n>0 && m>0 && k>0){
    result++;
    if(n>=m){
      if(k==m)  break;
      else{
        if(k>m) k-=m;
        else  k=n-(m-k);
      }
    }
    else{
      if(k==m%n)  break;
      else{
        if(k>m%n) k-=m%n;
        else  k=n-(m%n-k);
      }
    }
    n--;
  }
  if(n>5000000 || m>5000000 || k>condition || condition<1 || m<1 || k<1)
    printf("Input Error");
  else
    printf("Result : %d", result);
  return 0;
}
