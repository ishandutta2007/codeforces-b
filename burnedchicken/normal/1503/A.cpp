#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
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
#define wiwihorz  
int n,cnt;
string str,str1,str2;
bool flag;

void hhhhauraorz(){
    cin >> n >> str;
    str1.clear(),str2.clear();
    cnt=0;
    rep(n) cnt+=str[i]=='1';
    flag=0;
    rep(n){
        if(str[i]=='1'){
            if(cnt>0){
                str1+='(';
                str2+='(';
                cnt-=2;
            }
            else{
                str1+=')';
                str2+=')';
            }
        }
        else{
            if(flag){
                str1+=')';
                str2+='(';
            }
            else{
                str1+='(';
                str2+=')';
            }
            flag^=1;
        }
    }
    cnt=0;
    flag=1;
    rep(n){
        cnt+=str1[i]=='('?1:-1;
        if(cnt<0) flag=0;
    }
    if(cnt) flag=0;
    cnt=0;
    rep(n){
        cnt+=str2[i]=='('?1:-1;
        if(cnt<0) flag=0;
    }
    if(cnt) flag=0;
    print(flag?"YES":"NO");
    if(flag) print(str1),print(str2);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}