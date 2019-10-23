#include<cstdio>
using namespace std;
int main(){
    int n,cnt=0,x=1,ten[10];
    scanf("%d",&n);
    ten[0]=1;
    for(int i=1;i<=9;i++){
        ten[i]=ten[i-1]*10;
    }
    for(int i=0;i<9;i++){
        cnt+=n/ten[i+1]*ten[i];
        x=n%ten[i+1];
        if(1<x/ten[i]){
            cnt+=ten[i];
        }
        else if(x/ten[i]){
            if(!i){
                cnt++;
            }
            else{
                cnt+=x%ten[i]+1;
            }
        }
    }
    printf("%d\n",cnt);
}