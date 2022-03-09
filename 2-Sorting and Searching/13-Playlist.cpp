#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> songs;
    int p1=0,p2=0,mx=1;
    while(p1<n && p2<n){
        while(p2<n && !songs.count(a[p2])){
            songs.insert(a[p2]);
            mx=max(mx,p2-p1+1);
            p2++;
        }
        while(p2<n && songs.count(a[p2])){
            songs.erase(a[p1]);
            p1++;
        }
    }
    cout<<mx;
    return 0;
}