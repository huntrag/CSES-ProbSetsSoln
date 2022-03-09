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
    int n,m,x;
    fast(n); fast(m);
    int mxprice[m];
    set<pair<int,int>> ticket;
    for(int i=0;i<n;i++){
        fast(x);
        ticket.insert({x,i});
    }
    for(int i=0;i<m;i++) fast(mxprice[i]);
    for(int i=0;i<m;i++){
        auto it=ticket.lower_bound({mxprice[i]+1,0});
        if(it==ticket.begin()){
            cout<<"-1\n";
        }
        else{
            it--;
            cout<<(it->first)<<"\n";
            ticket.erase(it);
        }
    }
    return 0;
}