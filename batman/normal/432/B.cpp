//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (100*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ll n,a[N],b[N],x;
int Sa1378
{ 
   cin>>n;
   for(int i=0;i<n;i++)
   {
        cin>>x>>b[i];
        a[x]++;
   }
   for(int i=0;i<n;i++)
   {
        cout<<n-1+a[b[i]]<<" "<<2*(n-1)-(n-1+a[b[i]])<<endl;
   }
    return 0;
}