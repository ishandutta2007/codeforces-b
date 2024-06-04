#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int n,m;
int row[55][55],col[55][55];
char s[55][55];
int ab(int i,int j,int ii,int jj){
	return i==ii ? row[i][jj]==row[i][j-1] : col[i-1][j]==col[ii][j];
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>s[i]+1;
		for(int j=1;j<=n;j++){
			row[i][j]=row[i][j-1]+(s[i][j]=='W');
			col[i][j]=col[i-1][j]+(s[i][j]=='W');
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int ii=1;ii<=m;ii++){
				for(int jj=1;jj<=n;jj++){
					if(s[i][j]=='B' && s[ii][jj]=='B'){
						if(ab(i,j,i,jj) && ab(i,jj,ii,jj)) continue;
						if(ab(i,j,ii,j) && ab(ii,j,ii,jj)) continue;
						cout<<"NO"<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}