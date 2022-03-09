#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll mx=-1e9-1,sum;
    sum=mx;
    for(int i=0;i<n;i++){
        sum=max(sum+a[i],a[i]);
        mx=max(mx,sum);
    }
    cout<<mx;
    return 0;
}