#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
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
 
const ll Mod=1000000007,Mod2=998244353;
int t,n,m,k,a[3505],b[3505],ans,tmp;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		rep(n) cin >> a[i];
		rep(m) b[i]=max(a[i],a[i+n-m]);
		if(k>=m-1){
			ans=-1;
			rep(m) ans=max(ans,b[i]);
			cout << ans << '\n';
		}
		else{
			ans=-1;
			rep(k+1){
				tmp=2e9;
				rep1(j,m-k){
					tmp=min(tmp,b[i+j]);
				}
				ans=max(ans,tmp);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}