#include<cstdio>
using namespace std;

int a[1000001];

int main(){
    int n;
    a[1]=0;
    a[2]=0;
    a[3]=1;
    scanf("%d",&n);
    for(int i=4;i<=n;i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10007;
    }
    printf("%d\n",a[n]);
}