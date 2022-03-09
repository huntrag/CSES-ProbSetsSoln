#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> generate(int n){
    if(n==1){
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        return v;
    }    
    vector<string> res(1<<n);
    vector<string> samp=generate(n-1);
    int i=0,j=0;
    for(i=0;i<(1<<n-1);i++){
            res[i]="0"+samp[i];
        }
        reverse(samp.begin(),samp.end());
        for(;i<(1<<n);i++){
            res[i]="1"+samp[j];
            j++;
        }
        return res;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<string> ans=generate(n);
    for(string x:ans){
        cout<<x<<"\n";
    }
    return 0;
}