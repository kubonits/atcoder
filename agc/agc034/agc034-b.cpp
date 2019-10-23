#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
int main(){
    vector<pair<int,int> > a;
    int n,l,r,flag,flag2;
    long long ans=0;
    char s[200010];
    scanf("%s",s);
    n=strlen(s);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A'){
            a.push_back(make_pair(i,1));
            while(i>=0&&s[i-1]=='A'){
                a.back().second++;
                i--;
            }
        }
    }
    flag=1;
    //while(flag){
        flag=0;
        for(int i=0;i<a.size();i++){
            if(s[a[i].first]=='A'&&s[a[i].first+1]=='B'&&s[a[i].first+2]=='C'){
                s[a[i].first+1-a[i].second]='B';
                s[a[i].first+1+1-a[i].second]='C';
                s[a[i].first+2]='A';
                ans+=a[i].second;
                flag=1;
                a[i].first+=2;
                flag2=1;
                while(flag2){
                    if(a[i].first+2<n&&s[a[i].first+1]=='B'&&s[a[i].first+2]=='C'){
                        s[a[i].first+1-a[i].second]='B';
                        s[a[i].first+1+1-a[i].second]='C';
                        s[a[i].first+2]='A';
                        ans+=a[i].second;
                        flag=1;
                        a[i].first+=2;
                    }
                    else{
                        flag2=0;
                    }
                }
            }
        }
    //}
    printf("%lld\n",ans);
}