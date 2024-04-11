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
#define N (5000*1000+5)
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

int t,a,b,dp[N];
int Sa1378
{ 
    scanf("%d",&t);
    for(int i=2;i<N;i++)
    {
    	if(!dp[i])
    		for(int j=i;j<N;j+=i)
    		{
    			int ex=j;
    			while(ex%i==0)
    			{
    				ex/=i;
    				dp[j]++;
    			}
    		}
    }
    for(int i=2;i<N;i++)
    	dp[i]+=dp[i-1];
	while(t)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",dp[a]-dp[b]);
		t--;
	}		
    return 0;
}