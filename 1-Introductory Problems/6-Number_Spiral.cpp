#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case; cin>>test_case;
    while(test_case>0){
        ll row,col; cin>>row>>col;
        ll mx=(ll)max(row,col),mn=(ll)min(row,col);
        if(row%2==0 || col%2!=0){
            if((row%2==0 && row==mx)|| (col%2!=0 && col==mx)){
                cout<<mx*mx-mn+1;
            }
            else{
                cout<<(mx-1)*(mx-1)+mn;
            }
        }
        else{
            cout<<(mx-1)*(mx-1)+mn;
        }
        cout<<"\n";
        test_case--;
    }
    
    return 0;
}