#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    ll a[n-1],s=(ll)n*(n+1)/2,c=0ll;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        c+=a[i];
    }
    cout<<s-c;
    return 0;
}