#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void generate(string s){
    int i=0,n=s.size();
    vector<string> x;
    do{
        x.push_back(s);
        i++;
    }while(next_permutation(s.begin(),s.end()));
    cout<<i<<"\n";
    for(int j=0;j<i;j++){
        cout<<x[j]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string v;
    cin>>v;

    sort(v.begin(),v.end());
    generate(v);
    return 0;
}