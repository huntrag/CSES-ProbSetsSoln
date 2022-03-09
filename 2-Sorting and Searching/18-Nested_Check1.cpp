#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
 
bool comp1(const pii &a, const pii &b){
    if(a.first == b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
 
bool comp2(const pii &a, const pii &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // // inputs
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<pii> a(n);
    map<pii,int> m;
    for(int i=0;i<n;i++){
        int x1,x2;
        cin>>x1>>x2;
        a[i]=mp(x1,x2);
        m[mp(x1,x2)]=i;
    }
    sort(a.begin(),a.end(),comp1);
    
    vector<bool> contained(n),contains(n);
    contained[m[a[0]]]=false;
    int mx=a[0].second;
    for(int i=1;i<n;i++){
        if(a[i].second>mx){
            contained[m[a[i]]]=false;
            mx=a[i].second;
        }
        else{
            contained[m[a[i]]]=true;
        }
    }
    sort(a.begin(),a.end(),comp2);
    
    
    contains[m[a[0]]]=false;
    int mn=a[0].second;
    for(int i=1;i<n;i++){
        if(a[i].second<mn){
            contains[m[a[i]]]=false;
            mn=a[i].second;
        }
        else{
            contains[m[a[i]]]=true;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    
    return 0;
}