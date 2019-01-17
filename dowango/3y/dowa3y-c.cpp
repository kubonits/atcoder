#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a,c[4]={},ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        c[a-1]++;
    }
    ans=c[3];
    ans+=c[2];
    c[0]-=min(c[0],c[2]);
    ans+=c[1]/2;
    c[1]%=2;
    if(c[1]){
        ans+=1;
        c[0]-=min(c[0],2);
    }
    ans+=c[0]/4;
    c[0]%=4;
    if(c[0]){
        ans++;
    }
    printf("%d\n",ans);
}