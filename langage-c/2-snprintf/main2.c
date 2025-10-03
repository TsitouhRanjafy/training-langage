#include<stdio.h>
#include<assert.h>

int main(){
    int max_len = 61;
    char buffer[max_len];

    char *s1 = "RAMIARANJAFY";
    char *s2 = "Tsitohaina";
    char *s3 = "102";

    int j = snprintf(buffer,max_len,"Mon nom comple est: %s %s, et j'ai %s ans",s1,s2,s3);
    assert(j < max_len);

    puts(buffer);
    return 0;
}