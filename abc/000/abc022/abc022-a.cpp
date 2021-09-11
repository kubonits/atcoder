#include<cstdio>
using namespace std;
int main(){
    int n,s,t,w,cnt=0,a;
    scanf("%d %d %d",&n,&s,&t);
    scanf("%d",&w);
    if(w<=t&&s<=w){
        cnt++;
    }
    for(int i=1;i<n;i++){
        scanf("%d",&a);
        w+=a;
        if(s<=w&&w<=t){
            cnt++;
        }
    }
    printf("%d\n",cnt);
}