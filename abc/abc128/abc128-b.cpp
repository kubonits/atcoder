#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#define mod 1000000007
using namespace std;
int main(){
    int n,p[100],a[100]={},b;
    string s[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>p[i];
    }
    for(int i=0;i<n;i++){
        b=-1;
        for(int j=0;j<n;j++){
            if(a[j]==0&&(b==-1||s[b]>s[j]||(s[b]==s[j]&&p[b]<p[j]))){
                b=j;
            }
        }
        a[b]=1;
        printf("%d\n",b+1);
    }
}