#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define INF 1000000007
typedef long long ll;
typedef long double ld;
 
class Graph{
	public:
	int n;
	vector<vector<int>> e;
	vector<vector<int>> comp;
	vector<bool> vis;
	public:
	Graph(int n){
		this->n=n;
		this->e.resize(n+1);
		this->vis.resize(n+1);
		vis[0]=true;
	}
 
	void add(int u,int v){
		e[v].push_back(u);
		e[u].push_back(v);
	}
 
	void ans(){
		int count=0;
		for(int i=1;i<=n;i++){
			vector<int> all;
			if(!vis[i]){
				dfs(i,all);
				comp.push_back(all);
				count++;
			}
		}
		cout<<count-1<<"\n";
		for(int i=0;i<comp.size()-1;i++){
			cout<<comp[i][0]<<" "<<comp[i+1][0]<<"\n";
		}
	}
 
	void dfs(int v,vector<int> &all){
		if(vis[v]){
			return;
		}
		vis[v]=true;
		all.push_back(v);
		for(auto &r:e[v]){
			dfs(r,all);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin>>n;
	Graph g(n);
	int m; cin>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		g.add(u,v);
	}
	g.ans();
	return 0;
}