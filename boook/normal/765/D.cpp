/*input
2
2 1
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
#define MAX 1009000
#define INF 0x3f3f3f3f

int n , x[MAX] , val[MAX] , a[MAX] , b[MAX];
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int po = 0;
	REP(i , 1 , n + 1) if(x[i] == i){
		val[x[i]] = po + 1;
		b[++po] = i;
	}
	REP(i , 1 , n + 1){
		if(val[x[i]] == 0) return cout << -1 << endl , 0;
		a[i] = val[x[i]];
	}
	cout << po << endl;
	REP(i , 1 , n + 1) cout << a[i] << " " ; cout << endl;
	REP(i , 1 , po + 1) cout << b[i] << " " ; cout << endl;
    return 0;
}