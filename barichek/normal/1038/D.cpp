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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    if (n==1){
        int a;
        cin>>a;
        cout<<a<<"\n";
    }
    else{
        int m=1e18;
        int ans=0;
        bool is1=0;
        bool is2=0;
        while (n--){
            int a;
            cin>>a;
            is1|=(a<=0);
            is2|=(a>=0);
            ans+=abs(a);
            m=min(m,abs(a));
        }
        if (is1&&is2){
            cout<<ans<<"\n";
        }
        else{
            cout<<ans-2*m<<"\n";
        }
    }
}