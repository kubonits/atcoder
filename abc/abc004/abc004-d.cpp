#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int r,g,b,ans=1000000000,sr[902]={},sg[902]={},sb[902]={};
    scanf("%d %d %d",&r,&g,&b);
    for(int i=1;i<902;i++){
        sr[i]=sr[i-1]+abs(i-1-450+100);
        sg[i]=sg[i-1]+abs(i-1-450);
        sb[i]=sb[i-1]+abs(i-1-450-100);
    }
    for(int i=1;i<902-(r+g+b)+1;i++){
        for(int j=i+r;j<902-(g+b)+1;j++){
            for(int k=j+g;k<902-b+1;k++){
                ans=min(ans,sr[i+r-1]-sr[i-1]+sg[j+g-1]-sg[j-1]+sb[k+b-1]-sb[k-1]);
            }
        }
    }
    printf("%d\n",ans);
}