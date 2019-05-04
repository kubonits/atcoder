#include<cstdio>
using namespace std;
int main(){
    int n,t,a[100000],ans=0,l,r;
    scanf("%d %d",&n,&t);
    scanf("%d",&a[0]);
    l=a[0];
    r=a[0]+t;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=r){
            r=a[i]+t;
        }
        else{
            ans+=r-l;
            l=a[i];
            r=a[i]+t;
        }
    }
    ans+=r-l;
    printf("%d\n",ans);
}