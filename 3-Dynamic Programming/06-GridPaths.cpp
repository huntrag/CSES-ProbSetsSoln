#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
 
ll extract(int n, int digit)
{
    digit = pow(10, digit - 1);
    n = n / digit;
    return (n % 10);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                a[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n && !a[i][0]; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n && !a[0][i]; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j])
            {
                continue;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}