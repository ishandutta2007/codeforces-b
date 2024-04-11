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
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
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
        ll a,n;cin>>a>>n;
        vi v(a);rep(i,a)cin>>v[i];
        rsort(v);
        while(v.size()!=n)v.pop_back();
        reverse(all(v));
        vvi g(n);
        vi sum(n),cnt(n);
        vp srt(n);
        rep(i,n){
            cin>>cnt[i];
            rep(j,cnt[i]){
                ll c;cin>>c;g[i].pb(c);
                sum[i]+=c;
            }
        }
        rep(i,n)srt[i]=P((sum[i]+cnt[i]-1)/cnt[i],i);
        sort(all(srt));
        vi id(n);rep(i,n)id[srt[i].se]=i;
        bool ok=true;
        rep(i,n)if(v[i]<srt[i].fi)ok=false;
        string ans;
        if(ok){
            vi d;
            d.pb(0);
            rep(i,n-1)if(v[i]<srt[i+1].fi)d.pb(i+1);
            d.pb(n);
            rep(i,n)for(ll x:g[i]){
                ll t=(sum[i]-x+cnt[i]-2)/(cnt[i]-1);
                if(t<=(sum[i]+cnt[i]-1)/cnt[i])ans+='1';
                else{
                    ll l=lb(srt,P(t,-1));
                    ll r=lb(d,id[i]+1);
                    if(d[r]>=l&&v[l-1]>=t)ans+='1';
                    else ans+='0';
                }
            }
        }
        else{
            bool ok=true;
            vi d;
            rep(i,n-1)if(v[i+1]<srt[i].fi)ok=false;
            rep(i,n)if(v[i]<srt[i].fi)d.pb(i);
            rep(i,n)for(ll x:g[i]){
                ll t=(sum[i]-x+cnt[i]-2)/(cnt[i]-1);
                if(!ok||t>=(sum[i]+cnt[i]-1)/cnt[i])ans+='0';
                else{
                    ll l=lb(srt,P(t,-1));
                    if(l<=d[0]&&d.back()<=id[i]&&v[l]>=t)ans+='1';
                    else ans+='0';
                }
            }
        }
        out(ans);
    }
}