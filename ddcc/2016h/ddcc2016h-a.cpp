#include<cstdio>
using namespace std;
int main(){
    int r,c,ans=0,cnt=0;
    scanf("%d %d",&r,&c);
    for(int i=0;i<=r;i+=c){
        for(int j=0;j<=r;j+=c){
            if(i*i+j*j<=r*r&&(i+c)*(i+c)+j*j<=r*r&&i*i+(j+c)*(j+c)<=r*r&&(i+c)*(i+c)+(j+c)*(j+c)<=r*r){
                ans++;
            }
        }
    }
    printf("%d\n",4*ans);
}