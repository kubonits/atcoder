#include<cstdio>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int n,ans,a;
    scanf("%d %d",&n,&ans);
    for(int i=1;i<n;i++){
        scanf("%d",&a);
        ans=gcd(a,ans);
    }
    printf("%d\n",ans);
}