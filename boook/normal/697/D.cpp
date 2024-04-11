/*input
12
1 1 2 2 4 4 3 3 1 10 8
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , siz[MAX];
double ans[MAX];
vector<int> v[MAX];
void DFS1(int now){
	siz[now] = 1;
	for(auto to : v[now]){
		DFS1(to);
		siz[now] += siz[to];
	}
}
void DFS2(int now){
	for(auto to : v[now]){
		double tmp = siz[now] - 1 - siz[to];
		ans[to] = ans[now] + 1 + tmp / 2;
		DFS2(to);
	}
}
int32_t main(){
	cin >> n;
	REP(i , 2 , n + 1) cin >> x[i];
	REP(i , 2 , n + 1) v[x[i]].pb(i);
	ans[1] = 1.0;
	DFS1(1);
	DFS2(1);
	REP(i , 1 , n + 1){
		printf("%.11f ", ans[i]);
	}
	cout << endl;
    return 0;
}