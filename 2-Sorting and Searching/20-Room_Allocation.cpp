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
 
struct comp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        
        return a.first>b.first;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<tuple<int,int,int>> a(n);
    for(int i=0;i<n;i++){
        int x1,x2;
        cin>>x1>>x2;
        a[i]=make_tuple(x1,x2,i);
    }
    vector<int> rooms(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> p;
    sort(a.begin(),a.end());
    int count=0;
    for(int i=0;i<n;i++){
        
        if(!p.empty()){
            int arrival=get<0>(a[i]);
            pii lowest_dep=p.top();
            if(lowest_dep.first<arrival){
                p.pop();
                p.push(mp(get<1>(a[i]),lowest_dep.second));
                rooms[get<2>(a[i])]=lowest_dep.second;
                continue;
            }
        }
        count++;
        p.push(mp(get<1>(a[i]),count));
        rooms[get<2>(a[i])]=count;
    }
    cout<<*max_element(rooms.begin(),rooms.end())<<"\n";
    for(int i=0;i<n;i++){
        cout<<rooms[i]<<" ";
    }
    return 0;
}