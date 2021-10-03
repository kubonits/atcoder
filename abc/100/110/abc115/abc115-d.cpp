#include<cstdio>
#include<algorithm>
using namespace std;

long a[51],b[51];

long dfs(int n,long k){
    if(n==0&&k>=1){
        return 1;
    }
    else if(k<=1){
        return 0;
    }
    if(k>a[n]/2){
        return (long)1+b[n-1]+dfs(n-1,k-a[n]/2-1);
    }
    else if(k==a[n]/2){
        return b[n-1];
    }
    return dfs(n-1,k-1);
}

int main(){
    int n;
    long k,ans=0;
    scanf("%d %ld",&n,&k);
    a[0]=(long)1;
    b[0]=(long)1;
    for(int i=1;i<=50;i++){
        a[i]=a[i-1]*(long)2+(long)3;
        b[i]=b[i-1]*(long)2+(long)1;
    }
    printf("%ld\n",dfs(n,k));
}