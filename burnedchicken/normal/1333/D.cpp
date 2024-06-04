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
 
const int maxn=3005;
//i_am_noob
int n,k,a[maxn],cnt=0;
string str;
vector<vector<int> > vec1;
vector<int> vec,vec2;
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k >> str;
	rep(n) a[i]=str[i]=='L';
	while(1){
		vec.clear();
		rep(n) if(i>0) if(a[i]==1&&a[i-1]==0) vec.pb(i);
		rep(sz(vec)) swap(a[vec[i]],a[vec[i]-1]);
		if(vec.empty()) break;
		vec1.pb(vec);
		cnt++;
	}
	if(cnt>k){
		print1(-1);
		return 0;
	}
	while(1){
		if(vec1.empty()||cnt==k) break;
		vec2.pb(vec1.back().back());
		vec1.back().pop_back();
		cnt++;
		if(vec1.back().empty()){
			vec1.pop_back();
			cnt--;
		}
	}
	if(cnt<k){
		print1(-1);
		return 0;
	}
	reverse(all(vec2));
	rep(sz(vec1)){
		print0(sz(vec1[i]));
		rep1(j,sz(vec1[i])) print0(vec1[i][j]);
		cout << '\n';
	}
	rep(sz(vec2)) print2(1,vec2[i]);
	return 0;
}