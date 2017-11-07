#include <stdio.h>
#include <algorithm>
using namespace std;

int n, arr[100010], m;
int main(){
	int i, x, left, right, mid;
	scanf("%d", &n);
	for(i=1;i<=n;++i)	scanf("%d", &arr[i]);
	sort(&arr[1], &arr[n+1]);
	
	scanf("%d", &m);
	for(i=1;i<=m;i++){
		scanf("%d", &x);
		left = 1; right = n;
		while(left<=right){
			mid = (left+right)/2;
			if(arr[mid] == x)
				break;
			else if(arr[mid] > x)
				right = mid-1;
			else
				left = mid+1;
		}
		if(right<left)	printf("0\n");
		else	printf("1\n");
	}
}
