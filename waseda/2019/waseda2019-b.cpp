#include<cstdio>
#include<algorithm>
using namespace std;
int h,w,a[100][100],f=0,ans=1000000,s[10]={0,0,0,0,0,0,1,1,2,3},x,score;
int cnt;


int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]){
                f=1;
            }
        }
    }
    if(f==0){
        printf("Yes 0\n");
        return 0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]==5){
                cnt++;
                f=0;
            }
        }
    }
    if(f){
        printf("No\n");
        return 0;
    }
    if(min(h,w)>1){
        int maxa=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                maxa=max(maxa,a[i][j]);
            }
        }
        printf("Yes %d\n",s[maxa]+1);
    }
    else if(h>1){
        int maxa[2][100]={};
        maxa[0][0]=a[0][0];
        maxa[1][h-1]=a[h-1][0];
        for(int i=1;i<h;i++){
            maxa[0][i]=max(maxa[0][i-1],a[i][0]);
        }
        for(int i=h-2;i>=0;i--){
            maxa[1][i]=max(maxa[1][i+1],a[i][0]);
        }
        for(int i=0;i<h;i++){
            if(a[i][0]==5)
            ans=min(ans,1+s[maxa[0][i]]+s[maxa[1][i]]);
        }
        printf("Yes %d\n",ans);
    }
    else{
        int maxa[2][100]={};
        maxa[0][0]=a[0][0];
        maxa[1][w-1]=a[0][w-1];
        for(int i=1;i<w;i++){
            maxa[0][i]=max(maxa[0][i-1],a[0][i]);
        }
        for(int i=w-2;i>=0;i--){
            maxa[1][i]=max(maxa[1][i+1],a[0][i]);
        }
        for(int i=0;i<w;i++){
            if(a[0][i]==5)
            ans=min(ans,1+s[maxa[0][i]]+s[maxa[1][i]]);
        }
        printf("Yes %d\n",ans);
    }
}