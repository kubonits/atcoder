#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1000
using namespace std;

int main(){
    int n,dpmi[52][52][53],dpma[52][52][53],K,ans=-INF;
    char s[53];
    scanf("%d",&K);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<=n;k++){
                dpmi[i][j][k]=INF;
                dpma[i][j][k]=-INF;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            dpmi[i][i][0]=s[i]-'0';
            dpma[i][i][0]=s[i]-'0';
        }
        dpmi[i][i][1]=0;
        dpma[i][i][1]=9;
    }
    for(int i=2;i<n;i++){
        if((s[i]=='+'||s[i]=='-')&&s[i-1]>='0'&&s[i-1]<='9'&&s[i-2]>='0'&&s[i-2]<='9'){
            if(s[i]=='+'){
                dpmi[i-2][i][0]=dpma[i-2][i][0]=s[i-2]+s[i-1]-2*'0';
            }
            else{
                dpmi[i-2][i][0]=dpma[i-2][i][0]=s[i-2]-s[i-1];
            }
        }
        for(int j=0;j<=9;j++){
            if(s[i-1]>='0'&&s[i-1]<='9'){
                if(s[i]=='+'){
                    dpma[i-2][i][1]=max(dpma[i-2][i][1],s[i-1]-'0'+j);
                    dpmi[i-2][i][1]=min(dpmi[i-2][i][1],s[i-1]-'0'+j);
                }
                else if(s[i]=='-'){
                    dpma[i-2][i][1]=max(dpma[i-2][i][1],j-s[i-1]+'0');
                    dpmi[i-2][i][1]=min(dpmi[i-2][i][1],j-s[i-1]+'0');
                }
                dpma[i-2][i][2]=max(dpma[i-2][i][2],s[i-1]-'0'+j);
                dpmi[i-2][i][2]=min(dpmi[i-2][i][2],s[i-1]-'0'+j);
                dpma[i-2][i][2]=max(dpma[i-2][i][2],j-s[i-1]+'0');
                dpmi[i-2][i][2]=min(dpmi[i-2][i][2],j-s[i-1]+'0');
            }
            if(s[i-2]>='0'&&s[i-2]<='9'){
                if(s[i]=='+'){
                    dpma[i-2][i][1]=max(dpma[i-2][i][1],s[i-2]-'0'+j);
                    dpmi[i-2][i][1]=min(dpmi[i-2][i][1],s[i-2]-'0'+j);
                }
                else if(s[i]=='-'){
                    dpma[i-2][i][1]=max(dpma[i-2][i][1],s[i-2]-'0'-j);
                    dpmi[i-2][i][1]=min(dpmi[i-2][i][1],s[i-2]-'0'-j);
                }
                dpma[i-2][i][2]=max(dpma[i-2][i][2],s[i-2]-'0'+j);
                dpmi[i-2][i][2]=min(dpmi[i-2][i][2],s[i-2]-'0'+j);
                dpma[i-2][i][2]=max(dpma[i-2][i][2],s[i-2]-'0'-j);
                dpmi[i-2][i][2]=min(dpmi[i-2][i][2],s[i-2]-'0'-j);
            }
        }
        if(s[i-1]>='0'&&s[i-1]<='9'&&s[i-2]>='0'&&s[i-2]<='9'){
            dpma[i-2][i][1]=max(dpma[i-2][i][1],s[i-1]+s[i-2]-2*'0');
            dpmi[i-2][i][1]=min(dpmi[i-2][i][1],s[i-2]-s[i-1]);
        }
        if(s[i]=='+'){
            dpma[i-2][i][2]=max(dpma[i-2][i][2],18);
            dpmi[i-2][i][2]=min(dpmi[i-2][i][2],0);
        }
        if(s[i]=='-'){
            dpma[i-2][i][2]=max(dpma[i-2][i][2],9);
            dpmi[i-2][i][2]=min(dpmi[i-2][i][2],-9);
        }
        dpma[i-2][i][3]=18;
        dpmi[i-2][i][3]=-9;
    }
    for(int i=4;i<n;i++){
        for(int j=0;i+j<n;j++){
            for(int k=0;k<=min(i,K);k++){
                for(int l=j;l<i+j;l+=2){
                    for(int m=0;m<=min(k,l-j+1);m++){
                        if(abs(dpma[j][l][m])<INF&&abs(dpma[l+1][i+j-1][k-m])<INF){
                            dpma[j][i+j][k+1]=max(dpma[j][i+j][k+1],dpma[j][l][m]+dpma[l+1][i+j-1][k-m]);
                            dpmi[j][i+j][k+1]=min(dpmi[j][i+j][k+1],dpmi[j][l][m]+dpmi[l+1][i+j-1][k-m]);
                            dpma[j][i+j][k+1]=max(dpma[j][i+j][k+1],dpma[j][l][m]-dpmi[l+1][i+j-1][k-m]);
                            dpmi[j][i+j][k+1]=min(dpmi[j][i+j][k+1],dpmi[j][l][m]-dpma[l+1][i+j-1][k-m]);
                            if(s[i+j]=='+'){
                                dpma[j][i+j][k]=max(dpma[j][i+j][k],dpma[j][l][m]+dpma[l+1][i+j-1][k-m]);
                                dpmi[j][i+j][k]=min(dpmi[j][i+j][k],dpmi[j][l][m]+dpmi[l+1][i+j-1][k-m]);
                            }
                            if(s[i+j]=='-'){
                                dpma[j][i+j][k]=max(dpma[j][i+j][k],dpma[j][l][m]-dpmi[l+1][i+j-1][k-m]);
                                dpmi[j][i+j][k]=min(dpmi[j][i+j][k],dpmi[j][l][m]-dpma[l+1][i+j-1][k-m]);
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<=K;i++){
        ans=max(ans,dpma[0][n-1][i]);
    }
    if(ans==-INF){
        printf("NG\n");
    }
    else{
        printf("OK\n");
        printf("%d\n",ans);
    }
}