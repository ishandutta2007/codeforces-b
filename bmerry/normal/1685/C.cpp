//#pragma GCC optimize("O3")
//#pragma GCC optimize("-fcx-limited-range")
//#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

/*** TEMPLATE CODE STARTS HERE ***/

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

static void redirect(int argc, const char **argv)
{
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
#ifndef __SANITIZE_ADDRESS__
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
    cin.exceptions(ios::failbit);
}

/*** TEMPLATE CODE ENDS HERE */

static void solve()
{
    int N;
    string s;
    cin >> N >> s;
    N *= 2;
    vi lvl(N + 1);
    for (int i = 0; i < N; i++)
        lvl[i + 1] = lvl[i] + (s[i] == '(' ? 1 : -1);

    int low = min_element(RA(lvl)) - lvl.begin();
    if (lvl[low] >= 0)
    {
        cout << "0\n";
        return;
    }

    int high = max_element(RA(lvl)) - lvl.begin();
    if (*min_element(lvl.begin(), lvl.begin() + high) >= 0)
    {
        cout << "1\n" << high + 1 << ' ' << N << '\n';
        return;
    }
    if (*min_element(lvl.begin() + high, lvl.end()) >= 0)
    {
        cout << "1\n1 " << high << '\n';
        return;
    }

    int first_low = -1, last_low = N;
    for (int i = 0; i <= N; i++)
        if (lvl[i] < 0)
        {
            last_low = i;
            if (first_low == -1)
                first_low = i;
        }
    int first_high = max_element(lvl.begin(), lvl.begin() + first_low) - lvl.begin();
    int last_high = max_element(lvl.begin() + last_low, lvl.end()) - lvl.begin();
    if (lvl[first_high] + lvl[last_high] - lvl[high] >= 0)
    {
        cout << "1\n" << first_high + 1 << ' ' << last_high << '\n';
        return;
    }

    cout << "2\n";
    cout << "1 " << high << '\n';
    cout << high + 1 << ' ' << N << '\n';
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
        solve();

    return 0;
}