#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define index_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define index_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vi vector<int>
#define mp make_pair
#define pii pair<ll,ll>
#define MOD 1000000007
typedef long long ll;
 
 
 
int main()
{
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sum;
    cin>>n>>sum;
    vector<pii> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    if(n<3){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int p=sum-a[i].first;
        for(int j=i+1,k=n-1;j<k;j++){
            while(a[j].first+a[k].first>p){
                k--;
            }
            if(j<k && a[j].first+a[k].first==p){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
        
    
    return 0;
}