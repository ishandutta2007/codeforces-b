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

int x[MAX];

int32_t main(){
	REP(i , 0 , 5) cin >> x[i];
	int ans = 0 , sum = 0;
	REP(i , 0 , 5) sum += x[i];
	ans = sum;
	REP(i , 0 , 5) REP(j , i + 1 , 5){
		if(x[i] == x[j]) ans = min(ans , sum - x[i] * 2);
	}
	REP(i , 0 , 5) REP(j , i + 1 , 5) REP(k , j + 1 , 5) {
		if(x[i] == x[j] && x[j] == x[k]) ans = min(ans , sum - x[i] * 3);
	}
	cout << ans << endl;
    return 0;
}