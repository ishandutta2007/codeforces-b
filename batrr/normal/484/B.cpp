#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>
 
#include <ctime>
#include <cassert> 
 
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double 
#define ll long long 
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
using namespace std;                    
const ll maxn=1e6+1,inf=2e9,mod=1e9+7; 
int n,ans,mx[2*maxn],a[maxn];
int main(){                
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mx[a[i]]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<2*maxn;i++)
		mx[i]=max(mx[i],mx[i-1]);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1])
			continue;
		for(int j=2*a[i]-1;j<2*maxn;j+=a[i])
			ans=max(ans,mx[j]%a[i]);
	}	
	cout<<ans;
}