#include<cstdio>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;
int cnt,h,w,dp[2000][2000],f[2000][2000]={},ans=0,l[2000][2000],r[2000][2000];
char s[2000][2010];
int main(){
    stack<pair<int,int> > st;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            cnt=0;
            if(s[i][j]=='#'){
                cnt++;
            }
            if(s[i][j-1]=='#'){
                cnt++;
            }
            if(s[i-1][j]=='#'){
                cnt++;
            }
            if(s[i-1][j-1]=='#'){
                cnt++;
            }
            if(cnt%2){
                f[i][j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        dp[i][0]=i+1;
    }
    for(int i=0;i<w;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(f[i][j]){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j]+1;
            }
        }
    }
    ans=max(h,w);
    for(int i=0;i<h;i++){
        l[i][0]=0;
        r[i][w-1]=w-1;
        while(!st.empty()){
            st.pop();
        }
        st.push(make_pair(0,dp[i][0]));
        for(int j=1;j<w;j++){
            while(!st.empty()&&st.top().second>=dp[i][j]){
                st.pop();
            }
            if(st.empty()){
                l[i][j]=0;
            }
            else{
                l[i][j]=st.top().first;
            }
            st.push(make_pair(j,dp[i][j]));
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(make_pair(w-1,dp[i][w-1]));
        for(int j=w-2;j>=0;j--){
            while(!st.empty()&&st.top().second>=dp[i][j]){
                st.pop();
            }
            if(st.empty()){
                r[i][j]=w-1;
            }
            else{
                r[i][j]=st.top().first-1;
            }
            st.push(make_pair(j,dp[i][j]));
        }
        for(int j=0;j<w;j++){
            ans=max(ans,dp[i][j]*(r[i][j]-l[i][j]+1));
        }
    }
    printf("%d\n",ans);
}