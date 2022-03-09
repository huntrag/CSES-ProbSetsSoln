#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int sum=0;
    while(n>0){
        sum+=n/5;
        n/=5;
    }
    cout<<sum;
    return 0;
}