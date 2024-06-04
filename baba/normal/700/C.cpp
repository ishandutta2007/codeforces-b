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
const int N = int(1e3)+10;
const int M = int(3e4)+10;
int PP[N],EE[N],mark[M],n,m,s,t,P[N];
VII tree[N];
VI graph[N];//edge list representation of graph
int U[M],V[M],W[M],vis[N],arr[N],T,cmpno,C[N];
bool isbridge[M]; // if i'th edge is a bridge edge or not 
queue<int> Q[N];
int adj(int u,int e){
  return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge){ //mark bridges
  vis[u]=1;arr[u]=T++;
  int dbe = arr[u];
  for(int i=0;i<SZ(graph[u]);i++){
    int e = graph[u][i];int w = adj(u,e);
    if(mark[e])continue;
    if(!vis[w])dbe = min(dbe,dfs0(w,e));
    else if(e!=edge)dbe = min(dbe,arr[w]);
  }
  if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;
  return dbe;
}
void dfs1(int v){//Build the bridge tree
  int currcmp = cmpno; 
  Q[currcmp].push(v);vis[v]=1;
  while(!Q[currcmp].empty()){
    int u = Q[currcmp].front();Q[currcmp].pop();    
    C[u]=currcmp;
    for(int i=0;i<SZ(graph[u]);i++){
      int e = graph[u][i];int w = adj(u,e);
      if(mark[e])continue;
      if(vis[w])continue;
      if(isbridge[e]){cmpno++;
        tree[currcmp].push_back({cmpno,e});
        tree[cmpno].push_back({currcmp,e});
        dfs1(w);
      }
      else Q[currcmp].push(w),vis[w]=1;
    }
  }
}
void buildBridgeTree(){
  SET(vis,0);SET(isbridge,0);cmpno=1;
  for(int i=1;i<=n;i++)tree[i].clear();
  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs0(i,-1);
  SET(vis,0);
  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs1(i),cmpno++;
}
int getMin(int s,int t){
  queue<int> Q;SET(PP,0);
  Q.push(s);SET(vis,0);vis[s]=1;
  while(!Q.empty()){
    int u = Q.front();Q.pop();
    for(auto w:tree[u])
      if(!vis[w.F]){
        EE[w.F] = w.S;
        PP[w.F] = u;
        vis[w.F]=1;
        Q.push(w.F);
      }
  }
  int x = t;
  int ret = 0;
  while(PP[x]){
    if(!ret || W[EE[x]] < W[ret])
      ret = EE[x];
    x = PP[x];
  }
  return ret;
}
int main()
{
  si(n);si(m);si(s);si(t);
  for(int i=1;i<=m;i++){
    scanf("%d %d %d",U+i,V+i,W+i);
    graph[U[i]].PB(i);
    graph[V[i]].PB(i);
  }
  queue<int> Q;Q.push(s);vis[s]=1;
  while(!Q.empty()){
    int u = Q.front();Q.pop();
    for(auto e:graph[u]){
      int w = adj(u,e);
      if(!vis[w]){
        P[w] = e;
        vis[w]=1;
        Q.push(w);
      }
    }
  }
  if(!vis[t]){
    puts("0\n0");
    return 0;
  }
  int x = t;
  VI ans;int cans = int(2e9)+1;
  while(P[x]){
    mark[P[x]]=1;
    buildBridgeTree();
    int e = getMin(C[s],C[t]);
    if(C[s]!=C[t] && W[e] + W[P[x]] < cans){
      cans = W[e] + W[P[x]];
      ans.clear();ans.PB(e);ans.PB(P[x]);
    }
    mark[P[x]]=0;
    x = adj(x,P[x]);
  }
  if(ans.empty())return (puts("-1"),0);
  sort(ALL(ans));reverse(ALL(ans));
  if(ans.back()==0)ans.pop_back();
  dout(cans);
  dout(SZ(ans));
  for(auto e:ans)
    printf("%d ",e);
  puts("");
	return 0;
}