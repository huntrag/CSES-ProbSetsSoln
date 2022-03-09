#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    int dp[x], coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
            }
        }
    }
    cout << dp[x];
    return 0;
}