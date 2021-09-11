#include<cstdio>
using namespace std;
int main(){
    int n,temp,x[6];
    for(int i=0;i<6;i++){
        x[i]=i+1;
    }
    scanf("%d",&n);
    n%=30;
    for(int i=0;i<n;i++){
        temp=x[i%5];
        x[i%5]=x[i%5+1];
        x[i%5+1]=temp;
    }
    for(int i=0;i<6;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}