#include <stdio.h>
#include <vector>
using namespace std;

int n,m,cnt=0;
vector<int> list[32323];
int in[32323], pos[32323], ans[32323];
int heap[32323];

void swap(int a, int b){
	heap[a]^=heap[b]^=heap[a]^=heap[b];
	pos[heap[a]]^=pos[heap[b]]^=pos[heap[a]]^=pos[heap[b]];
}
void printh(){
	int i;
	for(i=1;i<=n;i++)	printf("%d ",heap[i]);
	printf("\n");
}
void insert(int item, int cur){
	if(item>0){
		heap[cur]=item;
		pos[item]=cur;
	}
	while(cur>1){
		if(in[heap[cur]]<in[heap[cur/2]]){
			swap(cur,cur/2);
			cur/=2;
		}
		else	break;
	}
}
void heapify(int pos){
	int cur=pos;
	while(cur<=cnt/2){
		if(in[heap[2*cur]]>in[heap[2*cur+1]] && 2*cur+1<=cnt){
			if(in[heap[2*cur+1]]<in[heap[cur]]){
				swap(2*cur+1,cur);
				cur*=2;
				cur++;
			}
			else	break;
		}
		else{
			if(in[heap[2*cur]]<in[heap[cur]]){
				swap(2*cur,cur);
				cur*=2;
			}
			else	break;
		}
	}
}

int main(){
	int i,j,a,b,pop;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		list[a].push_back(b);
		in[b]++;
	}
	for(i=1;i<=n;i++){
		insert(i,i);
	}
	cnt=n;
	for(i=0;i<n;i++){
		pop=ans[i]=heap[1];
		swap(1,cnt);
		cnt--;
		heapify(1);
		for(j=0;j<list[pop].size();j++){
			in[list[pop][j]]--;
			insert(-1, pos[list[pop][j]]);
		}
	}
	for(i=0;i<n;i++)	printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
