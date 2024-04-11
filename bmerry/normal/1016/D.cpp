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

static int bit(int x)
{
    return 1 << x;
}

static void solve()
{
    int N, M;
    cin >> N >> M;
    vi a(N), b(M);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];
    vector<vi> mat(N, vi(M));
    for (int i = 0; i < 30; i++)
    {
        vi oddr, oddc;
        for (int j = 0; j < N; j++)
            if (a[j] & bit(i))
                oddr.push_back(j);
        for (int j = 0; j < M; j++)
            if (b[j] & bit(i))
                oddc.push_back(j);
        if (SZ(oddr) % 2 != SZ(oddc) % 2)
        {
            cout << "NO\n";
            return;
        }
        int com = min(SZ(oddr), SZ(oddc));
        for (int j = 0; j < com; j++)
            mat[oddr[j]][oddc[j]] |= bit(i);
        for (int j = SZ(oddr); j < SZ(oddc); j++)
            mat[0][oddc[j]] |= bit(i);
        for (int j = SZ(oddc); j < SZ(oddr); j++)
            mat[oddr[j]][0] |= bit(i);
    }
    cout << "YES\n";
    for (int i = 0; i < N; i++)
    {
        for (int v : mat[i])
            cout << v << ' ';
        cout << '\n';
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    solve();

    return 0;
}