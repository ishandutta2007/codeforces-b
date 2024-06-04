// Willpower alone isn't enough in battle 
// You know that, *
// Defeating ** will require far more..
// ~ Armin Arlert, SnK

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'

int main()
{
    fast_io;
    int n, m;
    cin >> n >> m;
    set<string> pola;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        pola.insert(s);
    }
    int common = 0;
    int ene = 0;
    int pol = 0;
    for(int j=0;j<m;j++) {
        string s;
        cin >> s;
        if(pola.find(s)!=pola.end())
            common++;
        else
            ene++;
    }
    pol = SZ(pola) - common;
    common %= 2;
    string ans = "YES";
    if(common && ene>pol)
        ans = "NO";
    else if(!common && ene>=pol)
        ans = "NO";
    cout << ans << endl;
    return 0;
}