#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void calcular_tempo(long long int tempo, char planeta[8],  unsigned long long int* dias, unsigned long long int* horas, unsigned long long int *minutos, unsigned long long int *segundos){
    if((strstr(planeta, "Terra")) != NULL){
        
        *dias = tempo/(86400);
        *horas = (tempo%86400)/(3600);
        *minutos = (tempo%86400)%(3600)/60;
        *segundos = (tempo%86400)%(3600)%60;
    }

    else if((strstr(planeta, "Venus")) != NULL){
        
        
        *dias =  tempo/(86400*243);
        *horas = (tempo%(86400*243))/3600;
        *minutos = ((tempo%(86400))%3600)/60;
        *segundos = ((tempo%(86400))%3600)%60;
    }

    else if((strstr(planeta, "Mercurio")) != NULL){
        *dias =  tempo/(5068800);
        *horas = (tempo%(5068800))/3600;
        *minutos = ((tempo%(5068800)%3600)/60);
        *segundos = ((tempo%(5068800)%3600)%60);
    }

    else if((strstr(planeta, "Jupiter")) != NULL){
        *dias =  tempo/(35760);
        *horas = (tempo%(35760))/3600;
        *minutos = ((tempo%(35760))%3600)/60;
        *segundos = ((tempo%(35760))%3600)%60;
    }
}


int main(){
    char planet[8];
    long long int segundos;
    unsigned long long int days = 0, hours = 0, minutes = 0, seconds =0;
    unsigned long long int *dayptr = &days, *hourptr = &hours, *minutesptr = &minutes, *secondsptr = &seconds;

    scanf("%lld %s", &segundos, planet);

    calcular_tempo(segundos, planet, dayptr, hourptr, minutesptr, secondsptr);
    printf("%llu segundos no planeta %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n", segundos, planet, days, hours, minutes, seconds);

    return 0;


}