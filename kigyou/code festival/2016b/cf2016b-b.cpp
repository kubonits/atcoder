#include<cstdio>
using namespace std;
int main(){
    int n,a,b;
    char s[100010];
    scanf("%d %d %d",&n,&a,&b);
    scanf("%s",s);
    a+=b;
    for(int i=0;i<n;i++){
        if(s[i]=='a'&&a){
            printf("Yes\n");
            a--;
        }
        else if(s[i]=='b'&&a&&b){
            printf("Yes\n");
            a--;
            b--;
        }
        else{
            printf("No\n");
        }
    }
}