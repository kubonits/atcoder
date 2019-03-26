#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int h,w,a,b,ans=0,x=0,y=0,f[2]={1,1};
    char s[200][201];
    scanf("%d %d %d %d",&h,&w,&a,&b);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h/2;i++){
        for(int j=0;j<w/2;j++){
            if(s[i][j]=='S'&&s[h-1-i][j]=='S'&&s[i][w-1-j]=='S'&&s[h-1-i][w-1-j]=='S'){
                ans+=a+b+max(a,b);
            }
            else{
                if((s[i][j]=='S'&&s[h-1-i][j]=='S')||(s[i][w-1-j]=='S'&&s[h-1-i][w-1-j]=='S')){
                    x+=a;
                }
                if((s[i][j]=='S'&&s[i][w-1-j]=='S')||(s[h-1-i][j]=='S'&&s[h-1-i][w-1-j]=='S')){
                    y+=b;
                }
                if(s[i][j]!=s[h-1-i][j]||s[i][w-1-j]!=s[h-1-i][w-1-j]){
                    f[0]=0;
                }
                if(s[i][j]!=s[i][w-1-j]||s[h-1-i][j]!=s[h-1-i][w-1-j]){
                    f[1]=0;
                }
            }
        }
    }
    f[0]*=a;
    f[1]*=b;
    printf("%d\n",ans+max(x,y)+a+b-f[0]-f[1]);
}