/*input
3
5 1
3
3 3
1 2 3
4 1
1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

int t , n , m , x[MAX];
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 1 , t + 1){
		cin >> n >> m;
		REP(i , 1 , n + 1) x[i] = INF;
		REP(i , 1 , m + 1){
			int in ; cin >> in;
			x[in] = 1;
		}
		// REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
		REP(i , 1 , n + n + 1 + 1){
			REP(j , 2 , n + 1) if(x[j] > x[j - 1] + 1) x[j] = x[j - 1] + 1;
			RREP(j , n - 1 , 1) if(x[j] > x[j + 1] + 1) x[j] = x[j + 1] + 1;
		}
		int ans = 0;
		REP(i , 1 , n + 1) ans = max(ans , x[i]);
		cout << ans << endl;
	}
    return 0;
}