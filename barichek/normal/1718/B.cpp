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

const int max_n = -1, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> kek;
    kek.pb(1);
    kek.pb(2);
    while (kek[len(kek)-1]+kek[len(kek)-2]<=1e9){
        kek.pb(kek[len(kek)-1]+kek[len(kek)-2]);
    }
    int n=len(kek);

    int test;
    cin>>test;
    while (test--){
        int k;
        cin>>k;
        vector<int> c(k);
        for (int i=0;i<k;i++){
            cin>>c[i];
        }
        auto check12358=[&](int banned_id)
        {
            vector<bool> have(n,0);
            for (int id=0;id<k;id++){
                int cur=c[id];
                for (int i=n-1;i>=0;i--){
                    if (cur>=kek[i] && (id!=banned_id || i>0)){
//                        cout<<kek[i]<<" !!!\n";
                        cur-=kek[i];
                        if (have[i]){
                            return false;
                        }
                        have[i]=1;
                    }
                }
                if (cur!=0){
                    return false;
                }
            }
            for (int i=1;i<n;i++){
                if (have[i] && !have[i-1]){
                    return false;
                }
            }
            return true;
        };
        bool ans=0;
        for (int i=0;i<k;i++){
            c[i]--;

//            cout<<"new c[i] :: "<<c[i]<<"\n";

            if (check12358(i)){
                ans=1;
            }

            c[i]++;
        }
        cout<<(ans ? "YES" : "NO")<<"\n";
    }
}