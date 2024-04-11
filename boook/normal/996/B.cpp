/*input
6
5 2 6 5 7 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int t = 1e15 , ans = -1;
	REP(i , 1 , n + 1){
		int now = -1;
		RREP(j , 40 , 0){
			int to = now + (1LL << j);
			int val = to * n + i - 1;
			if(x[i] - val > 0) now = to;
		}
		now ++;
		if(now * n + i < t) t = now * n + i , ans = i;
	}
	cout << ans << endl;
    return 0;
}