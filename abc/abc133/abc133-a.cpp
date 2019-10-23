#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d\n",min(a*n,b));
}