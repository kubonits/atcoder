#include<cstdio>
using namespace std;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b<10){
        a*=10;
    }
    else if(b<100){
        a*=100;
    }
    else{
        a*=1000;
    }
    a+=b;
    printf("%d\n",a*2);
}