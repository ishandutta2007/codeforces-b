/*input
4
s
f
f
s
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
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX] , dp[MAX][MAX] , pre[MAX];
string s;

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> s , x[i] = s == "f";
    if(x[n] == 1) cout << 0 << endl;

    dp[1][1] = 1;
    REP(i , 2 , n + 1){
        REP(j , 1 , i + 1) pre[j] = (pre[j - 1] + dp[i - 1][j]) % mod;
        REP(j , 1 , i + 1){
            if(x[i - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = (pre[i] - pre[j - 1] + mod) % mod;
            // DB4(i , j , " = " , dp[i][j]);
        }
    }
    int ans = 0;
    REP(i , 1 , n + 1) (ans += dp[n][i]) %= mod;
    cout << ans << endl;
    return 0;
}