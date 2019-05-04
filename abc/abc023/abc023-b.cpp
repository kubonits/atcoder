#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,f=1,ans;
    string s,c;
    cin>>n;
    cin>>s;
    if(n%2==0){
        printf("-1\n");
        return 0;
    }
    ans=n/2;
    if(ans%3==0){
        c="bca";
    }
    else if(ans%3==1){
        c="abc";
    }
    else{
        c="cab";
    }
    for(int i=0;i<n;i++){
        if(s[i]!=c[i%3]){
            ans=-1;
            break;
        }
    }
    cout<<ans<<endl;
}