//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

const int max_n = -1, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        string s;
        cin>>s;
        int ans=0;
        for (int i=0;i<len(s);){
            if (i+2<len(s) && s[i]!='Z' && s[i]==s[i+1] && s[i]==s[i+2]){
                ans+=2;
                s[i+1]='Z';
                s[i+2]='Z';
                i+=3;
            }
            else if (i+1<len(s) && s[i]!='Z' && s[i]==s[i+1]){
                ans++;
                s[i+1]='Z';
                i+=2;
            }
            else if (i+2<len(s) && s[i]!='Z' && s[i]==s[i+2]){
                ans++;
                s[i+2]='Z';
                i++;
            }
            else{
                i++;
            }
        }
        cout<<ans<<"\n";
    }
}