#include <stdio.h>

int main(){
  int i, j, digits, max_sum, matrix[10000][8], sum, multiply, calc, save; //digits: n, max_sum: x, matrix: array that saves all cases
  scanf("%d%d", &digits, &max_sum);                                       //sum: used when calculating sum of each cases
  multiply = 1;                                                           //multiply: used when calculating numbers of cases
                                                                          //calc, save: used when saving data to matrix; Detailed description in report
  for(i=0;i<digits;i++) multiply *= 3;                                    //calculating numbers of cases

  calc = 1;
  for(i=digits-1;i>=0;i--){
    for(j=0;j<multiply;j++){
      save = j / calc;                                                    //save is quotient when divide j with calc;which is power of 3
      while(save > 2){
        save -= 3;                                                        //we need trinary number, so save has to be 0, 1 or 2
      }
      matrix[j][i] = save;                                                //save data
    }
    calc *= 3;                                                            //next power of 3
  }

  for(i=0;i<multiply;i++){
    sum = 0;
    for(j=0;j<digits;j++)
      sum += matrix[i][j];                                                //calculate sum of each data
    if(sum <= max_sum){
      for(j=0;j<digits;j++)
        printf("%d", matrix[i][j]);
      printf("\n");
    }
  }
  return 0;
}
