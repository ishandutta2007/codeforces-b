/*input
3
aa
abacaba
xdd
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int t;
string s;
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 ,t){
		cin >> s;
		int ok = 0;
		REP(i , 1 , s.size()) if(s[i] != s[i - 1]) ok = 1;
		if(ok == 0) cout << -1 << endl;
		else {
			REP(i , 0 , s.size()){
				if(i + 1 != s.size() && s[i] != s[s.size() - 1]){
					swap(s[0] , s[i]);
					break;
				}
			}
			cout << s << endl;
		}
	}
    return 0;
}