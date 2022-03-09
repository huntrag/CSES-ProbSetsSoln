#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
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
    int n,start,end,count=0,mx=-1; fast(n);
    map<int,int> events;
    for(int i=0;i<n;i++){
        fast(start); fast(end);
        events[start]=1;
        events[end]=-1;
    }
    for(auto &x: events){
        count+=x.second;
        mx=max(mx,count);
    }
    cout<<mx;
}