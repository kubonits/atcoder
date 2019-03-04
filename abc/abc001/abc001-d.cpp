#include<cstdio>
using namespace std;

int f[2000];

int main(){
    int n,l,r;
    char s[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        l=(s[3]-'0')/5;
        l+=(s[2]-'0')*2;
        l+=(s[1]-'0')*12;
        l+=(s[0]-'0')*120;
        r=(s[8]-'0')/5;
        r+=(s[7]-'0')*2;
        r+=(s[6]-'0')*12;
        r+=(s[5]-'0')*120;
        if((s[8]-'0')%5!=0){
            r++;
        }
        l*=2;
        r*=2;
        for(int j=l;j<=r;j++){
            f[j]=1;
        }
    }
    for(int i=0;i<1000;i++){
        if(f[i]==1&&(i==0||f[i-1]==0)){
            printf("%d%d%d%d-",i/240,i%240/24,i%24/4,i%4/2*5);
        }
        else if((f[i]==1&&f[i+1]==0)){
            printf("%d%d%d%d\n",i/240,i%240/24,i%24/4,i%4/2*5);
        }
    }
}