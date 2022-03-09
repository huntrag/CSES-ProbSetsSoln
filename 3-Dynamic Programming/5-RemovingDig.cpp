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
    ll n;
    cin >> n;
    ll dp[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll no = log10(i) + 1;
        for (ll j = 1; j <= no; j++)
        {
            dp[i] = min(dp[i], dp[i - extract(i, j)] + 1);
        }
    }
    cout << dp[n];
    return 0;
}