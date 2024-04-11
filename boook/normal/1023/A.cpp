/*input
9 6
gfgf*gfgf
gfgfgf
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

int n , m;
string s , t;
int32_t main(){
    IOS;
    cin >> n >> m;
    cin >> s >> t;
    int idx = -1;
    REP(i , 0 , s.size()) if(s[i] == '*') idx = i;
    if(idx == -1){
        if(s == t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if(s.size() > t.size() + 1) cout << "NO" << endl; 
    else {
        int fr = idx;
        int ba = s.size() - idx - 1;
        // DBGG(fr , ba);
        if(s.substr(0 , fr) == t.substr(0 , fr)){
            reverse(ALL(s));
            reverse(ALL(t));
            if(s.substr(0 , ba) == t.substr(0 , ba)){
                if(fr + ba <= t.size()) cout << "YES" << endl;
                else cout << "NO" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}