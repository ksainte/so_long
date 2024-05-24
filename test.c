#include"stdio.h"

int main(){
    char s[3] = "abcd";
    int i = 0;
    while(s[i] != '\0'){
         printf("%c",s[i]);
        i++;
    }
    return(0);
}