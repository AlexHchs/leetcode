#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
    char str1[2] = {'a', 'b'}, str2[2] = {'a'};
    char* ptr = str1+2;
    char jud;

    jud = (*ptr == '\0') ? 't' : 'f';

    printf("Output: str1 = %c", jud);

    

    return 0;
}
