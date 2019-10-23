#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    long long a=0,ans=0;
    char s[100010];
    vector<int> v;
    scanf("%s",s);
    n=strlen(s);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='+'){
            a++;
        }
        else if(s[i]=='-'){
            a--;
        }
        else{
            v.push_back(a);
        }
    }
    sort(v.begin(),v.end());
    a=v.size();
    for(int i=0;i<a;i++){
        if(i<a/2){
            ans-=v[i];
        }
        else{
            ans+=v[i];
        }
    }
    printf("%lld\n",ans);
}