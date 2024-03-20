#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>value(N);
vector<vector<int>>graph(N);
vector<int>dp_selected(N),dp_notselected(N);

int findans(int curnode,int parent){

	for(auto a:graph[curnode]){
		if(a!=parent){
			findans(a,curnode);
		}
	}

	int curnode_selected=0,curnode_notselected=0;

	for(auto a:graph[curnode]){
		if(a!=parent){
			curnode_selected+=dp_notselected[a];
			curnode_notselected+=max(dp_notselected[a],dp_selected[a]);
		}
	}

	dp_selected[curnode]=value[curnode]+curnode_selected;
    dp_notselected[curnode] = curnode_notselected;
}

int main(){
	
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>value[i];
	}

	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	findans(1,0);
	cout<<max(dp_selected[1],dp_notselected[1]);
}