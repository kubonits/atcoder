#include<cstdio>
#include<cmath>
int gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}

int main(){
    int n,a[10001],g,cnt=0,flag=0,sosuu[100000]={},x,sum;
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        scanf("%d",&a[i]);
        if(a[i]%2){
            cnt++;
        }
        sum+=a[i];
    }
    for(int i=n;i>=0;i--){
        if(a[i]){
            g=a[i];
            break;
        }
    }
    if(g<0){
        g*=-1;
    }
    for(int i=0;i<n;i++){
        if(a[i]<0){
            x=-a[i];
        }
        else{
            x=a[i];
        }
        g=gcd(g,x);
    }
    for(int i=2;i<=sqrt(g);i++){
        sosuu[i]=1;
    }
    for(int i=2;i<=sqrt(g);i++){
        if(sosuu[i]){
            for(int j=i*i;j<=sqrt(g);j+=i){
                sosuu[j]=0;
            }
        }
    }
    if(g%2==0||(cnt%2==0&&a[n]%2==0)){
        printf("2\n");
    }
    if(g==1){
        return 0;
    }
    if(g%2==0){
        flag=1;
    }
    for(int i=3;i<=sqrt(g);i++){
        if(g%i==0){
            printf("%d\n",i);
            flag=1;
        }
    }
    if(flag==0){
        printf("%d\n",g);
    }
}