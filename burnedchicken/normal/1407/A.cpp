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
const int MOD=Mod;
const int maxn=1005;
//i_am_noob
int t,n,a[maxn],cnt0,cnt1;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        cnt0=0,cnt1=0;
        rep(n) a[i]?cnt1++:cnt0++;
        if(cnt0>=cnt1){
            print1(n>>1);
            rep(n>>1) print0(0);
            cout << "\n";
        }
        else{
            if(cnt1%2) cnt1--;
            print1(cnt1);
            rep(cnt1) print0(1);
            cout << "\n";
        }
    }
    return 0;
}