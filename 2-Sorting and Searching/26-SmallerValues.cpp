#include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
 
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // cout<<a<<"\n";
    vector<int> pos(n);
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            // cout<<i<<"r ";
            s.pop();
        }
        if(s.empty()){
            pos[i]=0;
        }
        else{
            pos[i]=s.top()+1;
        }
        s.push(i);
    }
    cout<<pos;
    return 0;
}