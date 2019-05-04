#include<cstdio>
using namespace std;
int main(){
    int n,v[20],c[20],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        if(v[i]>c[i]){
            ans+=v[i]-c[i];
        }
    }
    printf("%d\n",ans);
}