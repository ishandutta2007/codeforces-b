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
#define MAX 
#define INF 0x3f3f3f3f


int nn , mm , q , w;
void A(){
    int tma = w , tmb = nn - q + 1;
    q = tma , w = tmb;
    swap(nn , mm);
}
void B(){
    w = mm - w + 1;
}
void C(){
    A();
    A();
    A();
}
int n , m , x , y , z , p;
int32_t main(){
    cin >> n >> m >> x >> y >> z >> p;
    x %= 4 , z %= 4 , y %= 2;
    REPNM(times , 1 , p + 1){
        nn = n , mm = m;
        cin >> q >> w;
        REP(i , x) A();
        REP(i , y) B();
        REP(i , z) C();
        cout << q << " " << w << endl;
    }
    return 0;
}