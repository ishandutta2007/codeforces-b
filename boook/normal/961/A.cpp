/*input
3 9
1 1 2 2 2 3 1 2 3
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
#define MAX 100000
#define INF 0x3f3f3f3f

int n , m , cnt[MAX];
int32_t main(){
	IOS;
	cin >> m >> n;
	REP(i , 1 , n + 1){
		int in; cin >> in;
		cnt[in] ++;
	}
	int ans = INF;
	REP(i , 1 , m + 1) ans = min(ans , cnt[i]);
	cout << ans << endl;
    return 0;
}