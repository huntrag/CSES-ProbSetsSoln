#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test_input.txt","r",stdin);
    string s1,s2;
    getline(cin>>ws,s1);
    getline(cin>>ws,s2);
 
    int n=s1.length();
    int m=s2.length();
 
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
 
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    s1=" "+s1;
    s2=" "+s2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int mn=min(dp[i-1][j-1],dp[i-1][j]);
                mn=min(mn,dp[i][j-1]);
                dp[i][j]=mn+1;
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][m];
    return 0;
}