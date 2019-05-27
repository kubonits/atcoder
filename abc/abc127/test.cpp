#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[10000],b[10000],ans;
void dfs(int x,int y,int z){
    printf("%d %d %d\n",x,y,z);
    if(z==k){
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                ans+=max(a[i],a[j])-min(a[i],a[j])+max(b[i],b[j])-min(b[i],b[j]);
            }
        }
    }
    else{
        if(y==m){
            y=0;
            x++;
        }
        if(x==n){
            return ;
        }
        a[z]=x;
        b[z]=y;
        dfs(x,y+1,z+1);
        dfs(x,y+1,z);
    }
}
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    //dfs(0,0,0);
    printf("%d\n",ans);
}