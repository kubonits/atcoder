#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[100010];
    long long a[26],b=0,c=0;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        b+=a[i]/2*2;
        c+=a[i]%2;
    }
    if(c){
        c--;
        b++;
    }
    printf("%lld\n",b*b+c);
}