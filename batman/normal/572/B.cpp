  ////////////////////////////////////////////////////////////////
 //~~~~~~~~~~~~~~~ Sa1378 Platform Vesion 1.3.6 ~~~~~~~~~~~~~~~//
////////////////////////////////////////////////////////////////


// Don't push me
	// Cause I'm close to the edge
		// I'm trying not to lose my head


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cout << #x << " is " << x << endl;
#define N (101*1000)
#define ll long long
#define ld long double
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define sin(a) sin(a*PI/180)
#define tan(a) sin(a*PI/180)
#define cot(a) sin(a*PI/180)
#define cos(a) cos(a*PI/180)
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e12);
const ll MOD=((ll)1e9+7);
const ll BIG_HSH=((ll)9999999900000001);
const ll SML_HSH=((ll)100030001);
inline ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/(sqr5);}
inline ld fib(ll x,ll mod){return (tavan(p_,x,mod)-tavan(1-p_,x,mod))/(sqr5);}
inline ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,k;
ll s[N],b[N];
vector <pair<ll,ll> > s2,b2;

int Sa1378
{
	IB
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		char c;
		ll p,q;
		cin>>c>>p>>q;
		if(c=='S')
			s[p]+=q;
		else
			b[p]+=q;	
	}
	
	for(ll i=0;i<N;i++)
	{
		if(s[i])
			s2.PB({i,s[i]});
		if(b[i])
			b2.PB({i,b[i]});			
	}	
	sort(s2.begin(),s2.end());
	sort(b2.begin(),b2.end());
	
	
	for(int i=min((ll)s2.size(),k)-1;i>=0;i--) 
		cout<<"S "<<s2[i].first<<" "<<s2[i].second<<"\n";
	for(int i=b2.size()-1;i>=max((ll)b2.size()-k,0ll);i--)
		cout<<"B "<<b2[i].first<<" "<<b2[i].second<<"\n";
	
    return 0;
}