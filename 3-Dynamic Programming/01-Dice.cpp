#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
static ll cnt=0;
void fast(int &number){
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
  	c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative) number *= -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vector<ll> combinations(n+1,0);
    combinations[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                combinations[i]=(combinations[i]+combinations[i-j])%mod;
            }
        }
    }
    cout<<combinations[n];
}