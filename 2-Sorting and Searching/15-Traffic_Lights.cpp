#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n1, test;
    cin >> n1 >> test;
    set<int> s;
    multiset<int> m;
    s.insert(0);
    s.insert(n1);
    m.insert(n1);
 
    while (test--)
    {
        int n;
        cin >> n;
        s.insert(n);
        auto iter = s.find(n);
        int previous = *prev(iter);
        int nextv = *next(iter);
        m.erase(m.find(nextv - previous));
        m.insert(nextv - n);
        m.insert(n - previous);
        cout << *m.rbegin() << " ";
    }
 
    return 0;
}