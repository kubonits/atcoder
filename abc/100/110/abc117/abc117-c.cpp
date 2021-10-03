#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,x[100000],sa[100000],ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x[i]);
    }
    sort(x,x+m);
    for(int i=0;i<m-1;i++){
        sa[i]=x[i+1]-x[i];
    }
    if(m-1>0){
        sort(sa,sa+m-1);
        for(int i=0;i<m-n;i++){
            ans+=sa[i];
        }
    }
    printf("%d\n",ans);
}