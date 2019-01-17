#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> t[301];
vector<int> v;
int depth[301],f[301];

void dfs(int x,int y,int d){
    depth[x]=d;
    for(int i=0;i<t[x].size();i++){
        if(t[x][i]!=y){
            dfs(t[x][i],x,d+1);
        }
    }
}

void dfs2(int x){
    f[x]=1;
    for(int i=0;i<t[x].size();i++){
        if(f[t[x][i]]==0&&depth[x]<depth[t[x][i]]){
            v.push_back(t[x][i]);
            dfs2(t[x][i]);
        }
    }
}

int main(){
    int n,m,k,p,root,l,r,ans,cnt;
    vector<pair<int,int> > d;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p);
        if(p){
            t[i].push_back(p);
            t[p].push_back(i);
        }
        else{
            root=i;
        }
    }
    dfs(root,-1,1);
    for(int i=1;i<=n;i++){
        d.push_back(make_pair(depth[i],i));
    }
    sort(d.begin(),d.end());
    for(int i=0;i<m;i++){
        ans=-1;
        for(int j=1;j<=n;j++){
            if(f[j]==0){
                v.clear();
                v.push_back(j);
                dfs2(j);
                l=r=cnt=0;
                for(int a=0;a<n&&cnt<m-i-1;a++){
                    if(f[d[a].second]==0){
                        l+=d[a].first;
                        cnt++;
                    }
                }
                for(int a=n-1;a>=0&&cnt<2*(m-i-1);a--){
                    if(f[d[a].second]==0){
                        r+=d[a].first;
                        cnt++;
                    }
                }
                if(cnt==2*(m-i-1)&&l<=k-depth[j]&&k-depth[j]<=r){
                    ans=j;
                    break;
                }
                else{
                    for(int a=0;a<v.size();a++){
                        f[v[a]]=0;
                    }
                }
            }
        }
        if(ans==-1){
            printf("-1\n");
            return 0;
        }
        else{
            printf("%d ",ans);
            k-=depth[ans];
        }
    }
}