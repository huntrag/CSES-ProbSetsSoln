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
 
ll total(vector<ll> &a,ll time,ll t){
    ll sum=0;
    for(ll i=0;i<(ll)a.size();i++){
        sum+=time/a[i];
        
    }   
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    ll mx_time=t*(a[0]);
    ll mn_time=0;
    ll mid;
    do{
        mid=(mn_time)+ceil((long double)(mx_time-mn_time)/2);
        ll products=total(a,mid,t);
        // cout<<mn_time<<" "<<mx_time<<" "<<products<<"\n";
        if(products>=t){
            mx_time=mid;
        }
        else{
            mn_time=mid;
        }
    }while(mn_time<mx_time-1);
 
    cout<<mx_time;
    
    return 0;
}