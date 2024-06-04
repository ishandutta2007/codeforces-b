#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int MOD=Mod2;
const int maxn=100005;
//i_am_noob
int n,x,pos[maxn][2],dp[maxn][2];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n;
    rep(n) pos[i][0]=pos[i][1]=-1;
    rep(2*n){
        cin >> x;
        x--;
        if(pos[x][0]>=0) pos[x][1]=i;
        else pos[x][0]=i;
    }
    dp[0][0]=dp[0][1]=pos[0][0]+pos[0][1];
    rep2(i,1,n){
        dp[i][0]=min(dp[i-1][0]+abs(pos[i][0]-pos[i-1][0])+abs(pos[i][1]-pos[i-1][1]),dp[i-1][1]+abs(pos[i][0]-pos[i-1][1])+abs(pos[i][1]-pos[i-1][0]));
        dp[i][1]=min(dp[i-1][0]+abs(pos[i][0]-pos[i-1][1])+abs(pos[i][1]-pos[i-1][0]),dp[i-1][1]+abs(pos[i][0]-pos[i-1][0])+abs(pos[i][1]-pos[i-1][1]));
    }
    print(min(dp[n-1][0],dp[n-1][1]));
    return 0;
}