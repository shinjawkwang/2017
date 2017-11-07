#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int i, j, n, sv;
  scanf("%d", &n);
  sv = n;
  for(i=1;i<=n;i++){
    for(j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }

  cout << endl;

  for(i=0;i<n;i++) {
    for(j=0;j<i;j++){
      printf(" ");
    }
    printf("*\n");
  }

  cout << endl;

  if(n % 2 == 1){
    if(n==1) printf("*");
    for(i=0;i<n/2;i++){
      for(j=0;j<i;j++) printf(" ");
      printf("*");
      for(j=sv-2;j>0;j--){
        printf(" ");
      }
      printf("*\n");
      if (i!=n/2-1)
        sv -= 2;
    }
    for(i=0;i<n-1;i++){
      if(i == n/2) printf("*");
      else         printf(" ");
    }
    printf("\n");
    for(i=n/2;i>0;i--){
      for(j=i-1;j>0;j--) printf(" ");
      printf("*");
      for(j=0;j<sv-2;j++){
        printf(" ");
      }
      printf("*\n");
      sv += 2;
    }
  }
  else {
    for(i=0;i<n/2;i++){
      for(j=0;j<i;j++) printf(" ");
      printf("*");
      for(j=sv-2;j>0;j--){
        printf(" ");
      }
      printf("*\n");
      if (i!=n/2-1)
        sv -= 2;
    }
    for(i=n/2;i>0;i--){
      for(j=i-1;j>0;j--) printf(" ");
      printf("*");
      for(j=0;j<sv-2;j++){
        printf(" ");
      }
      printf("*\n");
      sv += 2;
    }
  }
  return 0;
}
