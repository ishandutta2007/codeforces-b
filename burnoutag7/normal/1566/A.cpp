#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,s;
    cin>>n>>s;
    cout<<s/(n/2+1)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}