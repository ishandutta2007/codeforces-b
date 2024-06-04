#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int MOD=Mod;
const int maxn=500005;
//i_am_noob
int n,a[maxn],cnt=0,cur,nxt[maxn],b[maxn];
vector<int> vec;
deque<int> dq[3];
vector<pii> ans;
bool flag;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) if(a[i]) vec.pb(i);
    reverse(all(vec));
    rep(n) nxt[i]=-1;
    for(auto i: vec){
        if(a[i]==2){
            if(dq[0].empty()){
                print1(-1);
                return 0;
            }
            nxt[i]=dq[0].back();
            dq[0].pop_back();
        }
        if(a[i]==3){
            if(dq[0].empty()&&dq[1].empty()&&dq[2].empty()){
                print1(-1);
                return 0;
            }
            rep3(j,2,0) if(!dq[j].empty()){
                nxt[i]=dq[j].back();
                dq[j].pop_back();
                break;
            }
        }
        dq[a[i]-1].push_front(i);
    }
    cur=n-1;
    for(auto i: vec){
        if(a[i]==3) ans.pb({cur,i}),ans.pb({cur,nxt[i]}),cur--;
        else if(a[i]==2) ans.pb({b[nxt[i]],i});
        else ans.pb({cur,i}),b[i]=cur,cur--;
    }
    print1(sz(ans));
    for(auto [x,y]: ans) print2(x+1,y+1);
    return 0;
}