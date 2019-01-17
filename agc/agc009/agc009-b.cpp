#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,p[100001],d[100001];
vector<int> v[100001];

int dfs(int a){
    int s;
    vector<int> e;
    if(v[a].empty()){
        return 0;
    }
    e.reserve(v[a].size());
    int ans=0;
    for(int i=0;i<v[a].size();i++){
        e.push_back(dfs(v[a][i]));
    }
    s=v[a].size();
    sort(e.begin(),e.end());
    for(int i=0;i<s;i++){
        ans=max(ans,e[i]+s-i);
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        v[p[i]].push_back(i);
    }
    printf("%d\n",dfs(1));
}