#include<cstdio>
using namespace std;
int main(){
    int n,h,w;
    scanf("%d%d%d",&n,&h,&w);
    printf("%d\n",(n-w+1)*(n-h+1));
}