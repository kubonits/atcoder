#include<cstdio>
using namespace std;
int main(){
    int n,h,w,a,b,ans=0;
    scanf("%d %d %d",&n,&h,&w);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        if(a>=h&&b>=w){
            ans++;
        }
    }
    printf("%d\n",ans);
}