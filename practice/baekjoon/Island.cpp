#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int width, height, map[55][55], visit[55][55], flag = 1, cnt = 0;
int pos_x, pos_y;


void countIsland(int count, int x, int y){
  visit[x][y] = 1;
  if(map[x][y]){
    pos_x = x, pos_y = y;
    if(!visit[x+1][y] && map[x+1][y] && x<width)                 countIsland(count+1, x+1, y);
    if(!visit[x+1][y+1] && map[x+1][y+1] && x<width &&y<height)  countIsland(count+1, x+1, y+1);
    if(!visit[x+1][y-1] && map[x+1][y] && x<width && y>0)        countIsland(count+1, x+1, y-1);
    if(!visit[x][y+1] && map[x][y+1] &&x<height)                 countIsland(count+1, x, y+1);
    if(!visit[x][y-1] && map[x][y-1] && y>0)                     countIsland(count+1, x, y-1);
    if(!visit[x-1][y] && map[x-1][y] && x>0)                     countIsland(count+1, x-1, y);
    if(!visit[x-1][y+1] && map[x-1][y+1] && x>0 && y<height)     countIsland(count+1, x-1, y+1);
    if(!visit[x-1][y-1] && map[x-1][y-1] && x>0 && y>0)          countIsland(count+1, x-1, y-1);
  }
  else{
    if(pos_x<width-1)       countIsland(count, pos_x+1, y);
    else if(pos_y<height)   countIsland(count, 0, pos_y+1);
    else                {cnt += count; return;}
  }
  /*
  if(!visit[x+1][y] && map[x+1][y])                     countIsland(count+1, x+1, y);
  if(!visit[x+1][y+1] && map[x+1][y+1])                 countIsland(count+1, x+1, y+1);
  if(!visit[x+1][y-1] && map[x+1][y] && y>0)            countIsland(count+1, x+1, y-1);
  if(!visit[x][y+1] && map[x][y+1])                     countIsland(count+1, x, y+1);
  if(!visit[x][y-1] && map[x][y-1] && y>0)              countIsland(count+1, x, y-1);
  if(!visit[x-1][y] && map[x-1][y] && x>0)              countIsland(count+1, x-1, y);
  if(!visit[x-1][y+1] && map[x-1][y+1] && x>0)          countIsland(count+1, x-1, y+1);
  if(!visit[x-1][y-1] && map[x-1][y-1] && x>0 && y>0)   countIsland(count+1, x-1, y-1);
  */
}

int main(){
  int i,j;
  while(1){
    scanf("%d%d", &width, &height);
    if(!width || !height) break;
    for(i=0;i<height;i++){
      for(j=0;j<width;j++){
        scanf("%d", &map[i][j]);
      }
    }
    countIsland(0, 0, 0);
    printf("<---Result--->\n%d\n", cnt);
    cnt = 0;
  }
  return 0;
}
