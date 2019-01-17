#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int n,a[100000],g,m,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    m=g=a[0];
    for(int i=1;i<n;i++){
        m=max(m,a[i]);
        g=gcd(g,a[i]);
    }
    if(m>=k&&(m-k)%g==0){
        printf("POSSIBLE\n");
    }
    else{
        printf("IMPOSSIBLE\n");
    }
}