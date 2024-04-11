#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m;
string p[MAX];
PII x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , n) cin >> p[i];
    REP(i , n){
        x[i] = mp(-1 , -1);
        REP(j , m){
            if(p[i][j] == 'G') x[i].A = j;
            if(p[i][j] == 'S') x[i].B = j;
        }        
        if(x[i].A == -1 || x[i].B == -1 || x[i].A > x[i].B) return puts("-1");
    }
    set<int> cc;
    REP(i , n){
        cc.insert(x[i].B - x[i].A);
    }
    cout << cc.size() << "\n";
    return 0;
}