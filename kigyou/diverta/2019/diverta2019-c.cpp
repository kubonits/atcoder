#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,ans=0,ca=0,cb=0,score[10000],l,a=0,b=0,c=0;
    char s[10000][11];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        l=strlen(s[i]);
        if(s[i][0]=='B'){
            b++;
        }
        if(s[i][l-1]=='A'){
            a++;
        }
        if(s[i][0]=='B'&&s[i][l-1]=='A'){
            c++;
        }
        for(int j=0;j<l;j++){
            if(s[i][j]=='A'&&s[i][j+1]=='B'){
                ans++;
            }
        }
    }
    if(a==c&&b==c&&c){
        printf("%d\n",ans+c-1);
    }
    else{
        printf("%d\n",ans+min(a,b));
    }
}
