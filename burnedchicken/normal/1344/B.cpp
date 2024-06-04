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
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=1005;
//i_am_noob
int n,m,x,y,a[maxn]={0},ans=0,unused1=0,unused2=0;
char c[maxn][maxn];
bool flag;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	rep(n) rep1(j,m) cin >> c[i][j];
	rep(n){
		x=y=-1;
		rep1(j,m-1) if(c[i][j]=='#'&&c[i][j+1]=='.'){
			x=j;
			break;
		}
		rep3(j,m-1,1) if(c[i][j]=='#'&&c[i][j-1]=='.'){
			y=j;
			break;
		}
		if(x!=-1&&y!=-1&&x<y){
			print1(-1);
			return 0;
		}
		rep1(j,m-1) if(c[i][j]=='#'&&c[i][j+1]=='#') a[j]=1;
	}
	rep(m){
		x=y=-1;
		rep1(j,n-1) if(c[j][i]=='#'&&c[j+1][i]=='.'){
			x=j;
			break;
		}
		rep3(j,n-1,1) if(c[j][i]=='#'&&c[j-1][i]=='.'){
			y=j;
			break;
		}
		if(x!=-1&&y!=-1&&x<y){
			print1(-1);
			return 0;
		}
	}
	rep(n){
		flag=true;
		rep1(j,m) if(c[i][j]=='#') flag=false;
		if(flag) unused1++;
	}
	rep(m){
		flag=true;
		rep1(j,n) if(c[j][i]=='#') flag=false;
		if(flag) unused2++;
	}
	if((unused1!=0||unused2!=0)&&(unused1==0||unused2==0)){
		print1(-1);
		return 0;
	}
	rep(m) if(a[i]) ans++;
	print1(m-unused2-ans);
	return 0;
}