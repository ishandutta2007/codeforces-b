#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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

int n , m;
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds;
int32_t main(){
    cin >> n >> m;
    ds.init();
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        ds.Union(q , w);
    }
    if(n - 1 != m){
        cout << "no" << endl;
        return 0;
    }
    int cnt = 0;
    REP(i , 1 , n + 1){
        if(ds[i] == i) cnt ++;
    }
    if(cnt == 1) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}