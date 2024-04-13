/*regador de planta com temporizador.36º projeto.linguagem utilizada c++

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 13/12/2023
  Data de término do projeto 14/12/2023
*/
//**************inclusão das bibliotecas
#include <Wire.h>
#include <RTClib.h>
//**************definição
#define vermelho 2
#define amarelo 3
#define verde 4

#define bombadagua_1 5
#define bombadagua_2 6

#define SensorDeUmidade A0
//**************instanciação do objeto
RTC_DS1307 rtc;
//**************variável
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};
//******************************************************void setup**********************************************************************************
void setup () {
  //Serial.begin(57600);
  rtc.begin();
//**************pin mode
  pinMode(SensorDeUmidade,INPUT);// sensor de umidade da terra
  
  pinMode(vermelho, OUTPUT); //pin vermelho 2
  pinMode(amarelo, OUTPUT); //pin vermelho 3
  pinMode(verde, OUTPUT); //pin vermelho 4

  pinMode(bombadagua_1, OUTPUT); //pin boba d'água 5
  pinMode(bombadagua_2, OUTPUT); //pin boba d'água 6
 
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  //Serial.begin(9600);
}
//******************************************************void loop**********************************************************************************
void loop () {
    DateTime now = rtc.now();
//****************7 Horas************10 Minuto
   if( now.hour()==7 && now.minute()==10){
    if(analogRead(SensorDeUmidade)>=570){//liga a bomba d'água 
      analogWrite(bombadagua_1,200);
      digitalWrite(bombadagua_2,LOW);
       delay(1000);
    }else{//desliga a bomba d'água 
      analogWrite(bombadagua_1,0);
      digitalWrite(bombadagua_2,LOW);
      delay(1000);
    }
   }else{//desliga a bomba d'água se o tempo acabar
     analogWrite(bombadagua_1,0);
     digitalWrite(bombadagua_2,LOW);
   }
//****************5 Horas***********30 Minuto
  if( now.hour()==17 && now.minute()==30){
    if(analogRead(SensorDeUmidade)>=570){//liga a bomba d'água
      analogWrite(bombadagua_1,200);
      digitalWrite(bombadagua_2,LOW);
       delay(1000);
    }else{//desliga a bomba d'água 
      analogWrite(bombadagua_1,0);
      digitalWrite(bombadagua_2,LOW);
      delay(1000);
    }
   }else{//desliga a bomba d'água se o tempo acabar
     analogWrite(bombadagua_1,0);
     digitalWrite(bombadagua_2,LOW);
   }
//**************muda os leds de acordo com a umidade
   if(analogRead(SensorDeUmidade)<=1023 && analogRead(SensorDeUmidade)>=570){ //umidade da terra ruim
     digitalWrite(amarelo,LOW);
     digitalWrite(verde,LOW);
     digitalWrite(vermelho,HIGH);
    }
    if(analogRead(SensorDeUmidade)<=571 && analogRead(SensorDeUmidade)>=550){ //umidade da terra média
     digitalWrite(vermelho,LOW);
     digitalWrite(verde,LOW);
     digitalWrite(amarelo,HIGH);
    }
    if(analogRead(SensorDeUmidade)<=551){ //umidade da terra boa 
     digitalWrite(amarelo,LOW);
     digitalWrite(vermelho,LOW);
     digitalWrite(verde,HIGH);
    }
}