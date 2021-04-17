#include <CapacitiveSensor.h> //biblioteca de uso do sensor capacitivo
#define  Led_Fogo 4
#define  Vento_Fogo 5


int limite_atv=700;//é o limite de capacitancia para ativar o circuito baseado no toque
//Aqui o objeto do sensor de presença é criado
CapacitiveSensor   Sensor = CapacitiveSensor(2,3);         //pin 3 é o pino do sensor feito de aluminio, 
  // put your setup code here, to run once:

 pinMode(Led_Fogo,OUTPUT);
 pinMode(Vento_Fogo,OUTPUT); 
   Serial.begin(9600);
}

void loop() {
 
    long valorcap =  Sensor.capacitiveSensor(30); //variavel feita pra armazenar os valores lidos pelo sensor

    //teste de limite

   Serial.println(valorcap);                  // mostra os valores que o sensor obtem
   


if(valorcap>limite_atv)//caso o valor lido passe do valor estabelecido lá em cima ele aciona o circuito com o relé
{
  digitalWrite(Led_Fogo,LOW); //o relé tem lógica invertida;colocando no normalmente aberto no circuito ,para acionar aqui usa se o LOW
  digitalWrite(Vento_Fogo,LOW);
 
}
else if(valorcap<limite_atv)
{
  digitalWrite(Led_Fogo,HIGH);
  digitalWrite(Vento_Fogo,HIGH);
}

}
