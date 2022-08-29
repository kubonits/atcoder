#include<cstdio>
#include<vector>
#include<map>
using namespace std;

int d[200001],t[200001];
vector<int> vd[200001],vt[200001];

void dfsd(int x,int y){
    d[x]=y;
    for(int i=0;i<vd[x].size();i++){
        if(d[vd[x][i]]==0){
            dfsd(vd[x][i],y);
        }
    }
}

void dfst(int x,int y){
    t[x]=y;
    for(int i=0;i<vt[x].size();i++){
        if(t[vt[x][i]]==0){
            dfst(vt[x][i],y);
        }
    }
}
int main(){
    int n,l,k,p,q,s,r;
    map<long,int> m;
    long x;
    scanf("%d %d %d",&n,&k,&l);
    for(int i=0;i<k;i++){
        scanf("%d %d",&p,&q);
        vd[p].push_back(q);
        vd[q].push_back(p);
    }
    for(int i=0;i<l;i++){
        scanf("%d %d",&r,&s);
        vt[s].push_back(r);
        vt[r].push_back(s);
    }
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            dfsd(i,i);
        }
        if(t[i]==0){
            dfst(i,i);
        }
    }
    for(int i=1;i<=n;i++){
        x=(long)((long)(n+1)*(long)d[i]+(long)t[i]);
        decltype(m)::iterator it = m.find(x);
        if(it!=m.end()){
            m[x]++;
        }
        else{
            m.insert(make_pair(x,1));
        }
    }
    for(int i=1;i<=n;i++){
        printf("%ld ",m[(long)((long)(n+1)*(long)d[i]+(long)t[i])]);
    }
    printf("\n");
}