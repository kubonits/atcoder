#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int r,g,b,n,ans=0;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    for(int i=0;i*r<=n;i++){
        for(int j=0;j*g+i*r<=n;j++){
            if((n-i*r-j*g)%b==0){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}