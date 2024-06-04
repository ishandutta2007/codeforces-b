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
const int maxn=1000005;
//i_am_noob
int n,k,cnt[22][2],cnt1,cnt2;

template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>
modint ans1(1),ans2,noob(1),fact[maxn],invfact[maxn];
inline modint C(int n, int m){return m<0||m>n?modint(0):fact[n]*invfact[m]*invfact[n-m];}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    fact[0]=1;
    rep2(i,1,maxn) fact[i]=fact[i-1]*modint(i);
    rep(maxn) invfact[i]=fact[i].inv();
    k=63-__builtin_clzll(n);
    cnt[k][0]++;
    rep3(i,k-1,0){
        cnt[i][0]=n/pow2(i);
        rep2(j,i+1,k+1) cnt[i][0]-=cnt[j][0];
    }
    cnt1=n-1;
    rep3(i,k-1,0){
        ans1*=C(cnt1-1,cnt[i][0]-1);
        cnt1-=cnt[i][0];
    }
    rep3(i,k-1,0) ans1*=fact[cnt[i][0]];
    if(n==1||n<pow2(k)/2*3){
        print1(ans1);
        return 0;
    }
    cnt[k-1][1]++;
    rep3(i,k-2,0){
        cnt[i][1]=n/(pow2(i)*3);
        rep2(j,i+1,k) cnt[i][1]-=cnt[j][1];
    }
    rep3(i,k-1,0){
        cnt[i][0]=n/pow2(i)-cnt[i][1];
        rep2(j,i+1,k) cnt[i][0]-=cnt[j][0]+cnt[j][1];
    }
    rep3(i,k-2,-1){
        cnt1=n-1;
        noob=1;
        rep3(j,k-2,i+1){
            noob*=C(cnt1-1,cnt[j][1]-1)*fact[cnt[j][1]];
            cnt1-=cnt[j][1];
        }
        cnt2=0;
        rep3(j,k-1,i+1) cnt2+=cnt[j][0];
        noob*=C(cnt1-1,cnt2-1)*fact[cnt2];
        cnt1-=cnt2;
        rep3(j,i,0){
            noob*=C(cnt1-1,cnt[j][0]+cnt[j][1]-1)*fact[cnt[j][0]+cnt[j][1]];
            cnt1-=cnt[j][0]+cnt[j][1];
        }
        ans2+=noob;
    }
    print1(ans1+ans2);
    return 0;
}