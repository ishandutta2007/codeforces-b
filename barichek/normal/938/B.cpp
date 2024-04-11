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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n;
    cin>>n;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    int ans=1e9;
    for (int i=0;i<len(a);i++){
        int cur1=0;
        int cur2=0;
        cur1=a[i]-1;
        if (i!=len(a)-1){
            cur2=1000000-a[i+1];
        }
        ans=min(ans,max(cur1,cur2));
    }
    ans=min(ans,1000000-a[0]);
    cout<<ans<<"\n";
}