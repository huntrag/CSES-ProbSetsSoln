#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define index_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define index_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vi vector<int>
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
 
class Graph{
    private:
        ll V;
        vector<vector<ll>> e;
        map<pair<ll,ll>, ll> m;
 
    public:
        Graph(ll V);    
 
        void addEdge(ll u, ll v, ll cap);
 
        void updateEdge(ll u,ll v,ll added);
 
        bool isAugPath(ll src, ll sink, vector<ll> &parent);
 
        ll maxFlow(ll src,ll sink);
};
Graph :: Graph(ll V){
    this->V=V;
    this->e=vector<vector<ll>> (V);
}    
 
void Graph ::addEdge(ll u, ll v, ll cap){
    e[u].push_back(v);
    e[v].push_back(u);
    
    m[mp(u,v)]=m[mp(u,v)]+cap;
    m[mp(v,u)]=m[mp(v,u)]+0; // Back Edge
}
 
void Graph ::updateEdge(ll u,ll v,ll added){ 
    m[mp(u,v)]-=added;
    m[mp(v,u)]+=added; // Back Edge
}
 
bool Graph ::isAugPath(ll src, ll sink, vector<ll> &parent){
    queue<ll> q;
    q.push(src);
    vector<bool> vis(V,false);
    vis[src]=true;
    parent[src]=-1;
 
    while(!q.empty()){
        ll u=q.front();
        q.pop();
 
        for(auto &v:e[u]){
            if(!vis[v] && m[mp(u,v)]>0){                       
                vis[v]=true;
                parent[v]=u;
                if(v==sink){
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}
 
ll Graph ::maxFlow(ll src,ll sink){
    ll mxFlow=0;
    vector<ll> parent(V,-1);
    while(isAugPath(src,sink,parent)){
        ll added=LLONG_MAX;
        for(ll i=sink;i!=src;i=parent[i]){
            added=min(added,m[mp(parent[i],i)]);
        }
 
        for(ll i=sink;i!=src;i=parent[i]){
            updateEdge(parent[i],i,added);
        }
        
        mxFlow+=added;
    }
    return mxFlow;
}
 
int main()
{
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll v,e;
    cin>>v>>e;
    Graph g(v+1);
    while(e--){
        ll x,y,c;
        cin>>x>>y>>c;
        g.addEdge(x,y,c);
    }
    cout<<g.maxFlow(1,v);
    return 0;
}