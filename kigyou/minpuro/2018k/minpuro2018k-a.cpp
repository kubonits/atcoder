#include<cstdio>
#include<vector>
using namespace std;
int n,m,a,b[100001]={},sosuu[100001]={},c[100001]={},ans,z,d,cnt;
vector<int> x[100001],y[100001];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=2;i<=100000;i++){
        sosuu[i]=1;
    }
    for(int i=2;i<=100000;i++){
        if(sosuu[i]){
            x[i].push_back(i);
            for(int j=2*i;j<=100000;j+=i){
                sosuu[j]=0;
                x[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        b[a]++;
    }
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            c[i]+=b[j];
        }
    }
    for(int i=1;i<=m;i++){
        ans=0;
        z=(1<<(x[i].size()));
        for(int j=0;j<z;j++){
            cnt=0;
            d=1;
            for(int k=0;k<x[i].size();k++){
                if(j&(1<<k)){
                    cnt++;
                    d*=x[i][k];
                }
            }
            if(cnt%2==0){
                ans+=c[d];
            }
            else{
                ans-=c[d];
            }
        }
        printf("%d\n",ans);
    }
}