#include <bits/stdc++.h>
//using 
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
string b,n;
ll R;
int B,N; 
int c,ph;
bool exceed;
int phi(int x)
{
	int v=x;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			v=v/i*(i-1);
			while(x%i==0)
			x/=i;
		}
	}
	if(x>1)
	v=v/x*(x-1);
	return v;
}
int mod(string s,int v)
{
	ll ret=0;
	rep(i,s.size())
	{
		ret=ret*10+s[i]-'0';
		ret%=v;
	}
	return ret;
}
int _mod(string s,int v)
{
	ll ret=0;
	rep(i,s.size())
	{
		ret=ret*10+s[i]-'0';
		if(ret>v)
		{
			ret%=v;
			exceed=1;
		}
	}
	return ret;
}
ll qkpw(ll a,ll b,ll p)
{
	ll ret=1%p;
	while(b)
	{
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>b>>n>>c;cout<<"";ph=phi(c);cout<<"";
	B=mod(b,c);N=_mod(n,ph)-1;if(exceed)N+=ph;
	cout<<"";
	R=(B-1+c)*qkpw(B,N,c)%c;
	cout<<"";;
	if(R==0) cout<<c<<endl;
	else cout<<R<<endl;
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/