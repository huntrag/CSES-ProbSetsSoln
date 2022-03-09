#include <bits/stdc++.h>
using namespace std;
 
// Header files, namespaces, macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define index_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
#define MAX 1000000
#define MOD 1000000007
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,k; 
    cin>>n>>k;
    index_set s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    int sum=0;
    while(n){
        sum=(sum+k)%n;
        cout<<*s.find_by_order(sum)<<" ";
        s.erase(s.find_by_order(sum));
        n--;
    }
     
    return 0;
}