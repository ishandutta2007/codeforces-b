//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.3 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");


ll n,k,p,x,y,a,sum,l,m;

int Sa1378
{ 
    cin>>n>>k>>p>>x>>y;
    for(int i=0;i<k;i++)
    {
    	cin>>a;
    	sum+=a;
    	if(a<y)
    		l++;
		if(a==y)
			m++;
    }
    
    ll ex=min(n/2-l,n-k);
    if(l>(n/2)|| sum+ex+(n-k-ex)*y>x)
    {
    	cout<<-1;
    	return 0;
    }
    
    for(int i=0;i<n-k-ex;i++)
    	cout<<y<<" ";
    for(int i=0;i<ex;i++)
		cout<<1<<" ";	
    
    return 0;
}