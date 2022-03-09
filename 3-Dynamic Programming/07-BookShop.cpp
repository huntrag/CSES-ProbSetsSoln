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
	int n, x;
	cin >> n >> x;
	int price[n];
	int page[n];
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> page[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			dp[i + 1][j] = dp[i][j];
			if (price[i] <= j)
			{
				dp[i + 1][j] = max(dp[i + 1][j], page[i] + dp[i][j - price[i]]);
			}
		}
	}
	cout << dp[n][x];
	return 0;
}