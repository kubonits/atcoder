#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    long n,ans=0;
    vector<long> w;
    char s[200010];
    scanf("%s",s);
    n=strlen(s);
    for(long i=0;i<n;i++){
        if(s[i]=='W'){
            w.push_back(i);
        }
    }
    for(long i=0;i<w.size();i++){
        ans+=w[i]-i;
    }
    printf("%ld\n",ans);
}