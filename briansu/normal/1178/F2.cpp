//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=5e2+5, MAXm = 1e6 + 6, MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

ll dp[MAXn][MAXn], dt[MAXn];

ll cal(ll l, ll r)
{
    if(r < l)return 1;
    if(dp[l][r] != -1)return dp[l][r];
    ll t = min_element(dt + l, dt + r + 1) - dt;
    ll lt = 0, rt = 0;
    for(int i = l;i <= t;i ++)lt = (lt + cal(l, i - 1) * cal(i, t - 1)) % MOD;
    for(int i = t;i <= r;i ++)rt = (rt + cal(i + 1, r) * cal(t + 1, i)) % MOD;
    return dp[l][r] = lt * rt % MOD;
}

ll d[MAXm];
vector<ll> v[MAXn];

ll go(ll l,ll r,ll out)
{
    if(r < l)return 1;
    vector<ll> tmp;
    ll now = l, ret = 1;
    while(now <= r)
    {
        ll t = d[now];
        debug(t, v[t], l, r);
        if(t < out || now != v[t][0] || v[t].back() > r)return 0;
        REP(i, SZ(v[t]) - 1)
        {
            ret = ret * go(v[t][i] + 1, v[t][i + 1] - 1, t) % MOD;
        }
        tmp.pb(t);
        now = v[t].back() + 1;
    }
    REP(i, SZ(tmp))dt[i + 1] = tmp[i];  
    REP1(i, SZ(tmp))REP1(j, SZ(tmp))dp[i][j] = -1;
    ret = ret * cal(1, SZ(tmp)) % MOD;
    return ret;
}

int main()
{
    IOS();
    FILL(dp, -1);
    ll n, m;
    cin>>n>>m;
    REP1(i, m)cin>>d[i];
    REP1(i, m)v[d[i]].pb(i);
    

    cout<<go(1, m, -1)<<endl;
    
}