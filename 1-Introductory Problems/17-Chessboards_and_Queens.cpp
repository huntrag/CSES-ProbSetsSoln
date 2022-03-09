#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool col[8]={0},d1[16]={0},d2[16]={0};
int coun=0;
void search(int y, char arr[8][8]){
    if(y==8){
        coun++;
        return;
    }
    for(int x=0;x<8;x++){
        if(arr[y][x]=='.'){if(col[x] || d1[x+y] || d2[x-y+7]) continue;
        col[x]=d1[x+y]=d2[x-y+7]=1;
        search(y+1,arr);
        col[x]=d1[x+y]=d2[x-y+7]=0;}
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char arr[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>arr[i][j];
        }
    }
    search(0,arr);
    cout<<coun;
    return 0;
}