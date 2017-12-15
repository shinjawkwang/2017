#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int arr[5][300300];

int main() {
  int n, people, flag = 1, cnt;
  cin >> n;
  for(int i=0;i<n;i++){
    /* Receive Data */
    cin >> people;
    for(int j=0;j<people;j++){
      cin >> arr[i][j];
    }
    /* Receive Completed */

    /* 내림차순 정렬 */
    sort(arr[i], arr[i] + people, std::greater<int>());
    /* Solution algorithm start */
    cnt = 0;
    flag = 1;
    for(int j=0; j<people; j++){
      for(int k=0; k<j; k++){
        if(arr[i][j]+people < arr[i][k]+k+1){
          flag = 0;
          break;
        }
      }
      if(flag)  cnt ++;
      else      break;
    }

    /* Print */
    cout << "Case #" << i+1 << "\n" << cnt << "\n";
  }
  return 0;
}
