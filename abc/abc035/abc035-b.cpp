#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int h=0,w=0,t,n,cnt=0,ans=0;
    char s[100010];
    scanf("%s",s);
    scanf("%d",&t);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='U'){
            h++;
        }
        else if(s[i]=='D'){
            h--;
        }
        else if(s[i]=='R'){
            w++;
        }
        else if(s[i]=='L'){
            w--;
        }
        else{
            cnt++;
        }
    }
    if(h>0){
        ans+=h;
    }
    else{
        ans-=h;
    }
    if(w>0){
        ans+=w;
    }
    else{
        ans-=w;
    }
    if(t==1){
        printf("%d\n",ans+cnt);
    }
    else if(ans>=cnt){
        printf("%d\n",ans-cnt);
    }
    else{
        printf("%d\n",(ans+cnt)%2);
    }
}