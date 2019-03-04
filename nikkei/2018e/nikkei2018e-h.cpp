#include<cstdio>
using namespace std;
int main(){
    long long n,e[20]={},b[20],c;
    int a[500]={};
    scanf("%lld",&n);
    n%=9;
    if(n==8||n%2==1){
        printf("Win\n");
    }
    else{
        printf("Lose\n");
    }
}