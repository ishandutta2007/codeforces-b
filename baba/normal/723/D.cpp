//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = 51;
char s[N][N];
int n,m,k;
int vis[N][N],c,ok[N*N],dx[]={0,0,-1,+1},dy[]={+1,-1,0,0};
VII pos[N*N];
bool in(int i,int j){
  return (i>=1 && i<=n && j>=1 && j<=m && s[i][j] == '.');
}
void dfs(int i,int j){
//  trace(i,j);
  if(!in(i,j))return;
  if(vis[i][j])return;
  vis[i][j]=1;pos[c].PB({i,j});
  if(i == 1 || i == n || j==1 || j==m){
    ok[c] = false;
  }
  for(int x=0;x<4;x++)
    dfs(i+dx[x],j+dy[x]);
}
bool cmp(VII a,VII b){
  return SZ(a) > SZ(b);
}
int main()
{
  si(n);si(m);si(k);
 // trace(n,m,k);
  for(int i=1;i<=n;i++){
    scanf("%s\n",s[i]+1);
 //   trace(s[i]+1);
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(!vis[i][j] && s[i][j]=='.'){
        ++c;ok[c]=1;
   //     trace(i,j);
        dfs(i,j);
        if(!ok[c]){
          pos[c].clear();
          c--;
        }
      }
  sort(pos+1,pos+1+c,cmp);
  int anss = 0;
  while(c > k){
    anss += SZ(pos[c]);
    for(auto it : pos[c])
      s[it.F][it.S] = '*';
    c--;
  }
  dout(anss);
  for(int i=1;i<=n;i++)
    printf("%s\n",s[i]+1);

	return 0;
}