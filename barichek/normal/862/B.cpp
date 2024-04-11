#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

int cnt1;
int cnt2;
vi reb[arr];

void dfs(int now,int pred=-1,int deep=0)
{
    if (deep){
        cnt1++;
    }
    else{
        cnt2++;
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now,deep^1);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1);
    cout<<cnt1*cnt2-(n-1)<<"\n";
}