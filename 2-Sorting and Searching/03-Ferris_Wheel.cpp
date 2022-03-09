#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fscan(int &number){
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
    //inputs
    int n,x,count=0,flags=0,sum=0;
    fscan(n);fscan(x);
    vector<int> p(n);
    for(auto &t:p) fscan(t);
    // sort
    sort(p.begin(),p.end());
    //next step
    int f=0,l=0,i,j;
    for(i=n-1;i>=0;i--){
        sum=p[i]; flags=0;
        for(j=f;j<n-l && sum<=x && flags<2;j++){
            sum+=p[j];
            flags++;
        }
        if(flags>0){
            f+=flags-1; 
            count++;
        }
        l++;
    }  
    cout<<count;
    return 0;
}