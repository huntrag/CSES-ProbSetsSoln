#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    if(n==2 || n==3) cout<<"NO SOLUTION";
    else{
        int small=1,t=n/2,big=t+1;
        for(int i=1;i<=t;i++){
            cout<<big<<" "<<small<<" ";
            big++; small++;
        }
        if(n%2!=0) cout<<n;
    }
    return 0;
}