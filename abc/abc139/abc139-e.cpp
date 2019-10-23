#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
#include<utility>
#include<map>
#include<set>
using namespace std;

int visit[1000000],dis[1000000];
vector<int> v[1000000];

int dfs(int p){
    int res1=1,res2=0;
    visit[p]=1;
    for(int i=0;i<v[p].size();i++){
        if(visit[v[p][i]]==1&&dis[v[p][i]]){
            res2=dis[v[p][i]]+1;
            if(res2==0){
                dis[p]=-1;
                return -1;
            }
            res1=max(res1,res2);
        }
        else if(visit[v[p][i]]==1&&!dis[v[p][i]]){
            dis[p]=-1;
            return -1;
        }
        else{
            res2=dfs(v[p][i])+1;
            if(res2==0){
                dis[p]=-1;
                return -1;
            }
            res1=max(res2,res1);
        }
    }
    dis[p]=res1;
    return res1;
}

int main(){
    int n,a[1000],ans=0,flag,f[1001]={};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-1;j++){
            scanf("%d",&a[j]);
            if(j){
                v[max(i-1,a[j]-1)*n+min(i,a[j])-1].push_back(max(i-1,a[j-1]-1)*n+min(i,a[j-1])-1);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(visit[i*n+j]==0){
                dis[i*n+j]=dfs(i*n+j);
            }
            if(dis[i*n+j]==-1){
                printf("-1\n");
                return 0;
            }
            ans=max(ans,dis[i*n+j]);
        }
    }
    printf("%d\n",ans);
}