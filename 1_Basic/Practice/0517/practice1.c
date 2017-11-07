#include <stdio.h>

void swap(char* array){
  int save;
  char first[10], second[10], *result;
  for(int i=0;*(array+i)!=' ';i++){
    first[i] = array[i];
    save = i;
  }
  for(int i=save+2;i<10;i++){
    second[i-save-2] = array[i];
  }
  for(int i=0;i<10-save-2;i++)
    array[i] = second[i];
  for(int i=save+4;i<10;i++){
    if(i==save+4)
      array[i] = ' ';
    else
      array[i] = first[i-save-5];
  }
}

int main(){
  char word[10] = {'C', 'A', 'T', ' ', 'R', 'A', 'B', 'B', 'I', 'T'};
  for(int i=0;i<10;i++)
    printf("%c", word[i]);
  printf("\n");
  swap(word);
  for(int i=0;i<10;i++)
    printf("%c", word[i]);
  printf("\n");
  return 0;
}
