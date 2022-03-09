#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s; 
    int count=0,mxi=0,i=0;
    char p=s[0];
    while(s[i]!='\0'){
        if(p==s[i]){
            count++;
            mxi=max(mxi,count);
        }
        else count=1;
        p=s[i];
        i++;
    }
    printf("%d ",mxi);
    return 0;
}