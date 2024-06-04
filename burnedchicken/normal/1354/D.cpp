#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
//#define int long long
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
#define eps 1e-9
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
const int MOD=Mod;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=1000005;
//i_am_noob
int n,q,x,y,num;

struct BIT{
	int val[pow2(20)+1];
	void modify(int x, int y){for(int i=x; i<pow2(20)+1; i+=i&-i) val[i]+=y;}
	int query(int x, int y){
		int ret=0;
		for(int i=y; i>0; i-=i&-i) ret+=val[i];
		for(int i=x-1; i>0; i-=i&-i) ret-=val[i];
		return ret;
	}
}b;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> q;
	memset(b.val,0,sizeof(b.val));
	rep(n){
		cin >> x;
		b.modify(x,1);
	}
	while(q--){
		cin >> x;
		if(x>0) b.modify(x,1);
		else{
			x=-x;
			y=0,num=0;
			rep3(i,19,0){
				num+=b.val[y+pow2(i)];
				if(x>num) y+=pow2(i);
				else num-=b.val[y+pow2(i)];
			}
			y++;
			b.modify(y,-1);
		}
	}
	rep2(i,1,n+1) if(b.query(i,i)>0){
		print1(i);
		return 0;
	}
	print1(0);
	return 0;
}