/*input
5073
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
#define MAX 
#define INF 0x3f3f3f3f

string s;
int32_t main(){
    IOS;
    cin >> s;
    int ans = INF;

    REP(i , 0 , s.size()) REP(j , 0 , s.size()){
        if(i != j){
            int val = (s[i] - '0') * 10 + s[j] - '0';
            if(val % 25 == 0){
                string g;
                int all = s.size() , cnt = 0;
                REP(ii , 0 , s.size()) if(ii != i && ii != j) g += s[ii];
                g += s[i] , g += s[j];
                cnt += all - 1 - j + all - 2 - i + (i > j);
                if(g[0] == '0'){
                    int tmp = INF;
                    RREP(ii , all - 3 , 0) if(g[ii] != '0') tmp = min(tmp , ii);
                    cnt += tmp;
                }
                ans = min(ans , cnt);
            }
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}