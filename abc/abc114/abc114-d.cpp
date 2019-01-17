#include<cstdio>
using namespace std;

int box[101];

int main(){
    int n,a,ans=0;;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a=i;
        for(int j=2;j<=n;j++){
            while(a%j==0){
                box[j]++;
                a/=j;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(box[i]>=74){
            ans++;
        }
        for(int j=i+1;j<=n;j++){
            if(box[i]>=14&&box[j]>=4){
                ans++;
            }
            if(box[i]>4&&box[j]>=14){
                ans++;
            }
            if(box[i]>=24&&box[j]>=2){
                ans++;
            }
            if(box[i]>=2&&box[j]>=24){
                ans++;
            }
            for(int k=j+1;k<=n;k++){
                if(box[i]>=4&&box[j]>=4&&box[k]>=2){
                    ans++;
                }
                if(box[i]>=4&&box[j]>=2&&box[k]>=4){
                    ans++;
                }
                if(box[i]>=2&&box[j]>=4&&box[k]>=4){
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
}