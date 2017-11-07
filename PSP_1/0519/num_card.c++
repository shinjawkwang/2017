#include <stdio.h>
#include <algorithm>
using namespace std;

int n, arr[500010];
int main(){
	int left, right, mid, x, m;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)	scanf("%d", &arr[i]);
	sort(&arr[1], &arr[n+1]);
	//start binary Search
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d", &x);
		left = 1; right = n;
		while(left<=right){
			mid = (left+right)/2;
			if(arr[mid] == x)	break;
			else if(arr[mid] > x)	right = mid-1;
			else	left = mid+1;
		}
		if(left<=right)	printf("1\n");
		else	printf("0\n");
	}
	return 0;
}
