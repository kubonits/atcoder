#include<cstdio>
using namespace std;
int main(){
    int t,a,b,c,d;
    scanf("%d %d %d %d %d",&t,&a,&b,&c,&d);
    if(a+c<=t){
        printf("%d\n",b+d);
    }
    else if(c<=t){
        printf("%d\n",d);
    }
    else if(a<=t){
        printf("%d\n",b);
    }
    else{
        printf("0\n");
    }
}