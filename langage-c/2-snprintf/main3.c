#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int main(){
    size_t max_length_cmdbash = 100;
    char command_bash[max_length_cmdbash];
    char *text = "Tsitohaina";

    int j = snprintf(command_bash,max_length_cmdbash,"./cmd.sh \"%s\" ",text);
    assert(j < max_length_cmdbash);
    system(command_bash);
    return 0;
}