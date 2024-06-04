#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005;
//i_am_noob
int t,n,a[maxn],cnt[maxn],cnt2[maxn],tot,ans;
bool flag;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        rep(n) a[i]--;
        rep(n) cnt[i]=0;
        rep(n) cnt[a[i]]++;
        flag=false;
        rep(n) if(cnt[i]>(n+1)/2) flag=true;
        if(flag){
            print(-1);
            continue;
        }
        rep(n) cnt2[i]=0;
        cnt2[a[0]]++,cnt2[a[n-1]]++;
        ans=0;
        rep(n-1) if(a[i]==a[i+1]) cnt2[a[i]]+=2,ans++;
        cnt2[n]=2;
        tot=0;
        rep(n+1) tot+=cnt2[i];
        rep(n+1) if(cnt2[i]>tot/2) ans+=(cnt2[i]-(tot-cnt2[i]))/2;
        print(ans);
    }
    return 0;
}