#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n;
deque <ll> s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		s.push_back(1);
		while(s.size()>1 && s[(ll)s.size()-1]==s[(ll)s.size()-2])
		{
			s.pop_back();
			s.back()++;
		}
	}
	for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
	
    return 0;
}