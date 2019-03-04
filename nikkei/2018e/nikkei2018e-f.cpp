#include<cstdio>
using namespace std;
int main(){
    int p;
    long long ans=1789997546303;
    scanf("%d",&p);
    if(p){
        for(int i=1000;i>=p;i--){
            if(i==p){
                printf("%lld\n",ans);
            }
            if(ans%2==1){
                ans=ans*3+1;
            }
            else{
                ans/=2;
            }
        }
    }
    else{
        printf("1\n");
    }
}