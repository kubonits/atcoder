#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,l,r,mini,maxi;
    scanf("%d %d",&n,&m);
    mini=1;
    maxi=n;
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        mini=max(mini,l);
        maxi=min(maxi,r);
    }
    if(mini<=maxi){
        printf("%d\n",maxi-mini+1);
    }
    else{
        printf("0\n");
    }
}