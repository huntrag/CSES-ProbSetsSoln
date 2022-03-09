#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0; cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-a[n/2]);
    }
    cout<<ans;
    return 0;
}