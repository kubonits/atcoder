#include<cstdio>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a*d==b*c){
        printf("DRAW\n");
    }
    else if(a*d>b*c){
        printf("AOKI\n");
    }
    else{
        printf("TAKAHASHI\n");
    }
}