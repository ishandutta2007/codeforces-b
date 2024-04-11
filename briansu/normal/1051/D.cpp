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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

ll dp[MAXn][MAXn][2][2];

void add(ll &a,ll b)
{
  a += b;
  if(a >= MOD)a-=MOD;
}

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    dp[1][1][0][0] = 1;
    dp[1][2][0][1] = 1;
    dp[1][2][1][0] = 1;
    dp[1][1][1][1] = 1;
    for(int i = 2;i <= n;i++)for(int j = 1;j <= k;j++)REP(p,2)REP(q,2)
    {
      if(p == q)
      {
        add(dp[i][j][p][q],dp[i-1][j][p][q]);
        add(dp[i][j][p][q],dp[i-1][j][!p][q]);
        add(dp[i][j][p][q],dp[i-1][j][p][!q]);
        add(dp[i][j][p][q],dp[i-1][j - 1][!p][!q]);
      }
      else {
        add(dp[i][j][p][q],dp[i-1][j][p][q]);
        add(dp[i][j][p][q],dp[i-1][j-1][!p][q]);
        add(dp[i][j][p][q],dp[i-1][j-1][p][!q]);
        if(j>=2)add(dp[i][j][p][q],dp[i-1][j - 2][!p][!q]);
      }
    }
    ll tt = 0;
    REP(p,2)REP(q,2)add(tt,dp[n][k][p][q]);
    cout<<tt<<endl;
}