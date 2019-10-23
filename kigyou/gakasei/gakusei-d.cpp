#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<deque>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int n,a[510][510];

void dfs(vector<int> v , int x){
    if(v.size()==1||v.size()==0){
        return ;
    }
    vector<int> v1,v2;
    for(int i=0;i<v.size();i++){
        if(i%2){
            v1.push_back(v[i]);
        }
        else{
            v2.push_back(v[i]);
        }
    }
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            a[min(v1[i],v2[j])][max(v1[i],v2[j])]=x;
        }
    }
    dfs(v1,x+1);
    dfs(v2,x+1);
}

int main(){
    scanf("%d",&n);
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    dfs(v,1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}