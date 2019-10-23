#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
#define mod 1331

int a[6][8][8],v[8],v2[8];

int main(){
    int n;
    map<char,int> m;
    for(int i=0;i<8;i++){
        v[i]=i+1;
    }
    char s[50];
    scanf("%s",s);
    n=strlen(s);
    m.insert(make_pair('U',0));
    m.insert(make_pair('D',1));
    m.insert(make_pair('L',2));
    m.insert(make_pair('R',3));
    m.insert(make_pair('F',4));
    m.insert(make_pair('B',5));
    a[0][0][3]=1;
    a[0][1][0]=1;
    a[0][2][1]=1;
    a[0][3][2]=1;
    a[1][4][7]=1;
    a[1][5][4]=1;
    a[1][6][5]=1;
    a[1][7][6]=1;
    a[2][1][2]=11;
    a[2][6][1]=121;
    a[2][5][6]=11;
    a[2][2][5]=121;
    a[3][0][7]=121;
    a[3][3][0]=11;
    a[3][4][3]=11;
    a[3][7][4]=121;
    a[4][0][1]=11;
    a[4][7][0]=11;
    a[4][6][7]=121;
    a[4][1][6]=121;
    a[5][2][3]=121;
    a[5][5][2]=11;
    a[5][4][5]=121;
    a[5][3][4]=11;
    a[0][4][4]=1;
    a[0][5][5]=1;
    a[0][6][6]=1;
    a[0][7][7]=1;
    a[1][0][0]=1;
    a[1][1][1]=1;
    a[1][2][2]=1;
    a[1][3][3]=1;
    a[2][0][0]=1;
    a[2][3][3]=1;
    a[2][4][4]=1;
    a[2][7][7]=1;
    a[3][6][6]=1;
    a[3][1][1]=1;
    a[3][2][2]=1;
    a[3][5][5]=1;
    a[4][2][2]=1;
    a[4][5][5]=1;
    a[4][4][4]=1;
    a[4][3][3]=1;
    a[5][0][0]=1;
    a[5][7][7]=1;
    a[5][6][6]=1;
    a[5][1][1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<8;j++){
            v2[j]=0;
            for(int k=0;k<8;k++){
                v2[j]+=a[m[s[i]]][j][k]*v[k];
            }
        }
        for(int j=0;j<8;j++){
            v[j]=v2[j];
            if(v[j]%mod==0){
                v[j]/=mod;
            }
        }
    }
    for(int i=0;i<8;i++){
        if(v[i]%121==0){
            printf("%d ",v[i]/121);
        }
        else if(v[i]%11==0){
            printf("%d ",v[i]/11);
        }
        else{
            printf("%d ",v[i]);
        }
    }
    printf("\n");
    for(int i=0;i<8;i++){
        if(v[i]%121==0){
            printf("2 ");
        }
        else if(v[i]%11==0){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
}