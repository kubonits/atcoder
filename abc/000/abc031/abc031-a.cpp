#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,d;
    scanf("%d %d",&a,&d);
    printf("%d\n",max((a+1)*d,a*(d+1)));
}