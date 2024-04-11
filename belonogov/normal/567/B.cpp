#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9 + 19;

int n;
set < int > q;
int answer = 0;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char ch; 
        int x;
        scanf(" %c %d", &ch, &x);
        assert(ch == '+' || ch == '-');
        if (ch == '+') {
            q.insert(x);
            answer = max(answer, (int)q.size());
        }
        else  {
            if (q.count(x) == 1) {
                q.erase(x);
            }
            else {
                answer++;
            }
        }
    }

    cout << answer << endl;
}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}