#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,n;
	cin >> t;
	string str;
	bool ok;
	while(t--){
		cin >> n >> str;
		ok=false;
		if(n<11){
			cout << "NO\n";
			continue;
		}
		rep(n-10) if(str[i]=='8') ok=true;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}