#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
#define mod 1000000007
#define INF 1000000000000000
using namespace std;

int main(){
    int n,p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    n=p;
    p+=q+r;
    n=max(n,q);
    n=max(n,r);
    printf("%d\n",p-n);
}