#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

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
    ios::sync_with_stdio(false);
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
}

/*** TEMPLATE CODE ENDS HERE */

#define MOD 1000000007

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vi freq(1 << 20);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int b = 0; b < 20; b++)
    {
        int mask = 1 << b;
        for (int i = 0; i < (1 << 20); i++)
            if (i & mask)
                freq[i - mask] += freq[i];
    }

    ll ans = 0;
    vector<int> p2((1 << 20) + 1);
    p2[0] = 1;
    for (int i = 1; i <= (1 << 20); i++)
    {
        p2[i] = p2[i - 1] * 2;
        if (p2[i] >= MOD)
            p2[i] -= MOD;
    }
    for (int i = 0; i < (1 << 20); i++)
    {
        if (__builtin_parity(i))
            ans -= p2[freq[i]] - 1;
        else
            ans += p2[freq[i]] - 1;
    }
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';

    return 0;
}