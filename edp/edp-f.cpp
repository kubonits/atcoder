#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int n,m,dp[3001][3001]={},x,y,z;
string s,t,ans;
int main(){
    cin>>s;
    cin>>t;
    n=s.size();
    m=t.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            if(s[i]==t[j]){
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            }
        }
    }
    x=n;
    y=m;
    z=dp[n][m];
    for(int i=x;i>=1;i--){
        for(int j=y;j>0;j--){
            if(i<1){
                break;
            }
            if(dp[i][j]==z&&dp[i][j]>max(dp[i-1][j],dp[i][j-1])){
                ans.push_back(t[j-1]);
                y=j-1;
                z--;
                break;
            }
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
}