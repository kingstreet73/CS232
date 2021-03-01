#include <stdio.h>

int main(int argc, char *argv[]) {

   char str[10090];
   int ch, n = 0;

   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      ++n;
   }

   for (int i = 0; i < n; ++i){
      if('a' <= str[i] && str[i] <= 'z'){
        str[i] += 'A' - 'a';
      }

      putchar(str[i]);
   }

    return 0;
}

