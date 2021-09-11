#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",max(0,a-2*b));
}