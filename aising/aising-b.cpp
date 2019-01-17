#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a,b,x=0,y=0,z=0,p;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        if(p<=a){
            x++;
        }
        else if(p<=b){
            y++;
        }
        else{
            z++;
        }
    }
    int ans=min(x,y);
    printf("%d\n",min(ans,z));
}