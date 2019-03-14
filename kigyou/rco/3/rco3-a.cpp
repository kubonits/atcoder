#include<cstdio>
#include<queue>
#include<cmath>
#include <ctime>
#include <cstdlib>
#include<algorithm>
using namespace std;
int main(){
    int n,ans[200]={},used[200]={},r1,r2,temp;
    double x[200],y[200],g[200][200],dis=0.0,a,b,c;
    srand((unsigned)time(NULL));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    used[0]=1;
    ans[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
            if(ans[i+1]==0&&used[j]==0||(used[j]==0&&g[ans[i]][j]<g[ans[i]][ans[i+1]])){
                ans[i+1]=j;
            }
        }
        used[ans[i+1]]=1;
        dis+=g[ans[i]][ans[i+1]];
    }
    for(int i=0;i<1000000;i++){
        for(int j=1;j<=n;j++){
            c=0.0;
            a=g[ans[j-1]][ans[j%n]]+g[ans[j%n]][ans[(j+1)%n]];
            if(c<a){
                c=a;
                r1=j;
            }
        }
        r2=rand()%n+1;
        a=g[ans[r1-1]][ans[r1%n]]+g[ans[r1%n]][ans[(r1+1)%n]]+g[ans[r2-1]][ans[r2%n]]+g[ans[r2%n]][ans[(r2+1)%n]];
        b=g[ans[r1-1]][ans[r2%n]]+g[ans[r2%n]][ans[(r1+1)%n]]+g[ans[r2-1]][ans[r1%n]]+g[ans[r1%n]][ans[(r2+1)%n]];
        if(a>b){
            temp=ans[r1%n];
            ans[r1%n]=ans[r2%n];
            ans[r2%n]=temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
}