#include<cstdio>
using namespace std;
int main(){
    int n,q,p1,p2,p,l,r,mid;
    char s[200010],d[200000][3],t[200000][3];
    scanf("%d %d",&n,&q);
    scanf("%s",s);
    for(int i=0;i<q;i++){
        scanf("%s %s",t[i],d[i]);
    }
    p1=-1;
    p2=n;
    l=0;
    r=n-1;
    while(l<=r){
        mid=(l+r)/2;
        p=mid;
        for(int i=0;i<q;i++){
            if(p!=-1&&p!=n&&t[i][0]==s[p]){
                if(d[i][0]=='R'){
                    p++;
                }
                else{
                    p--;
                }
            }
        }
        if(p==-1){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    p1=r;
    l=0;
    r=n-1;
    while(l<=r){
        mid=(l+r)/2;
        p=mid;
        for(int i=0;i<q;i++){
            if(p!=-1&&p!=n&&t[i][0]==s[p]){
                if(d[i][0]=='R'){
                    p++;
                }
                else{
                    p--;
                }
            }
        }
        if(p==n){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    p2=l;
    if(p1>=p2){
        printf("0\n");
    }
    else{
        printf("%d\n",n-(p1+1)-(n-p2));
    }
}