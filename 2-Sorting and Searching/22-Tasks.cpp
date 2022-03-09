#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define index_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define index_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vi vector<int>
#define mp make_pair
#define pii pair<ll,ll>
typedef long long ll;
 
bool comp(const pii &a, const pii &b){
    if(a.first ==b.first){
        return a.second<b.second;
    }
    return (a.first)<(b.first);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<pii> a(n);
    for(ll i=0;i<n;i++){
        ll x1,x2;
        cin>>x1>>x2;
        a[i]=mp(x1,x2);
    }
    sort(a.begin(),a.end(),comp);
    // for(ll i=0;i<n;i++){
    //     cout<<a[i].first<<" "<<a[i].second<<"\n";
    // }
    ll time=0;
    ll reward=0;
    for(ll i=0;i<n;i++){
        time+=a[i].first;
        reward+=(a[i].second-time);
        // cout<<time<<" "<<reward<<"\n";
    }
    cout<<reward;
    return 0;
}