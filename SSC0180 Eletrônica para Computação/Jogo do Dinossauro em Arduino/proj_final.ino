//pinos :
  //semaforo
int red_semaforo = 1;
int amarelo_semaforo = 2;
int verde_semaforo = 3;
  //contador
int contador1 = 4;
int contador2 = 5;
  //outros
int ledA = 0;
int butao = 6;
//variaveis de programa
int n_potencia;
int btn_state = 0;
int nrandomdelay;
int nrandomled;
int valorRed;

void contar(){
  delay(1000);
  digitalWrite(contador1, HIGH);
  delay(1000);
  digitalWrite(contador1, LOW);
  digitalWrite(contador2,HIGH);
  delay(1000);
  digitalWrite(contador1, HIGH);
  delay(1000);
  digitalWrite(contador2,LOW);
  digitalWrite(contador1, LOW);
  
}

void derrota(){
  digitalWrite(red_semaforo,HIGH);
  digitalWrite(amarelo_semaforo,HIGH);
  digitalWrite(verde_semaforo,HIGH);
  digitalWrite(contador1,HIGH);
  digitalWrite(ledA,HIGH);
  digitalWrite(contador2,HIGH);
  delay(1000);
  digitalWrite(red_semaforo,LOW);
  digitalWrite(amarelo_semaforo,LOW);
  digitalWrite(verde_semaforo,LOW);
  digitalWrite(contador1,LOW);
  digitalWrite(ledA,LOW);
  digitalWrite(contador2,LOW);
}
void evento_btn(){
  btn_state = digitalRead(butao);
  
  //Serial.println(nrandom);
  if(btn_state != 0){
    digitalWrite(ledA,LOW);
    digitalWrite(contador2,HIGH);
   }else{
    digitalWrite(ledA,HIGH);
    digitalWrite(contador2,LOW);
   }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(ledA,OUTPUT);
  pinMode(red_semaforo,OUTPUT);
  pinMode(amarelo_semaforo,OUTPUT);
  pinMode(verde_semaforo,OUTPUT);
  pinMode(contador1,OUTPUT);
  pinMode(contador2,OUTPUT);
  pinMode(A5,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  n_potencia = analogRead(A5);
  if(n_potencia < 350){
    nrandomled = random(0,2);
    nrandomdelay = random(500,1500);
    if(nrandomled == 1){
      //ledV = 5 ; ledA = 0; cVermelho = 4
      delay(500);
      evento_btn();
      digitalWrite(contador1,HIGH);
      evento_btn();
      delay(nrandomdelay);
      if(digitalRead(contador2) == HIGH && digitalRead(contador1) == HIGH){
        derrota();
      }
      evento_btn();
      digitalWrite(contador1,LOW);
    }
    evento_btn();
    //loop semaforo:
    //verde
    digitalWrite(verde_semaforo,HIGH);//acende o verde
    evento_btn();
    delay(nrandomdelay);
    evento_btn();
    digitalWrite(verde_semaforo,LOW);//apaga o verde
    evento_btn();
    //amarelo
    digitalWrite(amarelo_semaforo,HIGH);//ascende o amarelo
    evento_btn();
    delay(nrandomdelay);
    evento_btn();
    digitalWrite(amarelo_semaforo,LOW);//apaga o amarelo
    evento_btn();
     //vermelho
    digitalWrite(red_semaforo,HIGH);//liga o vermelho
    valorRed = 1;
    evento_btn();
    delay(nrandomdelay);
    evento_btn();
    delay(nrandomdelay);
    if(digitalRead(ledA) == HIGH && valorRed == 1){
      derrota();
    }
    digitalWrite(red_semaforo,LOW);//apaga o vermelho
    valorRed = 0;
    evento_btn();  
  }else{
    digitalWrite(ledA,LOW);
    //Semaforo
    digitalWrite(red_semaforo,HIGH);//liga o vermelho
    contar();
    digitalWrite(red_semaforo,LOW);//apaga o vermelho
    digitalWrite(amarelo_semaforo,HIGH);//ascende o amarelo
    contar();
    digitalWrite(amarelo_semaforo,LOW);//apaga o amarelo
    digitalWrite(verde_semaforo,HIGH);//acende o verde
    contar();
    digitalWrite(verde_semaforo,LOW);//apaga o verde
  }
}
