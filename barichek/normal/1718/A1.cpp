//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 1e5+10, inf = 1000111222;

int pref[max_n];

int solve(vector<int> A)
{
    int n=A.size();
    for (int i=1;i<=n;i++){
        pref[i]=pref[i-1]^A[i-1];
    }
    int ans=0;
    set<int> s;
    s.insert(pref[0]);
    for (int i=1;i<=n;i++){
        if (s.count(pref[i])){
            ans++;
            s.clear();
        }
        s.insert(pref[i]);
    }
    return n-ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        int ans=0;
        vector<int> A;
        for (int i=0;i<n;i++){
            int aa;
            cin>>aa;
            if (aa!=0){
                A.pb(aa);
            }
            else{
                ans+=solve(A);
                A.clear();
            }
        }
        ans+=solve(A);
        A.clear();
        cout<<ans<<"\n";
    }
}