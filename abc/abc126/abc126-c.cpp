#include<cstdio>
using namespace std;
int main(){
    int n,k,b;
    double ans=0.0,a;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        a=1.0;
        b=i;
        while(b<k){
            b*=2;
            a/=2.0;
        }
        ans+=a;
    }
    printf("%.11f\n",ans/(double)n);
}