#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, n=5, num, cnt=0;
	int *a = malloc(n*sizeof(int));

	while(1){
		printf("Enter numbers until entering a negative number\n");
		scanf("%d", &num);
		if (num<0)	break;
		if(cnt<n){
			a[cnt++] = num;
		}
		/*else{
			while(n<cnt)
				n++;
			a[cnt++] = num;
		}
		*/
		else{
			a = realloc(a, 2*n*sizeof(int));
			n *=2;
		}
	}
	for(int i=0;i<cnt;i++)
		printf("%3d", a[i]);
	free(a);
	printf("\n");
	return 0;
}
