/*input
3 2 3
1 8 4
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n >> k >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		v[x[i] % m].pb(x[i]);
		if(v[x[i] % m].size() == k){
			cout << "Yes" << endl;
			for(auto to : v[x[i] % m]){
				cout << to << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "No" << endl;
    return 0;
}