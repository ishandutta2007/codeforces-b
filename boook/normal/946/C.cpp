/*input
thereisnoanswer
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
#define MAX 
#define INF 0x3f3f3f3f

string p = "abcdefghijklmnopqrstuvwxyz" , s;
int32_t main(){
	IOS;
	cin >> s;
	if(s.size() < p.size()) return cout << -1 << endl , 0;
	int pos = 0;
	REP(i , 0 , s.size()){
		if(pos < p.size() && s[i] <= p[pos]) s[i] = p[pos] , pos ++;
	}
	if(pos == p.size()) cout << s << endl;
	else cout << -1 << endl;	
    return 0;
}