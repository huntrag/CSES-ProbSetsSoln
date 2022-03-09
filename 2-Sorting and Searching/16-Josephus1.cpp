#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 0; i < n; i++)
    {
        a[i + 1] = i + 1;
    }
    int streak = 0;
    int pivot = 1;
    do
    {
        //killer
 
        streak = 0;
        while (a[pivot] == -1 && streak < n - 1)
        {
            pivot++;
            if (pivot == n + 1)
            {
                pivot = 1;
            }
            streak++;
        }
 
        if (streak == n - 1 && streak != 0 && streak != 1 && streak != 2)
        {
            break;
        }
        streak = 0;
        //killed
        pivot++;
        if (pivot == n + 1)
        {
            pivot = 1;
        }
        while (a[pivot] == -1 && streak < n - 1)
        {
            pivot++;
            if (pivot == n + 1)
            {
                pivot = 1;
            }
            streak++;
        }
        cout << a[pivot] << " ";
        a[pivot] = -1;
    } while (streak < n - 1);
    return 0;
}