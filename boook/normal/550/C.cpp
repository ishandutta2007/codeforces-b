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
#define MAX 
#define INF 0x3f3f3f3f

string s;

int32_t main(){
    cin >> s;
    REP(i , 0 , s.size()){
        if(s[i] == '0' || s[i] == '8'){
            cout << "YES" << endl;
            cout << s[i] << endl;
            return 0;
        }
    }
    REP(i , 0 , s.size() - 1){
        if(s[i] == '0') continue;
        REP(j , i + 1 , s.size()){
            int tmp = (s[i] - '0') * 10 + s[j] - '0';
            if(tmp % 8 == 0){
                cout << "YES" << endl;
                cout << tmp << endl;
                return 0;
            } 
        }
    }
    REP(i , 0 , s.size() - 1){
        if(s[i] == '0') continue;
        REP(j , i + 1 , s.size()){
            REP(k , j + 1 , s.size()){
                int tmp = ((s[i] - '0') * 10 + s[j] - '0') * 10 + s[k] - '0';
                if(tmp % 8 == 0){
                    cout << "YES" << endl;
                    cout << tmp << endl;
                    return 0;
                } 
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}