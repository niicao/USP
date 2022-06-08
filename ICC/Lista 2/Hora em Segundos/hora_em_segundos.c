#include <stdio.h>

int main()
{
   int h, m, s, total;
   scanf("%d %d %d", &h, &m, &s);
   total= h*3600 + m*60 + s;
   if ((h < 0) | (h > 23)){
       printf("HORARIO INVALIDO");
   }
   else if((m < 0) | (m > 60)){
       printf("HORARIO INVALIDO");
   }
   else if((s < 0) | (s > 60)){
       printf("HORARIO INVALIDO");
   }
   else{
       printf("%d", total);
   }
   return 0;
}
