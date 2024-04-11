#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=1000000007;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<mi> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]*mi(i);
    vector<mi> finv(n+1,1); finv[n]=inv(f[n]);
    for(int i=n;i>=1;i--) finv[i-1]=finv[i]*mi(i);
    auto C=[&](int a,int b)->mi
    {
        if(a<b) return 0;
        return (f[a]*finv[b]*finv[a-b]);
    };
    vector<int> sz(n+1,0);
    vector<mi> opt(n+1,0);
    mi now=0;
    mi res=0;
    function<void(int,int)> dfs=[&](int a,int p)
    {
        sz[a]=1;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            sz[a]+=sz[to];
            opt[a]-=C(sz[to],k);
        }
        opt[a]+=C(sz[a],k);
        now+=(opt[a]*mi(sz[a]));
    };
    dfs(1,0);
    auto reroot=[&](int a,int b) //b is the new root
    {
        now-=(opt[a]*mi(sz[a]));
        opt[a]+=C(sz[b],k);
        opt[a]-=C(sz[a],k);
        sz[a]-=sz[b];
        opt[a]+=C(sz[a],k);
        now+=(opt[a]*mi(sz[a]));
        now-=(opt[b]*mi(sz[b]));
        opt[b]-=C(sz[b],k);
        sz[b]+=sz[a];
        opt[b]+=C(sz[b],k);
        opt[b]-=C(sz[a],k);
        now+=(opt[b]*mi(sz[b]));
    };
    function<void(int,int)> go=[&](int a,int p)
    {
        res+=now;
        for(int to:v[a])
        {
            if(to==p) continue;
            reroot(a,to);
            go(to,a);
            reroot(to,a);
        }
    };
    go(1,0);
    cout << res << "\n";
    return 0;
}