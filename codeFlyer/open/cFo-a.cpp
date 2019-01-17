#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,ans=10,p,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        a=0;
        while(p%10==0){
            a++;
            p/=10;
        }
        ans=min(a,ans);
    }
    printf("%d\n",ans);
}