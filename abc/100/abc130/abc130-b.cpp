#include<cstdio>
using namespace std;
int main(){
    int n,l,x,d=0,ans=1;
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&l);
        if(d+l<=x){
            ans++;
        }
        d+=l;
    }
    printf("%d\n",ans);
}