#include<bits/stdc++.h>
using namespace std;
long M=1e9+7;
long long total(int n, int x){
    if(n==0) return 1;
    else{
        long long sum=0;
        if(x==0 || x==3){
            sum=(sum+total(n-1,1))%M;
            sum=(sum+total(n-1,2))%M;
            sum=(sum+total(n-1,3))%M;
            sum=(sum+total(n-1,4))%M;
        }
        else if(x==1){
            sum=(sum+total(n-1,2))%M;
            sum=(sum+total(n-1,4))%M;
        }
        else if(x==2){
            sum=(sum+total(n-1,3))%M;
            sum=(sum+total(n-1,4))%M;
        }
        else if(x==4){
            sum=(sum+total(n-1,2))%M;
            sum=(sum+total(n-1,1))%M;
        }
        return sum;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test; cin>>test;
    while(test-->0){int n; cin>>n;
    cout<<total(n,0)<<"\n";}
    return 0;
}