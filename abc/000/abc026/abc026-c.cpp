#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[21];
vector<int> childe[21];

int dfs(int n){
    int res=0,mini,maxi;
    if(childe[n].empty()){
        return 1;
    }
    a[childe[n][0]]=dfs(childe[n][0]);
    mini=maxi=a[childe[n][0]];
    for(int i=1;i<childe[n].size();i++){
        a[childe[n][i]]=dfs(childe[n][i]);
        mini=min(mini,a[childe[n][i]]);
        maxi=max(maxi,a[childe[n][i]]);
    }
    return mini+maxi+1;
}
int main(){
    int n,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&b);
        childe[b].push_back(i+1);
    }
    printf("%d\n",dfs(1));
}