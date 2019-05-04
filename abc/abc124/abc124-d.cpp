#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int n,k,ans=0;
    vector<int> l,r;
    char s[100010];
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    l.push_back(0);
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            l.push_back(i);
            r.push_back(i-1);
        }
    }
    if(l.size()!=r.size()){
        r.push_back(n-1);
    }
    r.push_back(n-1);
    r.push_back(n-1);
    r.push_back(n-1);
    r.push_back(n-1);
    if((l.size()<=2*k)||(l.size()==2*k+1&&s[0]=='1')){
        printf("%d\n",n);
        return 0;
    }
    for(int i=0;i<l.size()-2*k+1;i++){
        if(s[l[i]]=='1'){
            ans=max(ans,r[i+2*k]-l[i]+1);
        }
        else{
            ans=max(ans,r[i+2*k-1]-l[i]+1);
        }
    }
    printf("%d\n",ans);
}