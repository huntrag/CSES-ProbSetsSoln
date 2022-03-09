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
 
bool comp1(const pii &a, const pii &b){
    if(a.first == b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
 
bool comp2(const pii &a, const pii &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // // inputs
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<pii> a(n);
    map<pii,int> m;
    for(int i=0;i<n;i++){
        int x1,x2;
        cin>>x1>>x2;
        a[i]=mp(x1,x2);
        m[mp(x1,x2)]=i;
    }
    sort(a.begin(),a.end(),comp1);
    
    vector<int> contained(n),contains(n);
    contained[m[a[0]]]=0;
    index_multiset ms;
    ms.insert(a[0].second);
    for(int i=1;i<n;i++){
        ms.insert(a[i].second);
        contained[m[a[i]]]=ms.size()-ms.order_of_key(a[i].second)-1;    
    }
    sort(a.begin(),a.end(),comp2);
    
    
    contains[m[a[0]]]=0;
    index_multiset s;
    s.insert(-a[0].second);
    for(int i=1;i<n;i++){
        s.insert(-a[i].second);
        contains[m[a[i]]]=s.size()-s.order_of_key(-a[i].second)-1;    
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    
    return 0;
}