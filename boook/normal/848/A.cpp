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

int n;
string s;
int32_t main(){
	cin >> n;
	int po = 0;
	if(n == 0){
		cout << "a" << endl;
		return 0;
	}
	while(n){
		s += 'a' + po;
		int cnt = 1;
		while(n >= cnt){
			s += 'a' + po;
			n -= cnt;
			cnt ++;
		}
		po ++;
	}
	cout << s << endl;
    return 0;
}