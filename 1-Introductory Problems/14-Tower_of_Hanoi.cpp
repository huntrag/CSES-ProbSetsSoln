#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Hanoi(int n,int from, int final, int intermediate){
    if(n==1){
        cout<<from<<" "<<final<<"\n";
        return;
    }
    Hanoi(n-1,from,intermediate,final);
    cout<<from<<" "<<final<<"\n";
    Hanoi(n-1,intermediate,final,from);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    cout<<(1<<(n))-1<<"\n";
    Hanoi(n,1,3,2);
    return 0;
}