#include<bits/stdc++.h>
using namespace std;
typedef unsigned int it;
bool check_int(double num){
    if(num<0) return false;
    else return ceil(num)==floor(num);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test; cin>>test;
    while(test-- >0){
        double a,b; cin>>a>>b;
        if(check_int((double)(2*a-b)/3) && check_int((double)(2*b-a)/3)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}