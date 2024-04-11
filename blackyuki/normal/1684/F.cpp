#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define pb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define popcnt __builtin_popcountll
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
const ll mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll t;cin>>t;
    rep(tt,t){
        ll n,m;cin>>n>>m;
        vi v(n);
        rep(i,n)cin>>v[i];
        vvi gl(n),gr(n);
        rep(i,m){
            ll l,r;cin>>l>>r;l--;r--;
            gl[l].pb(r);gr[r].pb(l);
        }
        vi srt=v;dupli(srt);
        rep(i,n)v[i]=lb(srt,v[i]);
        ll L=inf,R=-inf;
        {
            vi lst(n,-1);
            ll ma=-1;
            rep(i,n){
                chmax(ma,lst[v[i]]);lst[v[i]]=i;
                for(ll x:gr[i])if(x<=ma)chmax(R,ma);
            }
        }
        {
            vi lst(n,inf);
            ll mi=inf;
            for(int i=n-1;i>=0;i--){
                chmin(mi,lst[v[i]]);lst[v[i]]=i;
                for(ll x:gl[i])if(x>=mi)chmin(L,mi);
            }
        }
        vvi al(n);
        rep(i,n)al[v[i]].pb(i);
        if(R==-inf)out(0);
        else{
            ll ans=R+1,ma=-1,cur=R;
            rep(i,L){
                for(ll x:gl[i])chmax(ma,x);
                ll t=lb(al[v[i]],ma+1)-1;
                if(t>=0&&al[v[i]][t]>=i+1)chmax(cur,al[v[i]][t]);
                chmin(ans,cur-i);
            }
            out(ans);
        }
    }
}