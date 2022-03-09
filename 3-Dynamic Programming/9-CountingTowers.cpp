#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
    int test; cin>>test;
    ll n=1000001;
    vector<vector<ll>> dp(n+1, vector<ll> (9,0ll));
    dp[1][1]=1ll;
    dp[1][5]=1ll;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=8;j++){
            if(j==1 || j==3 ||j==4 ||j==7 || j==8){
                dp[i][j]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][7]+dp[i-1][8])%MOD;
            }
            else{
                dp[i][j]=(dp[i-1][3]+dp[i-1][5]+dp[i-1][6])%MOD;
            }
        }
    }  
    while(test--){
        ll n; cin>>n;
        
        ll sum=0ll;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=8;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(ll i=1;i<=8;i++){
            sum=(sum+dp[n][i])%MOD;
        }
        cout<<sum<<"\n";
    }
    
    return 0;
}