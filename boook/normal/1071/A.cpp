/*input
0 0
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
vector<int> a , b;
int32_t main(){
    IOS;
    cin >> n >> m;
    int sum = n + m , ans = 0;
    while((ans + 1) * (ans + 2) / 2 <= sum) ans ++;
    RREP(i , ans , 1){
        if(n >= i){
            n -= i;
            a.pb(i);
        }
        else b.pb(i);
    }
    cout << a.size() << endl;
    for(auto to : a) cout << to << " "; cout << endl;
    cout << b.size() << endl;
    for(auto to : b) cout << to << " "; cout << endl;
    return 0;
}