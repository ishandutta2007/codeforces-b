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
#define MAX 200000
#define INF 0x3f3f3f3f

string s;
int z[MAX];
vector<int> v;
int32_t main(){
    cin >> s;
    z[0] = s.size();
    int l = 0 , r = 0;
    REP(i , 1 , s.size()){
        z[i] = max(min(z[i - l] , r - i + 1) , 0);
        while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]]){
            l = i , r = i + z[i];
            z[i] ++;
        }
    }
    REP(i , 0 , s.size()) v.pb(z[i]);
    sort(ALL(v));
    vector<PII> ans;
    REP(i , 0 , s.size()){
        if(z[s.size() - 1 - i] == i + 1){
            int tmp = v.size() - (lower_bound(ALL(v) , i + 1) - v.begin());
            ans.pb(mp(i + 1 , tmp));
        }
    }
    cout << ans.size() << endl;
    for(auto to : ans) cout << to.A << " " << to.B << endl;
    return 0;
}