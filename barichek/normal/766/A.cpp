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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

/// sydoran is our lord
/// melnyk is our krevedka
/// oryshych is our kaban
/// mitsa is our batya
/// kek is our cheburek
/// oros is our down
/// goban is our huyoban
/// pechora is our maksim
/// arsijo is our tasher
/// filip is our petuh
/// vetal is our vseukr

main()
{
    string a,b;
    cin>>a>>b;
    cout<<(a==b?-1ll:ll(max(a.length(),b.length())));
}