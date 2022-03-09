#include <bits/stdc++.h>
#define vi vector<int>
typedef long long ll; 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test; cin>>test;
	while(test--){
		ll n;
		cin>>n;
		ll index=0;
		ll size=1;
		ll prev=0;
		ll mul=1;
		while(index<n){
			prev=index;
			index+=(ll)(9ll*mul*size);
			size=(ll)size+1ll;
			mul=mul*10ll;
		}
		size--;
		mul=mul/10ll;
		// cout<<mul<<" "<<(n-prev)<<" "<<size;
		ll number=(ll)mul+(n-prev-1)/size;
		ll dex=(ll) (n-prev)%size;
		if(dex==0) dex=size;
		// cout<<dex<<"\n";
		dex=size-dex;
		ll div=1ll;
		while(dex>0){
			div=(ll)div*10;
			dex--;
		}
		// cout<<number<<"\n";
		number=number/div;
		cout<<number%10<<"\n";
 
	}
	return 0;
}