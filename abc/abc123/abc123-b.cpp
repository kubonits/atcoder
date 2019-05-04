#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a[5],sum=0,x,ans;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(a[i]%10==0){
            sum+=a[i];
        }
        else{
            sum+=a[i]/10*10+10;
        }
    }
    ans=sum;
    for(int i=0;i<5;i++){
        if(a[i]%10){
            ans=min(ans,sum-a[i]/10*10-10+a[i]);
        }
    }
    printf("%d\n",ans);
}