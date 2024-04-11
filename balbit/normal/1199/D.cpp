#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 2e5+5;

pii trs[maxn];

int mxp[maxn]; // maximum payoff at and after this point

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n){
        int x; cin>>x;
        trs[i] = {-1,x};
    }
    int q; cin>>q;
    REP(i,q){
        int T; cin>>T;
        if (T==1){
            int a, x; cin>>a>>x; a--;
            trs[a]={i,x};
        }else{
            int p; cin>>p;
            mxp[i]=p;
        }
    }
    RREP(i,q){
        MXTO(mxp[i],mxp[i+1]);
    }
    REP(i,n){
        MXTO(trs[i].s, mxp[trs[i].f+1]);
        cout<<trs[i].s<<' ';
    }
    
}