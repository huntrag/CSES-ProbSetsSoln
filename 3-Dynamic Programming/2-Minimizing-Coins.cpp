// C++ program to demonstrate the
// ordered set in GNU C++
#include <bits/stdc++.h>
using namespace std;
 
// Header files, namespaces,
// macros as defined above
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// #define index_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAX 1000000
#define MOD 1000000007
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (auto &r : coins)
    {
        cin >> r;
    }
    vector<int> res(sum + 1, -1);
    res[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0 && res[i - coins[j]] != -1)
            {
                if (res[i] != -1)
                {
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
                else
                {
                    res[i] = res[i - coins[j]] + 1;
                }
            }
        }
    }
    cout << res[sum];
    return 0;
}