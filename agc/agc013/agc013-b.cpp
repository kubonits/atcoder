#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
int main(){
    int n,m,a,b,flag=0,used[100001]={};
    vector<int> g[100001];
    deque<int> ans;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans.push_back(1);
    ans.push_back(g[1][0]);
    used[1]=used[g[1][0]]=1;
    while(!flag){
        flag=1;
        for(int i=0;i<g[ans.front()].size();i++){
            if(used[g[ans.front()][i]]==0){
                ans.push_front(g[ans.front()][i]);
                used[ans.front()]=1;
                break;
            }
        }
        for(int i=0;i<g[ans.back()].size();i++){
            if(used[g[ans.back()][i]]==0){
                ans.push_back(g[ans.back()][i]);
                used[ans.back()]=1;
                break;
            }
        }
        for(int i=0;i<g[ans.front()].size();i++){
            flag*=used[g[ans.front()][i]];
        }
        for(int i=0;i<g[ans.back()].size();i++){
            flag*=used[g[ans.back()][i]];
        }
    }
    printf("%ld\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}