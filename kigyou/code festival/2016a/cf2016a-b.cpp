#include<cstdio>
using namespace std;
int main(){
    int n,a[100001],ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(i==a[a[i]]){
            ans++;
        }
    }
    printf("%d\n",ans/2);
}