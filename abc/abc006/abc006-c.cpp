#include<cstdio>
using namespace std;
int main(){
    int n,m,x,y,z;
    scanf("%d %d",&n,&m);
    m-=2*n;
    if(0<=m&&m<=2*n){
        z=m/2;
        y=m%2;
        x=n-y-z;
        printf("%d %d %d\n",x,y,z);
    }
    else{
        printf("-1 -1 -1\n");
    }
}