#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

main()
{
    set<char> setik={'A','E','O','U','Y','I'};
    vi ansik={-1};
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++)
        if (setik.count(s[i]))
            ansik.pb(i);
    ansik.pb(s.length());
    int ans=0;
    for (int i=1;i<ansik.size();i++)
        ans=max(ans,ansik[i]-ansik[i-1]);
    cout<<ans;
}