#include <stdio.h>

int digits, max_sum;

void DFS(int x, int sum, int *arr) {  // x: digits of each result, sum: sum of each result, arr: array that stores result
  int i;
    if(x == digits){                  //when result is completed
      for(i=0;i<digits;i++)
        printf("%d", arr[i]);
      printf("\n");
      return;
    }
    if(sum + 0 <= max_sum){           //when adding 0 to array is okay
      arr[x] = 0;                     //add 0 to array
      DFS(x+1, sum, arr);             //do same task with 0 added in array
    }
    if(sum + 1 <= max_sum){           //when adding 1 to array is okay
      arr[x] = 1;                     //add 1 to array
      DFS(x+1, sum+1, arr);           //do same task with 1 added in array
    }
    if(sum + 2 <= max_sum){           //when adding 2 to array is okay
      arr[x] = 2;                     //add 2 to array
      DFS(x+1, sum+2, arr);           //do same task with 2 added in array
    }
} // this task is will be continued until the array is full.

int main(){
  int result[8];                      //result array
  scanf("%d%d", &digits, &max_sum);

  DFS(0, 0, result);                  //start recursing!
  return 0;
}
