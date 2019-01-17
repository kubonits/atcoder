#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100000],mina,maxa,cnt=0;
    scanf("%d",&n);
    mina=n;
    maxa=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        mina=min(mina,a[i]);
        maxa=max(maxa,a[i]);
    }
    if(mina+1<maxa){
        printf("No\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i]==mina&&mina!=maxa){
            cnt++;
        }
    }
    if(mina==maxa&&(mina==n-1||n>=mina*2)){
        printf("Yes\n");
        return 0;
    }
    if(cnt>=maxa||n-cnt<2*(maxa-cnt)){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}