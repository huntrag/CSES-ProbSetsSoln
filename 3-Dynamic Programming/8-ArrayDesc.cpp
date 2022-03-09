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
#define MOD 1000000007
typedef long long ll;
 
 
 
int main()
{
    // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
 
    vector<vector<ll>> dp(n,vector<ll>(m+1,-1));
    for(int i=0;i<n;i++){
        if(a[i]==0){
            for(int j=0;j<=m;j++){
                dp[i][j]=0ll;
            }
        }
        else{
            dp[i][a[i]]=0ll;
        }
    }
    if(a[0]==0){
        for(int i=0;i<=m;i++){
            dp[0][i]=1ll;
        }
    }
    else{
        dp[0][a[0]]=1ll;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]!=-1){
            if(j>=1 && j<=m && dp[i-1][j]!=-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
            if(j-1>=1 && j-1<=m && dp[i-1][j-1]!=-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
            }
            if(j+1>=1 && j+1<=m && dp[i-1][j+1]!=-1){
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
            }}
        }
    }
    ll sum=0ll;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=m;i++){
        if(dp[n-1][i]==-1){
            continue;
        }
        sum=(sum+dp[n-1][i])%MOD;
    }
    cout<<sum;
    
    
    return 0;
}