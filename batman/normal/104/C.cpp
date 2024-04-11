//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.6 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI 3.1415926535897932384626433832795028841971
#define INF 1e9
#define MOD 1e9+7
#define HASH 1e16+7
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,m;
vector <ll> e[N];

bool check_loop()
{
	ll loops=0;
	bool mark[N]={};
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			queue <ll> q;
	
			q.push(i);
			mark[i]=1;
			while(!q.empty())
			{
				ll ex=q.front();
				q.pop();
				for(int i=0;i<e[ex].size();i++)
				{
					if(mark[e[ex][i]])
						loops++;
					else
					{
						mark[e[ex][i]]=1;
						q.push(e[ex][i]);
					}
				}
				loops--;
			}
		}
	//cerr<<loops<<endl;
	if(loops==1)
		return 1;
	return 0;	
}

int Sa1378
{ 
	IB
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	e[a].PB(b);
    	e[b].PB(a);
    }
    cout<<((check_loop())?"FHTAGN!":"NO");
    return 0;
}