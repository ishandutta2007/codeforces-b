#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005;

//i_am_noob
//#define wiwihorz  

int n,k,a[maxn];

int query1(int x, int y){
    print("or",x+1,y+1);
    cout << flush;
    int res;
    cin >> res;
    return res;
}

int query2(int x, int y){
    print("and",x+1,y+1);
    cout << flush;
    int res;
    cin >> res;
    return res;
}

void orzck(){
    cin >> n >> k;
    vector<int> vec;
    rep(3) rep2(j,i+1,3) vec.pb(query1(i,j));
    rep(3) rep2(j,i+1,3) vec.pb(query2(i,j));
    rep(31){
        int cnt1=0,cnt2=0;
        rep1(j,3) if((vec[j]&pow2(i))==0) cnt1++;
        rep1(j,3) if((vec[3+j]&pow2(i))) cnt2++;
        if(cnt1==3) continue;
        else if(cnt2==3) a[0]^=pow2(i),a[1]^=pow2(i),a[2]^=pow2(i);
        else if(cnt1>=1){
            rep1(j,3) a[j]^=pow2(i);
            if((vec[0]&pow2(i))==0) a[0]^=pow2(i),a[1]^=pow2(i);
            if((vec[1]&pow2(i))==0) a[0]^=pow2(i),a[2]^=pow2(i);
            if((vec[2]&pow2(i))==0) a[1]^=pow2(i),a[2]^=pow2(i);
        }
        else{
            if((vec[3]&pow2(i))) a[0]^=pow2(i),a[1]^=pow2(i);
            if((vec[4]&pow2(i))) a[0]^=pow2(i),a[2]^=pow2(i);
            if((vec[5]&pow2(i))) a[1]^=pow2(i),a[2]^=pow2(i);
        }
    }
    rep2(i,3,n){
        int x=query1(0,i),y=query2(0,i);
        a[i]=a[0];
        rep1(j,31){
            if((a[0]&pow2(j))==0&&(x&pow2(j))) a[i]^=pow2(j);
            if((a[0]&pow2(j))&&(y&pow2(j))==0) a[i]^=pow2(j);
        }
    }
    rep(n) bug(a[i]);
    sort(a,a+n);
    print("finish",a[k-1]);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    //freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}