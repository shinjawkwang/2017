#include <stdio.h>

int main(){
  int n, i, j, a[55], b[55], c[55], tmp, max, min, pos, sum = 0;
  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);
  for(i=0;i<n;i++)
    scanf("%d", &b[i]);
  for(i=0;i<n;i++){
    min = a[i];
    pos = i;
    for(j=i;j<n;j++){
      if(min>a[j]){
        min = a[j];
        pos = j;
      }
    }
    tmp = a[i];
    a[i] = min;
    a[pos] = tmp;
  }
  for(i=0;i<n;i++){
    max = b[i];
    pos = i;
    for(j=i;j<n;j++){
      if(max<b[j]){
          max = b[j];
          pos = j;
        }
    }
    tmp = b[i];
    b[i] = max;
    b[pos] = tmp;
  }
  for(i=0;i<n;i++)
    sum += a[i] * b[i];
  printf("%d", sum);
  return 0;
}
