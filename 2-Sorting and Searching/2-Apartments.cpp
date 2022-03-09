#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fastscan(int &number){
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
    int n,m,k;
    fastscan(n);
    fastscan(m);
    fastscan(k);
    vector<int> a(n),b(m);
    for(auto &x:a) fastscan(x);
    for(auto &x:b) fastscan(x);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0,count=0;
    while(i<n){
        while(j<m && b[j]<a[i]-k) j++;
        if(abs(a[i]-b[j])<=k){
            count++;
            i++;
            j++;
        }
        else i++;
    }
    cout<<count;
    return 0;
}