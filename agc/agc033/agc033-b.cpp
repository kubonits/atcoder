#include<cstdio>
#include<algorithm>
using namespace std;
int dpu[200001],dpd[200001],dpr[200001],dpl[200001],h,w,n,sr,sc;
char s[200010],t[200010];
int main(){
    int flag=0;
    scanf("%d %d %d",&h,&w,&n);
    scanf("%d %d",&sr,&sc);
    scanf("%s",s);
    scanf("%s",t);
    dpr[n]=w+1;
    dpl[n]=0;
    dpu[n]=0;
    dpd[n]=h+1;
    for(int i=n-1;i>=0;i--){
        if(t[i]=='L'){
            dpr[i]=dpr[i+1]+1;
        }
        else{
            dpr[i]=dpr[i+1];
        }
        if(s[i]=='R'){
            dpr[i]=min(w,dpr[i]-1);
        }
        else{
            dpr[i]=min(w+1,dpr[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(t[i]=='R'){
            dpl[i]=dpl[i+1]-1;
        }
        else{
            dpl[i]=dpl[i+1];
        }
        if(s[i]=='L'){
            dpl[i]=max(1,dpl[i]+1);
        }
        else{
            dpl[i]=max(0,dpl[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(t[i]=='U'){
            dpd[i]=dpd[i+1]+1;
        }
        else{
            dpd[i]=dpd[i+1];
        }
        if(s[i]=='D'){
            dpd[i]=min(h,dpd[i]-1);
        }
        else{
            dpd[i]=min(h+1,dpd[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(t[i]=='D'){
            dpu[i]=dpu[i+1]-1;
        }
        else{
            dpu[i]=dpu[i+1];
        }
        if(s[i]=='U'){
            dpu[i]=max(1,dpu[i]+1);
        }
        else{
            dpu[i]=max(0,dpu[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(dpr[i]-1<=dpl[i]||dpd[i]-1<=dpu[i]){
            flag=1;
        }
    }
    if(dpu[0]>=sr||dpd[0]<=sr||dpr[0]<=sc||dpl[0]>=sc||flag){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}