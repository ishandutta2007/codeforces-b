/*input

*/
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 
#define inf 0x3f3f3f3f

int t, n, m;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n >> m;
        if (n % m == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}