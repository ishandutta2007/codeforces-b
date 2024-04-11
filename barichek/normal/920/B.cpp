#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vi in[arr];
vi out[arr];
int kek[arr];
int ans[arr];

void solve()
{
    for (int i=1;i<=5000;i++){
        in[i].clear();
        out[i].clear();
    }
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        ans[i]=0;
    }
    for (int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        in[l].pb(i);
        out[r+1].pb(i);
    }
    set<pii> q;
    q.clear();
    int last=0;
    for (int i=1;i<=5000;i++){
        for (auto j:in[i]){
            q.insert(mp(kek[j]=(last++),j));
        }
        for (auto j:out[i]){
            q.erase(mp(kek[j],j));
        }
        if (!q.empty()){
            auto kek=*q.begin();
            q.erase(q.begin());
            ans[kek.sec]=i;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}