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
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=300005;
//i_am_noob
int n,q,a[maxn],m=0,o,x,k,l,r,ans;

struct BIT{
	int val[maxn];
	void modify(int x, int y){for(int i=x; i<maxn; i+=i&-i) val[i]+=y;}
	int query(int x, int y){
		int ret=0;
		for(int i=y; i>0; i-=i&-i) ret+=val[i];
		for(int i=x-1; i>0; i-=i&-i) ret-=val[i];
		return ret;
	}
}bit;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    rep(pow2(n)) cin >> a[i];
    rep(pow2(n)) bit.modify(i+1,a[i]);
    while(q--){
        cin >> o;
        if(o==1){
            cin >> x >> k;
            x--;
            bit.modify((x^m)+1,k-a[x^m]);
            a[x^m]=k;
        }
        else if(o==2){
            cin >> k;
            m^=pow2(k)-1;
        }
        else if(o==3){
            cin >> k;
            m^=pow2(k);
        }
        else{
            cin >> l >> r;
            l--,ans=0;
            rep(19){
                if(l%pow2(i+1)){
                    x=((l^m)>>i)<<i;
                    ans+=bit.query(x+1,x+pow2(i));
                    l+=pow2(i);
                }
                if(r%pow2(i+1)){
                    x=(((r-pow2(i))^m)>>i)<<i;
                    ans+=bit.query(x+1,x+pow2(i));
                    r-=pow2(i);
                }
                if(l==r) break;
            }
            print1(ans);
        }
    }
    return 0;
}