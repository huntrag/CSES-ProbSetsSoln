#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x; cin>>n>>x;
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        int val; cin>>val;
        if(m.count(x-val)){
            cout<<i+1<<" "<<m[x-val];
            return 0;
        }
        m[val]=i+1;
    }    
    cout<<"IMPOSSIBLE";
    return 0;
}