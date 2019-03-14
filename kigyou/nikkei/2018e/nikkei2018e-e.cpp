#include<cstdio>
using namespace std;
int main(){
    int n,f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        f=0;
        if(i%2==0){
            f=1;
            printf("a");
        }
        if(i%3==0){
            f=1;
            printf("b");
        }
        if(i%4==0){
            f=1;
            printf("c");
        }
        if(i%5==0){
            f=1;
            printf("d");
        }
        if(i%6==0){
            f=1;
            printf("e");
        }
        if(!f){
            printf("%d",i);
        }
        printf("\n");
    }
}