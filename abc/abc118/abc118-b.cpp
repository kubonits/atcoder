#include<cstdio>
using namespace std;
int main(){
    int n,m,g[30][30]={},k,a,cnt=0,f;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&a);
            g[i][a-1]=1;
        }
    }
    for(int i=0;i<m;i++){
        f=1;
        for(int j=0;j<n;j++){
            f*=g[j][i];
        }
        cnt+=f;
    }
    printf("%d\n",cnt);
}