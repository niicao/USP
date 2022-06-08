#include <stdio.h>

int main()
{
    int s, h=0, m=0, sec=0;
    
    scanf("%d", &s);

    h = s/3600;
    m = (s%3600)/60;
    sec = ((s%3600)%60);
    
    printf("%02d:%02d:%02d", h, m, sec);
    return 0;
}
