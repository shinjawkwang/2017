#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, m, u, v, k, j, result=0;
	vector <int> link_list[1010];
	vector <int> stack;
	int visit[1010], group[1010];
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d%d", &u, &v);
		link_list[u].push_back(v);
		link_list[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		group[i] = i;
		visit[i] = 0;
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			stack.push_back(i);
			visit[i] = 1;
		}
		while(!stack.empty()){
			j=stack.back();
			stack.pop_back();
			for(k=0;k<link_list[j].size();k++){
				if(!visit[link_list[j][k]]){
					stack.push_back(link_list[j][k]);
					visit[link_list[j][k]]=1;
					group[link_list[j][k]]=group[j];
				}
			}
		}
	}
	sort(group+1, group+n+1);
	for(int i=1;i<=n;i++){
		if(group[i] != group[i-1])	result++;
	}
	printf("%d\n", result);
}
