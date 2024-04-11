//#pragma GCC optimize("O3")
//#pragma GCC target("arch=corei7-avx")
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int Q;
    cin >> Q;
    for (int pass = 0; pass < Q; pass++)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        vi g;
        int run = 0;
        for (char c : s)
        {
            if (c == '.')
                run++;
            else
            {
                if (run >= b)
                    g.push_back(run);
                run = 0;
            }
        }
        if (run >= b)
            g.push_back(run);
        sort(RA(g));

        bool alice = false;
        if (g.empty() || g[0] < a || g.back() >= 4 * b + a - 1
            || (g.size() >= 2 && g[g.size() - 2] >= 2 * b))
            alice = false;
        else
        {
            auto good = [a, b] (int x)
            {
                return x < b || (x >= a && x < 2 * b);
            };
            for (int i = 0; i + a <= g.back(); i++)
            {
                int j = g.back() - a - i;
                if (good(i) && good(j))
                {
                    int c = g.size() - 1 + (i >= a) + (j >= a);
                    if (c % 2 == 0)
                    {
                        alice = true;
                        break;
                    }
                }
            }
        }
        cout << (alice ? "YES" : "NO") << "\n";
    }

    return 0;
}