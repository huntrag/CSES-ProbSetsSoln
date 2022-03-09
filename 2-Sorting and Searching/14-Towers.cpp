#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> a(n);
    for(auto &r:a){
        cin>>r;
    }
    //input
 
    multiset<int> s;
    int count=0,num;
    bool cond=false;
    for(int i=0;i<n;i++){
        if(s.lower_bound(a[i]+1)==s.end()){
            count++;
            s.insert(a[i]);
        }
        else{
            s.erase(s.lower_bound(a[i]+1));
            s.insert(a[i]);
        }
        
    }
    cout<<count<<"\n";
    return 0;
} 