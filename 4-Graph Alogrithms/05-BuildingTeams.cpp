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
	vector<int> colour;
	vector<bool> vis;
	public:
	Graph(int n){
		this->n=n;
		this->e.resize(n+1);
		this->colour.resize(n+1);
		for(int i=1;i<=n;i++){
			colour[i]=-1;
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
		
		int flag=0;
		
		for(int i=1;i<=n;i++){
			if(vis[i]){
				continue;
			}
			vis[i]=true;
			colour[i]=0;
			q.push(i);
			while(!q.empty()){
				int current=q.front();
				q.pop();
				for(auto &r:e[current]){
					if(!vis[r]){
						vis[r]=true;
						colour[r]=colour[current]^1;
						q.push(r);
					}
					else{
						if(colour[current]==colour[r]){
							flag=1;
							break;
						}
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		if(flag==1){
			cout<<"IMPOSSIBLE\n";
			return;
		}
		for(int i=1;i<=n;i++){
			cout<<colour[i]+1<<" ";
		}
		cout<<'\n';
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