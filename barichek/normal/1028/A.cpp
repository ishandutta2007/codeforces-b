#pragma GCC optimize("O3")
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

    int n,m;
    cin>>n>>m;
    int sum_x=0;
    int cnt_x=0;
    int sum_y=0;
    int cnt_y=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin>>c;
            if (c=='B'){
                sum_x+=i;
                cnt_x++;
                sum_y+=j;
                cnt_y++;
            }
        }
    }
    cout<<sum_x/cnt_x<<" "<<sum_y/cnt_y<<"\n";
}