#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#define mod 1000000007
using namespace std;
int main(){
    int n,d[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    sort(d,d+n);
    printf("%d\n",d[n/2]-d[n/2-1]);
}