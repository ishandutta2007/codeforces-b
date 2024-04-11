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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    int n;
    cin>>n;
    int cur=0;
    while (n--)
    {
        int u;
        string s;
        cin>>u>>s;
        if (s=="West"||s=="East")
            if (cur==0||cur==20000)
                return cout<<"NO", 0;
            else
                continue;
        if (s=="North")
        {
            if (cur<u)
                return cout<<"NO", 0;
            cur-=u;
        }
        else
        {
            if (cur+u>20000)
                return cout<<"NO", 0;
            cur+=u;
        }
    }
    if (cur!=0)
        return cout<<"NO", 0;
    cout<<"YES";
}