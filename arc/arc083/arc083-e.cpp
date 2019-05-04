#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,tdp[1001],x[1001];
vector<int> childe[1001];

bool dfs(int v){
    bool res;
    int mini=0,sa,ndp[5001]={},sum=0;
    res=true;
    for(int i=0;i<childe[v].size();i++){
        res=dfs(childe[v][i]);
        if(!res){
            return res;
        }
    }
    for(int i=0;i<childe[v].size();i++){
        mini+=min(x[childe[v][i]],tdp[childe[v][i]]);
        sum+=x[childe[v][i]]+tdp[childe[v][i]];
    }
    if(mini>x[v]){
        return false;
    }
    ndp[mini]=1;
    for(int i=0;i<childe[v].size();i++){
        sa=max(x[childe[v][i]],tdp[childe[v][i]])-min(x[childe[v][i]],tdp[childe[v][i]]);
        for(int j=x[v];j>=0;j--){
            if(ndp[j]&&j+sa<=x[v]){
                ndp[j+sa]=1;
            }
        }
    }
    for(int i=x[v];i>=0;i--){
        if(ndp[i]){
            tdp[v]=sum-i;
            return true;
        }
    }
    return true;
}

int main(){
    int p;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&p);
        childe[p].push_back(i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&x[i+1]);
    }
    if(dfs(1)){
        printf("POSSIBLE\n");
    }
    else{
        printf("IMPOSSIBLE\n");
    }
}