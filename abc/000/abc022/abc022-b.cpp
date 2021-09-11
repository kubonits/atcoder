#include<cstdio>
using namespace std;
int main(){
    int n,a,x[100001]={},ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        x[a]++;
    }
    for(int i=1;i<=100000;i++){
        if(x[i]){
            ans+=x[i]-1;
        }
    }
    printf("%d\n",ans);
}