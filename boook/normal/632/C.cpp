/*input
4
abba
abacaba
bcd
er
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
#define MAX 600000
#define INF 0x3f3f3f3f

int n;
string s[MAX];
int cmp(string a , string b){
    string q = a + b;
    string w = b + a;
    return q < w;
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> s[i];
    sort(s + 1 , s + 1 + n , cmp);
    REP(i , 1 , n + 1) cout << s[i];
    cout << endl;
    return 0;
}