#include <stdio.h>

int main(){
    int estacao;
    
    scanf("%d", &estacao);
    
    switch(estacao){
        case 0:
        printf("* Morumbi\n|\n* Butanta\n|\n* Pinheiros\n|\n* Faria Lima\n|\n* Fradique Coutinho\n|\n* Oscar Freire");
        break;
        
        case 1:
        printf("* Butanta\n|\n* Pinheiros\n|\n* Faria Lima\n|\n* Fradique Coutinho\n|\n* Oscar Freire");
        break;
        
        case 2:
        printf("* Pinheiros\n|\n* Faria Lima\n|\n* Fradique Coutinho\n|\n* Oscar Freire");
        break;
        
        
        case 3:
        printf("* Faria Lima\n|\n* Fradique Coutinho\n|\n* Oscar Freire");
        break;
        
        
        case 4:
        printf("* Fradique Coutinho\n|\n* Oscar Freire");
        break;
        
        
        case 5:
        printf("* Oscar Freire");
        break;
        
        case 6:
        printf("* Paulista\n|\n* Higienopolis-Mackenzie\n|\n* Republica\n|\n* Luz");
        break;
        
        case 7:
        printf("* Higienopolis-Mackenzie\n|\n* Republica\n|\n* Luz");
        break;
        
        case 8:
        printf("* Republica\n|\n* Luz");
        break;
        
        case 9:
        printf("* Luz");
        break;
        
    }
    return 0;
}
