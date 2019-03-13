#include<cstdio>
using namespace std;
int main(){
    int n,c[100],a[100]={};
    double ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j&&c[i]%c[j]==0){
                a[i]++;
            }
        }
        if(a[i]%2==1){
            ans+=0.5;
        }
        else{
            ans+=(double)(a[i]/2+1)/(1+a[i]);
        }
    }
    printf("%.7f\n",ans);
}