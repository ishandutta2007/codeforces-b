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
const int maxn=105;
//i_am_noob
int t,n,a[maxn],b[maxn],c[maxn];
vector<int> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        rep(n) cin >> b[i];
        rep(n) cin >> c[i];
        vec.clear();
        vec.pb(a[0]);
        rep2(i,1,n-1){
            if(a[i]==vec.back()) vec.pb(b[i]);
            else vec.pb(a[i]);
        }
        if(a[n-1]!=vec.back()&&a[n-1]!=vec[0]) vec.pb(a[n-1]);
        else if(b[n-1]!=vec.back()&&b[n-1]!=vec[0]) vec.pb(b[n-1]);
        else vec.pb(c[n-1]);
        rep(n) print0(vec[i]);
        cout << "\n";
    }
    return 0;
}