/*input

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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) b[i] = 1 - a[i];
	REP(i , 1 , n + 1) b[i] += b[i - 1];
	RREP(i , n , 1) a[i] += a[i + 1];
	int big = max(a[1] , b[n]);
	REP(i , 1 , n + 1) big = max(big , b[i] + a[i + 1]);
	cout << big << endl;
    return 0;
}