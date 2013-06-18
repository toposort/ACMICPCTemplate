/************************************
求给定字符串中最长回文串的长度
p[i]-1是以str[i]为中心的回文串在原串当中的长度。
*************************************/

#include <string.h>
#include <stdio.h>
#include <iostream>

const int maxn = 1000011<<1;
int n;
char str[maxn];//start from index 1
int p[maxn];
char s[maxn];

void pre(){
    n = strlen(s);
    str[0] = '$';
    str[1] = '#';
    for(int i = 0; i < n; i++){
        str[i*2 + 2] = s[i];
        str[i*2 + 3] = '#';
    }
    n = n*2+2;
    str[n] = 0;
}

void kp(){
    int mx = 0, id;
    for(int i = 1; i < n; i++){
        if(mx > i) p[i] = std::min(p[2*id-i], p[id]+id-i);
        else p[i] = 1;
        while(str[i+p[i]] == str[i-p[i]]) p[i]++;
        if(p[i]+i > mx){
            mx = p[i]+i;
            id = i;
        }
    }
}

int main(){
    scanf("%s", s);
    pre();
    kp();
}
