#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct tick{
    int first;
    int second;
};
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
bool comp(tick a, tick b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second==b.second){
        return (a.first<b.first);
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,count=0,i=0; fast(n);
    vector<tick> a(n);
    for(i=0;i<n;i++){
        fast(a[i].first);
        fast(a[i].second);
    }
    sort(a.begin(),a.end(),comp); 
    i=0;
    int temp;
    while(i<n){
        temp=a[i].second;
        int j=i+1;
        while(a[j].first<temp){
            j++;
        }
        count++;
        i=j;
    }
    cout<<count;
    return 0;
}