#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> res;
void subsets(vector<ll> v,ll ans,ll i){
    if(i==v.size()){
        res.push_back(2*ans);
        return ;
    }
    ans=ans+v[i];
    subsets(v,ans,i+1);
    ans=ans-v[i];
    subsets(v,ans,i+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,min=INT32_MAX,sum=0; cin>>n;
    vector<ll> input(n);
    for(ll i=0;i<n;i++){
        cin>>input[i];
        sum+=input[i];
    }
    
    subsets(input,0,0);
    
    for(ll i=0;i<res.size();i++){
        if(sum-res[i]<min && sum-res[i]>=0){
            if(sum-res[i]==0){
                min=0;
                break;
            }
            min=sum-res[i];
        }
    }
    cout<<min;
    return 0;
}