#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int main(){
    int a,b;
    string s;
    cin >> s;
    a = b = 0;
    for (int i=0;i<s.length();i++)
        if (s[i]=='+'){
            a++;
            if (b>0)
                b--;
        }else{
            b++;
            if (a>0)
                a--;
        }
    cout << a+b << endl;
    return 0;
}