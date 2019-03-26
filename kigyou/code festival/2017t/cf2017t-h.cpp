#include<cstdio>
#include<utility>
#include<vector>
using namespace std;

int n,m,a,b,q,l,r,mid;
vector<pair<int,int> > parent[100001];
vector<int> childe[100001];

void init(){
    for(int i=1;i<=n;i++){
        parent[i].push_back(make_pair(i,0));
    }
}

int main(){
    scanf("%d %d",&n,&m);
    init();
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        a=parent[a].back().first;
        b=parent[b].back().first;
        if(a!=b){
            if(childe[a].size()<childe[b].size()){
                a=a^b;
                b=a^b;
                a=a^b;
            }
            childe[a].push_back(b);
            parent[b].push_back(make_pair(a,i));
            for(int j=0;j<childe[b].size();j++){
                childe[a].push_back(childe[b][j]);
                parent[childe[b][j]].push_back(make_pair(a,i));
            }
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&a,&b);
        if(parent[a].back().first!=parent[b].back().first){
            printf("-1\n");
        }
        else{
            l=0;
            r=m;
            while(l<=r){
                int x,y;
                mid=(l+r)/2;
                for(int j=parent[a].size()-1;j>=0;j--){
                    if(parent[a][j].second<=mid){
                        x=parent[a][j].first;
                        break;
                    }
                }
                for(int j=parent[b].size()-1;j>=0;j--){
                    if(parent[b][j].second<=mid){
                        y=parent[b][j].first;
                        break;
                    }
                }
                if(x==y){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            printf("%d\n",l);
        }
    }
}