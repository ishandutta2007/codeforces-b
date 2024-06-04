#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=200005;
//i_am_noob
int n,m,l,r,a,b,x,y,ans1,ans2;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> l >> r;
	if(n%2==1&&m%2==1){
		print1(Pow(r-l+1,n*m));
		return 0;
	}
	a=(n*m+1)/2,b=n*m/2,x=(1+r)/2-l/2,y=r/2-(l-1)/2;
	ans1=(sub(Pow(add(x,y),a),Pow(sub(y,x),a))%MOD*inverse(2)%MOD)*(sub(Pow(add(x,y),b),Pow(sub(y,x),b))%MOD*inverse(2)%MOD)%MOD;
	ans2=(add(Pow(add(x,y),a),Pow(sub(y,x),a))%MOD*inverse(2)%MOD)*(add(Pow(add(x,y),b),Pow(sub(y,x),b))%MOD*inverse(2)%MOD)%MOD;
	print1(add(ans1,ans2));
	return 0;
}