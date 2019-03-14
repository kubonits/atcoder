#include<cstdio>
using namespace std;
int main(){
    int k,cnt1=0,cnt2=0;
    scanf("%d",&k);
    for(int i=-100;i<100;i+=k){
        for(int j=-100;j<100;j+=k){
            if(i*i+j*j<=100*100&&(i+k)*(i+k)+j*j<=100*100&&i*i+(j+k)*(j+k)<=100*100&&(i+k)*(i+k)+(j+k)*(j+k)<=100*100){
                cnt1++;
            }
        }
    }
    for(int i=-150;i<150;i+=k){
        for(int j=-150;j<150;j+=k){
            if(i*i+j*j<=150*150&&(i+k)*(i+k)+j*j<=150*150&&i*i+(j+k)*(j+k)<=150*150&&(i+k)*(i+k)+(j+k)*(j+k)<=150*150){
                cnt2++;
            }
        }
    }
    printf("%d %d\n",cnt1,cnt2);
}