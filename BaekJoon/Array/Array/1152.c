#include <stdio.h>
#include <string.h>

int main() {
   char arr[1000000];
   int ret = 0;
   gets(arr);
   
   char* tok = strtok(arr, " ");
   while (tok != NULL) {
       if(tok[0]!=' '){
        tok = strtok(NULL, " ");
        ret++;
       }
   }
   printf("%d\n", ret);

   return 0;
}