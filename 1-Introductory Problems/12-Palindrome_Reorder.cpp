#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int letters[26]={0};
    int n=s.length();
    for(int i=0;i<n;i++){
        letters[(int)(s[i]-'A')]++;
    }
    int flag=0,t=0; char c;
    for(int i=0;i<26;i++){
        if(letters[i]%2!=0){
            flag++;
            c=(char)((int)'A'+i);
            letters[i]/=2;
            if(flag==2) break;
        }
        else{
            letters[i]/=2;
        }
    }
    if(flag==2){
        cout<<"NO SOLUTION\n";
    }
    else{
        char res[n];
        for(int i=0;i<26;i++){
            while(letters[i]>0){
                res[t]=(char)((int)'A'+i);
                res[n-t-1]=res[t];
                letters[i]--;
                t++;
            }
        }
        if(flag==1) res[n/2]=c;
        for(int i=0;i<n;i++){
            cout<<res[i];
        }
    }

}