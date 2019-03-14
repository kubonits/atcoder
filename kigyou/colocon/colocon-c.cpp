#include<cstdio>
using namespace std;

long gcd(long a,long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int g[36][36]={},f[36];

long dfs(long x,long y){
    if(x>y){
        return (long)1;
    }
    int flag=1;
    long ans=0;
    for(long i=0;i<x;i++){
        if(f[i]&&!g[i][x]){
            flag=0;
        }
    }
    if(flag){
        f[x]=1;
        ans+=dfs(x+1,y);
    }
    f[x]=0;
    return ans+dfs(x+1,y);
}
int main(){
    long a,b;
    scanf("%ld %ld",&a,&b);
    for(long i=0;i<=b-a;i++){
        for(long j=i+1;j<=b-a;j++){
            if(gcd(i+a,j+a)==1){
                g[i][j]=1;
            }
        }
    }
    printf("%ld\n",dfs((long)0,b-a));
}