#include<cstdio>
using namespace std;

int dfs(long long x,int s,int d,long long n){
    if(x>n){
        return s;
    }
    if((s+d)%2){
        return dfs(2*x+1,(s^1),d,n);
    }
    else{
        return dfs(2*x,(s^1),d,n);
    }
}

int main(){
    long long n,m;
    scanf("%lld",&n);
    int d=0;
    m=n;
    while(m>0){
        d++;
        m/=2;
    }
    int a=dfs(1,0,d,n);
    if(a){
        printf("Aoki\n");
    }
    else{
        printf("Takahashi\n");
    }
}