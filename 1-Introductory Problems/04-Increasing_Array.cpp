#include <bits/stdc++.h>
using namespace std;
//constants
const int M = 32;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
//Shortcuts
#define ll long long
#define pc(x) putchar(x)
#define sz(x) (ll) x.size()
#define pb push_back
#define setBits __builtin_popcount
#define LCM(a, b) (a * b != 0 ? a * b / __gcd(a, b) : 0)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define revStr(str) string(str.rbegin(), str.rend())
#define repChar(ch, n) string(n, (int)ch)
#define clr(arr) memset(arr, 0, sizeof(arr));
#define F0(i, n) for (ll i = 0; i < n; i++)
#define F1(i, n) for (ll i = 1; i <= n; i++)
#define IC(i, container) for (auto i : container)
//fast I/O
long gn();
string gs();
inline void wi(long long n);
inline void ws(string s);
//Data Stucture
typedef array<int, 2> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vpi> graph;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mpi;
typedef multimap<int, int> mpsi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vi, greater<int>> min_heap;
/********************Fast Input-output*********************/
long gn()
{
    bool negative = false;
    int chr = getchar();
    if (chr == '-')
        negative = true, chr = getchar();
    long a = chr - '0';
    while (true)
    {
        chr = getchar();
        if (chr < '0')
            return negative ? -1 * a : a;
        a = (a << 3) + (a << 1) + chr - '0';
    }
}
string gs()
{
    string str;
    int chr = getchar();
    str += (char)chr;
    while (true)
    {
        chr = getchar();
        if (chr < 33)
            return str;
        str += (char)chr;
    }
}
inline void wi(ll n)
{
    if (n < 0)
    {
        pc('-');
        n *= -1;
    }
    ll N = n, rev, count = 0;
    rev = N;
    if (N == 0)
    {
        pc('0');
        return;
    }
    while ((rev % 10) == 0)
    {
        count++;
        rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0)
    {
        rev = (rev << 3) + (rev << 1) + N % 10;
        N /= 10;
    } //store reverse of N in rev
    while (rev != 0)
    {
        pc(rev % 10 + '0');
        rev /= 10;
    }
    while (count--)
        pc('0');
}
/*****************************Basic Number Theory*******************/
//Fast modular Exponentiation
ll exp(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            (res *= x) %= MOD;
        }
 
        (x *= x) %= MOD;
        y >>= 1;
    }
    return res;
}
 
void solve()
{
    int t = 1;
    // t = gn();
    while (t--)
    {
        ll n = gn(),ct = 0;
        ll prev = gn();
        F1(i,n-1){
            ll curr = gn();
            if(curr < prev)
                ct+=(prev-curr);
            else
                prev = curr;
        }
        wi(ct);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    solve();
    return 0;
}