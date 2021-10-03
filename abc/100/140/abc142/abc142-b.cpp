#include<cstdio>
using namespace std;
int main(){
    int n,k,h,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h);
        if(h>=k){
            ans++;
        }
    }
    printf("%d\n",ans);
}