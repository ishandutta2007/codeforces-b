//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (200*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
int a[200*1000],n;
set<int> s;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    s.insert(a[0]);
    for(int i=1;i<n;i++)
    {
    	/*
    	cerr<<*s.lower_bound(a[i])<<" ";
    	if(s.lower_bound(a[i])==s.end())
    		cerr<<1;	
    	cerr<<endl;	
    	*/
        if(s.lower_bound(a[i])==s.end())
            s.insert(a[i]);
        else
        {
            s.erase(s.lower_bound(a[i]));
            s.insert(a[i]);
        }
    }
    cout<<s.size();
}