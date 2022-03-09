#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define index_set tree<ll, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define index_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vi vector<int>
#define mp make_pair
#define pii pair<int,int>
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
 
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
 
struct util{
    int sum;
    int f;
    int s;
};
 
bool comp(util a, util b){
    return a.sum<b.sum;
}
 
int main()
{
     // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum; cin>>n>>sum;
    vi a(n);
    cin>>a;
    int size=n*(n-1)/2;
    vector<util> x(size);
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            x[k].sum=a[i]+a[j];
            x[k].f=i;
            x[k].s=j;
            k++;
        }
    }
    sort(x.begin(),x.end(),comp);
    int i=0,j=size-1;
 
    while(i<size && j>=0){
        if(x[i].sum+x[j].sum==sum && 
        x[i].f!=x[j].f && 
        x[i].s!=x[j].s && 
        x[i].f!=x[j].s && 
        x[i].s!=x[j].f){
            cout<<x[i].f+1<<" "<<x[i].s+1<<" "<<x[j].f+1<<" "<<x[j].s+1;
            return 0;
        }
        else if(x[i].sum+x[j].sum<sum ){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}