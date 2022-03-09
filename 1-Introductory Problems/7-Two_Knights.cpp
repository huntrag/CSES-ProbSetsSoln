#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long res;
    int i,n=1; cin>>i;
    for(;n<=i;n++){
        res=(unsigned long long)n*n*(n*n-1)/2-4*(n-1)*(n-2);
        cout<<res<<"\n";
    }
    return 0;
}