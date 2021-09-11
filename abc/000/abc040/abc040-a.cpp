#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    printf("%d\n",min(x-1,n-x));
}