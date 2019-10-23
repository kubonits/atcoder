#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#include<map>
using namespace std;

int main(){
    int n,a,b[300010]={},maxi=0;;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        b[a]--;
    }
    sort(b,b+n+1);
    for(int i=0;i<=n;i++){
        b[i]*=-1;
    }
    int p=0,x=n,y,z=n;
    a=n;
    for(int i=1;i<=n;i++){
        do{
            y=x/i;
            a=x;
            if(z!=y){
                x-=(z-y)*p;
                z=y;
            }
            while(b[p]>y){
                x-=b[p]-y;
                p++;
            }
        }while(a!=x);
        printf("%d\n",y);
    }
}