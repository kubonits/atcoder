#include<cstdio>
using namespace std;
int main(){
    int n,x[100010]={},a,b,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        x[a]++;
        x[b]++;
    }
    for(int i=1;i<=n;i++){
        if(x[i]%2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}