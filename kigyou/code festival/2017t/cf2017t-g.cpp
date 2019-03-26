#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,g[40][40]={},m,a,b,two[21],dp[2000000],dp3[2000000],cnt,ans;
vector<int> dp2[2000000];
int main(){
    scanf("%d %d",&n,&m);
    two[0]=1;
    for(int i=1;i<=n/2;i++){
        two[i]=2*two[i-1];
    }
    for(int i=0;i<two[n/2];i++){
        dp[i]=1;
    }
    for(int i=0;i<two[n-n/2];i++){
        dp3[i]=1;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        g[a][b]=1;
        g[b][a]=1;
        if(a<n/2&&b<n/2){
            dp[two[a]+two[b]]=0;
        }
        if(a>=n/2&&b>=n/2){
            dp3[two[a-n/2]+two[b-n/2]]=0;
        }
    }
    for(int i=0;i<two[n/2];i++){
        if(dp[i]==0){
            for(int j=0;j<n/2;j++){
                if((i&two[j])==0){
                    dp[i+two[j]]=0;
                }
            }
        }
    }
    for(int i=0;i<two[n-n/2];i++){
        if(dp3[i]==0){
            for(int j=n/2;j<n;j++){
                if((i&two[j-n/2])==0){
                    dp3[i+two[j-n/2]]=0;
                }
            }
        }
        else{
            cnt=0;
            for(int j=0;j<n-n/2;j++){
                if((i&two[j])){
                    cnt++;
                }
            }
            dp3[i]=cnt;
        }
    }
    for(int i=n/2;i<n;i++){
        dp2[0].push_back(i);
    }
    for(int i=0;i<n/2;i++){
        for(int j=n/2;j<n;j++){
            if(g[i][j]==0){
                dp2[two[i]].push_back(j);
            }
        }
    }
    for(int i=0;i<two[n/2];i++){
        for(int j=0;j<n/2;j++){
            if((i&two[j])==0&&dp2[i+two[j]].empty()){
                int l=0,r=0;
                while(l<dp2[i].size()&&r<dp2[two[j]].size()){
                    if(dp2[i][l]<dp2[two[j]][r]){
                        l++;
                    }
                    else if(dp2[i][l]>dp2[two[j]][r]){
                        r++;
                    }
                    else{
                        dp2[i+two[j]].push_back(dp2[i][l]);
                        l++;
                        r++;
                    }
                }
            }
        }
    }
    for(int i=0;i<two[n-n/2];i++){
        if(dp3[i]==0){
            for(int j=0;j<n-n/2;j++){
                if(i&two[j]){
                    dp3[i]=max(dp3[i],dp3[i^two[j]]);
                }
            }
        }
    }
    for(int i=0;i<two[n/2];i++){
        if(dp[i]){
            if((i)==131){
                printf("error\n");
            }
            int x=0;
            cnt=0;
            for(int j=0;j<n/2;j++){
                if(i&two[j]){
                    cnt++;
                }
            }
            for(int j=0;j<dp2[i].size();j++){
                x+=two[dp2[i][j]-n/2];
            }
            ans=max(ans,cnt+dp3[x]);
        }
    }
    printf("%d\n",ans);
}