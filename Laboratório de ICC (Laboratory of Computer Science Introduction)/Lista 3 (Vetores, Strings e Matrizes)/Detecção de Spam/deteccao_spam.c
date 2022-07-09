
#include <stdio.h>
#include <string.h>
int main(){
    int flag = 0;
    char string[150];
    
    char palavrasProib[][99] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda", "SOS"};
    while (fgets(string, 150, stdin) != NULL){

        if(strlen(string) > 77){
            printf("Spam");
            return 0;
        }
        
        for(int i = 0; i < 12; i++){
            if(strstr(string, palavrasProib[i]) != NULL){
                flag++;
            }
            if(flag > 1){
                printf("Spam");
                return 0;
            }
        }
    }
    
    printf("Inbox");
    
    
    
    
    return 0;
}