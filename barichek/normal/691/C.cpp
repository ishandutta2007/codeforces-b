#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define inter_work fflush(stdout);
#define stop system("pause");
#define endl putchar('\n')
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---math_fun---///

template<typename type> inline type sqr(type n)
{
    return n*n;
}

vi pref_f(string s)
{
	vector<int> ans(s.length());
	for (int i=1;i<s.length();i++)
    {
		int j=ans[i-1];
		while (j>0&&s[i]!=s[j])
			j=ans[j-1];
		if (s[i]==s[j]) j++;
		ans[i]=j;
	}
	return ans;
}

template<typename type> inline ll pow(type a,int n)
{
    if (n==0) return 1;
    if (n==1) return a;
    if (n&1) return a*pow(a,n-1);
    else return sqr(pow(a,n>>1));
}

template<typename type1,typename type2> inline ll __gcd(type1 a,type2 b)
{
    while (a&&b)
        (a>b)?a%=b:b%=a;
    return a+b;
}

///---read---///

inline bool read(char &n)
{
    n=' ';
    while (true)
    {
        n=getchar();
        if (feof(stdin)) break;
        if (n==' '||n=='\n') continue;
        return true;
    }
    return false;
}

inline bool read(string &n)
{
    char c;
    n="";
    bool work=false;
    while (true)
    {
        c=getchar();
        if (feof(stdin)) break;
        if (c==' '||c=='\n')
        {
            if (work) break;
            else continue;
        }
        n+=c;
        work=true;
    }
    if (work) return true;
    else return false;
}

template<typename type> inline bool read(type &n)
{
    if (typeid(ld)==typeid(n)||typeid(double)==typeid(n))
    {
        n=(type)0;
        int st=1;
        char c;
        bool minus=false;
        bool left=true;
        bool work=false;
        type step[20];
        step[1]=1e-1;
        for (int i=2;i<20;i++)
            step[i]=step[i-1]/10;
        while (true)
        {
            c=getchar();
            if (feof(stdin)) break;
            if (c==' '||c=='\n')
            {
                if (work) break;
                else continue;
            }
            if (c=='-') minus=true;
            elif (c=='.') left=false;
            elif (left) n=n*10+c-'0', work=true;
            else n+=(c-'0')*step[st++], work=true;
        }
        if (minus) n*=(type)-1;
        if (work) return true;
        else return false;
    }
    else
    {
        n=0;
        char c;
        bool minus=false;
        bool work=false;
        while (true)
        {
            c=getchar();
            if (feof(stdin)) break;
            if (c==' '||c=='\n')
            {
                if (work) break;
                else continue;
            }
            if (c=='-') minus=true;
            else n=n*10+c-'0', work=true;
        }
        if (minus) n*=-1;
        if (work) return true;
        else return false;
    }
}

template<typename type1,typename type2> inline bool read(type1 &a,type2 &b)
{
    return read(a)&&read(b);
}

template<typename type1,typename type2,typename type3> inline bool read(type1 &a,type2 &b,type3 &c)
{
    return read(a)&&read(b)&&read(c);
}

///---write---///

inline void write_(char n)
{
    putchar(n);
}

inline void write_(string n)
{
    for (int i=0;i<n.length();i++)
        putchar(n[i]);
}

template<typename type> inline void write_(type n)
{
    if (typeid(ld)==typeid(n)||typeid(double)==typeid(n))
        printf("%.8f",(double)n);
    else
    {
        if (n==0)
        {
            putchar('0');
            return;
        }
        char ans[20];
        int kil=0;
        if (n<0) putchar('-'), n*=-1;
        while (n)
        {
            ans[kil++]=char(n-(n/10)*10+'0');
            n/=10;
        }
        for (int i=kil-1;i>=0;i--)
            putchar(ans[i]);
    }
}

template<typename type> inline void write(type n)
{
    write_(n);
    putchar(' ');
}

template<typename type1,typename type2> inline void write(type1 a,type2 b)
{
    write(a);
    write(b);
}

template<typename type> inline void writeln(type n)
{
    write_(n);
    endl;
}

template<typename type1,typename type2> inline void writeln(type1 a,type2 b)
{
    write(a);
    writeln(b);
}

///---program start---///

int main()
{
    string s;
    fast;
    cin>>s;
    if (s[s.length()-1]=='.') s+='0';
    bool ok=false;
    for (auto i:s)
        if (i=='.') ok=true;
    if (!ok) s+=".0";
    int dop2;
    for (dop2=0;dop2<s.length();dop2++)
        if (s[dop2]!='0') break;
    s=s.substr(dop2);
    if (s[0]=='.') s='0'+s;
    int tochka;
    int tsifra=-1;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='.') tochka=i;
        elif (s[i]!='0'&&tsifra==-1) tsifra=i;
    }
    if (tsifra==-1)
        return cout<<0, 0;
    string ans;
    //cout<<tochka<<" "<<tsifra<<"\n";
    if (tochka>tsifra)
    {
        ans=s;
        for (int i=0;i<ans.length();i++)
            if (ans[i]=='.') ans=ans.substr(0,i)+ans.substr(i+1);
        ans=ans.substr(0,tsifra+1)+'.'+ans.substr(tsifra+1);
        int dop1;
        for (dop1=ans.length()-1;dop1>=0;dop1--)
            if (ans[dop1]!='0') break;
        ans=ans.substr(0,dop1+1);
        if (ans[ans.length()-1]=='.')ans=ans.substr(0,ans.length()-1);
        //cout<<ans<<"\n";
        stringstream str;
        str<<tochka-tsifra-1;
        string dopchik;
        dopchik=str.str();
        //cout<<dopchik<<"\n";
        //cout<<dopchik<<" !!!\n";
        //ans+=dopchik;
        if(dopchik!="0") ans+='E'+dopchik;
    }
    else
    {
        ans=s;
        //cout<<ans<<"\n";
        for (int i=0;i<ans.length();i++)
            if (ans[i]=='.') ans=ans.substr(0,i)+ans.substr(i+1);
        //cout<<ans<<"\n";
        tsifra--;
        ans=ans.substr(0,tsifra+1)+'.'+ans.substr(tsifra+1);
        //cout<<ans<<"\n";
        int dop1;
        for (dop1=ans.length()-1;dop1>=0;dop1--)
            if (ans[dop1]!='0') break;
        ans=ans.substr(0,dop1+1);
        for (dop1=0;dop1<ans.length();dop1++)
            if (ans[dop1]!='0') break;
        ans=ans.substr(dop1);
        if (ans[ans.length()-1]=='.')ans=ans.substr(0,ans.length()-1);
        //cout<<ans<<" !!!!\n";
        ans+='E';
        stringstream str;
        str<<tsifra-tochka+1;
        string dopchik;
        dopchik=str.str();
        //cout<<dopchik<<" !!!\n";
        ans+='-'+dopchik;
        //if (dopchik=="1") ans=ans.substr(0,ans.length()-2);
    }
    cout<<ans;
}