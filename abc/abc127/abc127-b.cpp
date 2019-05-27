#include<cstdio>
using namespace std;
int main(){
    int r,d,x;
    scanf("%d %d %d",&r,&d,&x);
    for(int i=0;i<10;i++){
        x=x*r-d;
        printf("%d\n",x);
    }
}