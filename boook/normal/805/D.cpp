#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 1500000
#define INF 0x3f3f3f3f
#define mod 1000000007

string s;
int pre[MAX];
int32_t main(){
	cin >> s;
	int cnt = 0 , ans = 0;
	pre[1] = 1;
	REPNM(i , 2 , MAX) pre[i] = (pre[i - 1] * 2) % mod;
	REPNM(i , 2 , MAX) pre[i] = (pre[i - 1] + pre[i]) % mod;
	REP(i , s.size()){
		if(s[i] == 'a') cnt ++;
		else {
			ans = (ans + pre[cnt]) % mod;
		}
	}
	cout << ans << endl;
    return 0;
}