#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<utility>
#include<queue>
#include<set>
using namespace std;

int g[100000];

int dfs(int x){
    if(g[x]==x){
        return x;
    }
    else{
        return x=dfs(g[x]);
    }
}
int main(){
    int n,x,y;
    vector<pair<int,int> > a,b;
    int p=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        a.push_back({x,i});
    }
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        b.push_back({x,i});
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(a[i].first>b[i].first){
            printf("No\n");
            return 0;
        }
    }
    p=0;
    for(int i=0;i<n;i++){
        if(i==p){
            while(p<n&&a[p].first<=b[i].first){
                p++;
            }
            for(int j=i;j<p;j++){
                a[j].first=b[i].first;
                b[j].first=b[i].first;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i].second==b[i].second){
            printf("Yes\n");
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first||b[i].first==b[i-1].first){
            printf("Yes\n");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        g[i]=i;
    }
    for(int i=0;i<n;i++){
        x=dfs(a[i].second);
        y=dfs(b[i].second);
        if(x!=y){
            g[max(x,y)]=g[min(x,y)];
        }
    }
    for(int i=0;i<n;i++){
        x=dfs(i);
        if(x){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}