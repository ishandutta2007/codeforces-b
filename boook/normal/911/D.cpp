/*input
4
1 2 4 3
4
1 1
1 4
1 4
2 3
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , x[MAX];

int32_t main(){
	int ans = 0;
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	REP(i , 1 , n + 1){
		REP(j , i + 1 , n + 1){
			if(x[i] > x[j]) ans = 1 - ans;
		}
	}

	cin >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		int tmp = b - a + 1;
		if(tmp * (tmp - 1) / 2 % 2 == 1) ans = 1 - ans;
		if(ans) cout << "odd" << endl;
		else cout << "even" << endl;
	}
    return 0;
}