#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,c1=0,c2=0;
    char s[100010];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(i%2){
            if(s[i]=='0'){
                c1++;
            }
            else{
                c2++;
            }
        }
        else{
            if(s[i]=='0'){
                c2++;
            }
            else{
                c1++;
            }
        }
    }
    printf("%d\n",min(c1,c2));
}