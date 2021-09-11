#include<cstdio>
using namespace std;
int main(){
    int n,p,a,b,k,x[101]={};
    scanf("%d",&n);
    scanf("%d %d",&a,&b);
    x[a]=1;
    x[b]=1;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&p);
        if(x[p]){
            printf("NO\n");
            return 0;
        }
        x[p]=1;
    }
    printf("YES\n");
}