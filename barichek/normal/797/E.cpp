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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

using namespace std;
///#define int long long

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

const int sz=200;

int n;
int a[arr];
int ans[arr][sz];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<sz;j++){
            ans[i][j]=i+a[i]+j>n?1:ans[i+a[i]+j][j]+1;
        }
    }
    int q;
    cin>>q;
    while (q--){
        int p,k;
        cin>>p>>k;
        if (k>=sz){
            int ans=0;
            while (p<=n){
                p+=a[p]+k;
                ans++;
            }
            cout<<ans<<"\n";
        }
        else{
            cout<<ans[p][k]<<"\n";
        }
    }
}