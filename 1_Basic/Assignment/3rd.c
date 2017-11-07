#include <stdio.h>

int min(int a, int b) { return a <= b ? a : b; }

int main() {
   int stones, k1, k2, place, max_place, tmp;
   int count = 0, current_place = 0, result = 0, places[110], cnt[110];
   scanf("%d", &stones);
   for (int i = 0; i<110; i++) {
      places[i] = 0;
      cnt[i] = 0;
   }
   for (int i = 0; i<stones; i++) {
      scanf("%d", &place);
      places[place] ++;
      max_place = place;
   }

   scanf("%d%d", &k1, &k2);
   if (k1>k2) {
      tmp = k1;
      k1 = k2;
      k2 = tmp;
   } //k2>k1

   if (k1 == -1) { //basic start
      while (1) {
         for (int i = k2; i>0; i--) {
            if (places[current_place + i] == 1) {
               current_place += i;
               result++;
               if (current_place == max_place)      break;
               i = k2 + 1;
               count = 0;
            }
            else      count++;
            if (count == k2) {
               result = -1;
               break;
            }
         }
         if (current_place == max_place || count == k2)            break;
      }
   } //basic end

   else {//advanced start
      places[0] = 1;
÷      cnt[0] = 0;
      if (places[k1] == 1) cnt[k1] = 1;
      if (places[k2] == 1) cnt[k2] = 1;
      for (int i = 1; i<= max_place; i++) {
         if (cnt[i] != 0) {
            if (cnt[i + k1] == 0) {
               if (places[i + k1] == 1)  cnt[i + k1] = cnt[i] + 1;
            }
            if (cnt[i + k2] == 0) {
               if (places[i + k2] == 1)  cnt[i + k2] = cnt[i] + 1;
            }
         }
      }
      if (cnt[max_place] == 0) result = -1;
      else result = cnt[max_place];
   }//advance end
   printf("%d\n", result);
   return 0;
}
