#include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
 
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int test; cin>>test;
    // while(test--){
        int n,x; 
        cin>>n>>x;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<ll,int> m;
        ll sum=0, pre=0;
        m[0]++;
        for(auto &r:a){
            pre+=r;
            sum+=m[pre-x];
            m[pre]++;
        }
        cout<<sum<<"\n";
    // }
    return 0;
}