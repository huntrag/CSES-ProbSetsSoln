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
	vector<int> prev;
	vector<bool> vis;
	public:
	Graph(int n){
		this->n=n;
		this->e.resize(n+1);
		this->prev.resize(n+1);
		for(int i=1;i<=n;i++){
			prev[i]=-1;
		}
		this->vis.resize(n+1);
		vis[0]=true;
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
	}
 
	void add(int u,int v){
		e[v].push_back(u);
		e[u].push_back(v);
	}
 
	void bfs(){
		queue<int> q;
		q.push(1);
		int flag=0;
		vis[1]=true;
		while(!q.empty()){
			int current=q.front();
			q.pop();
			if(current==n){
				flag=1;
				break;
			}
			for(auto &r:e[current]){
				if(!vis[r]){
					vis[r]=true;
					q.push(r);
					prev[r]=current;
				}
			}
		}
		if(flag==0){
			cout<<"IMPOSSIBLE\n";
			return;
		}
		stack<int> path;
		for(int i=n;i>=1;i=prev[i]){
			path.push(i);
		}
		cout<<path.size()<<"\n";
		while(!path.empty()){
			cout<<path.top()<<" ";
			path.pop();
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
	g.bfs();
	return 0;
}