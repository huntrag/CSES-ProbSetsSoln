#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    while(true){
        cout<<n<<" ";
        if(n==1) break;
        else{
            if(n%2==0) n/=2;
            else n=(ll)n*3+1;}
    }
    return 0;
}