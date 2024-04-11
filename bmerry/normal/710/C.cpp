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

static void solve()
{
    int N;
    cin >> N;
    vector<vi> ans(N, vi(N, -1));
    for (int i = 0; i < N / 2; i++)
    {
        int par = (N / 2 - i + 1) % 2;
        for (int j = i; j < N - i - 1; j++)
            ans[i][j] = par++;
        for (int j = i; j < N - i - 1; j++)
            ans[j][N - i - 1] = par++;
        for (int j = N - 1 - i; j > i; j--)
            ans[N - i - 1][j] = par++;
        for (int j = N - 1 - i; j > i; j--)
            ans[j][i] = par++;
    }
    ans[N / 2][N / 2] = 1;
    int nxt[2] = {2, 1};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int p = ans[i][j] % 2;
            ans[i][j] = nxt[p];
            nxt[p] += 2;
        }
    for (int i = 0; i < N; i++)
    {
        int rsum = 0, csum = 0;
        for (int j = 0; j < N; j++)
        {
            rsum += ans[i][j];
            csum += ans[j][i];
        }
        assert(rsum % 2);
        assert(csum % 2);
    }
    int d1 = 0, d2 = 0;
    for (int i = 0; i < N; i++)
    {
        d1 += ans[i][i];
        d2 += ans[N - 1 - i][i];
    }
    assert(d1 % 2);
    assert(d2 % 2);
    for (int i = 0; i < N; i++)
    {
        for (int v : ans[i])
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