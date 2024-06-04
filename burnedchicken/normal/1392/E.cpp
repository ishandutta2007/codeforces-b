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
const int maxn=200005;
//i_am_noob
int n,a[25][25],minn[25][25],maxx[25][25],q,k,x,y;
vector<pii> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) a[0][i]=0,minn[0][i]=0,maxx[0][i]=0;
    rep2(i,1,n){
        rep3(j,n-1,0){
            if(j==n-1){
                a[i][j]=0;
                continue;
            }
            a[i][j]=maxx[i-1][j+1]-minn[i-1][j]+1;
        }
        rep1(j,n){
            if(j==0) minn[i][j]=maxx[i][j]=minn[i-1][j]+a[i][j];
            else minn[i][j]=minn[i-1][j]+a[i][j],maxx[i][j]=maxx[i][j-1]+a[i][j];
        }
    }
    rep(n){
        rep1(j,n) print0(a[i][j]);
        cout << "\n";
    }
    cout << flush;
    cin >> q;
    while(q--){
        cin >> k;
        vec.clear();
        x=n-1,y=n-1;
        rep(2*n-2){
            vec.pb({x,y});
            if(y==0) x--;
            else if(minn[x][y-1]<=k){
                k-=a[x][y-1];
                y--;
            }else{
                k-=a[x-1][y];
                x--;
            }
        }
        vec.pb({x,y});
        reverse(all(vec));
        rep(2*n-1) print2(vec[i].first+1,vec[i].second+1);
        cout << flush;
    }
    return 0;
}