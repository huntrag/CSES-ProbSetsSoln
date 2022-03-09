#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;
typedef long double ld;
 
class Graph{
	public:
		int N;
		int M;
		vector<vector<bool>> grid;
		vector<vector<bool>> visit;
		vector<vector<pair<int,int>>> prev;
		vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
 
	Graph(int N, int M){
		this->N=N;
		this->M=M;
		grid.resize(N);
		visit.resize(N);
		prev.resize(N);
		for(int i=0;i<N;i++){
			grid[i].resize(M);
			visit[i].resize(M);
			prev[i].resize(M);
		}	
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				prev[i][j].first=-1;
				prev[i][j].second=-1;
			}
		}	
	}
 
	void add(char c, int i, int j){
		if(c=='#'){
			grid[i][j]=true;
		}
		else{
			grid[i][j]=false;
		}
	}
 
	void bfs(int si, int sj, int ei, int ej){
		queue<pair<int,int>> q;
		int flag=0;
		q.push(make_pair(si,sj));
		grid[si][sj]=true;
		while(!q.empty()){
			pair<int,int> current=q.front();
			q.pop();		
			if(current.first==ei && current.second==ej){
				flag=1;
				break;
			}
			for(auto &r:dir){
				int i=current.first+r.first;
				int j=current.second+r.second;
				if(i<0 || i>N-1 || j<0 || j>M-1 || grid[i][j]){
					continue;
				}
				grid[i][j]=true;
				q.push(make_pair(i,j));
				prev[i][j]=make_pair(current.first,current.second);
			}
		}
		if(flag==0){
			cout<<"NO\n";
			return;
		}
		cout<<"YES\n";
		pair<int,int> path,start;
		path=make_pair(ei,ej);
		start=make_pair(si,sj);
		stack<char> s;
		for(;path!=start;path=prev[path.first][path.second]){
			pair<int,int> move=make_pair(
				path.first-prev[path.first][path.second].first,
				path.second-prev[path.first][path.second].second
			);
			if(move==make_pair(1,0)){
				s.push('D');
			}else if(move==make_pair(-1,0)) {
				s.push('U');
			}
			else if(move==make_pair(0,1)){
				s.push('R');
			}
			else{
				s.push('L');
			}
		}
		cout<<s.size()<<"\n";
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,si,sj,ei,ej;
	cin>>n>>m;
	Graph g(n,m);
	vector<vector<char>> a(n,vector<char> (m));
	vector<string> v(n);
	for(int i=0;i<n;i++){
		getline(cin>>ws,v[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c=v[i][j];
			g.add(c,i,j);
			if(c=='A'){
				si=i; sj=j;
			}
			if(c=='B'){
				ei=i; ej=j;
			}
		}
	}
	g.bfs(si,sj,ei,ej);
	return 0;
}