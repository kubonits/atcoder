#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,l,ans=100000,sum=0;
    scanf("%d %d",&n,&l);
    sum+=n*l;
    for(int i=0;i<n;i++){
        sum+=i;
    }
    for(int i=0;i<n;i++){
        if(abs(ans-sum)>abs(l+i)){
            ans=sum-(l+i);
        }
    }
    printf("%d\n",ans);
}