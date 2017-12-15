#include <iostream>

using namespace std;

int arr[5][300300];

int main() {
  int n, people;
  cin >> n;
  for(int i=0;i<n;i++){
    /* Receive Data */
    cin >> people;
    for(int j=0;j<people;j++){
      cin >> arr[i][j];
    }
    /* Receive Completed */

  }
  return 0;
}
