#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,a,b,d,ans=0;
    char s[10];
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%s %d",s,&d);
        d=max(d,a);
        d=min(d,b);
        if(strcmp(s,"West")==0){
            ans+=d;
        }
        else{
            ans-=d;
        }
    }
    if(ans==0){
        printf("0\n");
    }
    else if(ans>0){
        printf("West %d\n",ans);
    }
    else{
        printf("East %d\n",-ans);
    }
}