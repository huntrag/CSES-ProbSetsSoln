#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    ll index[n],x,count=1;
    for(int i=1;i<=n;i++){
        cin>>x;
        index[x]=i;
    }
    ll prev=index[1];
    for(int i=2;i<=n;i++){
        if(index[i]<prev){
            count++;
        }
        prev=index[i];
    }
    cout<<count;
    return 0;
}