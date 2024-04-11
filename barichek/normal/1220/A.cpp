//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    cin>>s;
    map<char,int> cnt;
    for (auto i:s){
        cnt[i]++;
    }
    while (cnt['o']&&cnt['n']&&cnt['e']){
        cout<<1<<" ";
        cnt['o']--;
        cnt['n']--;
        cnt['e']--;
    }
    while (cnt['z']&&cnt['e']&&cnt['r']&&cnt['o']){
        cout<<0<<" ";
        cnt['z']--;
        cnt['e']--;
        cnt['r']--;
        cnt['o']--;
    }
}