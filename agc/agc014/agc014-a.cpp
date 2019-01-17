#include<cstdio>
using namespace std;
int main(){
    int a,b,c,aa,bb,cc,ans=0;
    scanf("%d %d %d",&a,&b,&c);
    while(a%2==0&&b%2==0&&c%2==0){
        aa=(b+c)/2;
        bb=(a+c)/2;
        cc=(a+b)/2;
        if(a==aa&&b==bb&&c==cc){
            printf("-1\n");
            return 0;
        }
        ans++;
        a=aa;
        b=bb;
        c=cc;
    }
    printf("%d\n",ans);
}