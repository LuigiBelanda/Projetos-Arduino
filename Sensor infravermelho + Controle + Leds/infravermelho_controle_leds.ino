#include <IRremote.h>

#define led_laranja 11
#define led_vermelho 10
#define led_azul 9

int pino_receptor = 12;

IRrecv receptor(pino_receptor);

decode_results valorSaida;

void setup()
{
	Serial.begin(9600);
	receptor.enableIRIn(); 
  
  	//leds
	pinMode(led_laranja, OUTPUT);
  	pinMode(led_vermelho, OUTPUT);
  	pinMode(led_azul, OUTPUT);
    //leds
}

void loop() {
  
	if (receptor.decode(&valorSaida)) 
    {
      	Serial.println("Valor HEX do botao apertado:");
		Serial.println(valorSaida.value, HEX);
		receptor.resume();
	}
  
  	if (valorSaida.value == 0xFD00FF) // botão power  - liga tudo
    { 
		digitalWrite(led_laranja, HIGH);
        digitalWrite(led_vermelho, HIGH);
      	digitalWrite(led_azul, HIGH);
      	delay(500);
    	Serial.println("Todos os leds ligados");
	}
  
  	else if (valorSaida.value == 0xFD30CF)// botão 0 - desliga tudo
    { 
		digitalWrite(led_laranja, LOW);
        digitalWrite(led_vermelho, LOW);
      	digitalWrite(led_azul, LOW);
      	delay(500);
      	Serial.println("Todos os leds apagados");
	}
  
  	else if (valorSaida.value == 0xFD08F7)// botão 1 - liga só o primeiro led
    { 
		digitalWrite(led_laranja, HIGH);
      	delay(500);
      	Serial.println("Primeiro led acesso");
	}
    
    else if (valorSaida.value == 0xFD8877)// botão 2 - liga só o segundo led
    { 
        digitalWrite(led_vermelho, HIGH);
      	delay(500);
      	Serial.println("Segundo led acesso");
	}
  
  	else if (valorSaida.value == 0xFD48B7)// botão 3 - liga só o terceiro led
    { 
        digitalWrite(led_azul, HIGH);
      	delay(500);
      	Serial.println("Terceiro led acesso");
	}
  
  	else if (valorSaida.value == 0xFD28D7)// botão 4 - apaga o primeiro led
    { 
        digitalWrite(led_laranja, LOW);
      	delay(500);
      	Serial.println("Primeiro led apagado");
	}
  
  	else if (valorSaida.value == 0xFDA857)// botão 5 - apaga o segundo led
    { 
        digitalWrite(led_vermelho, LOW);
      	delay(500);
      	Serial.println("Segundo led apagado");
	}
  
  	else if (valorSaida.value == 0xFD6897)// botão 6 - apaga o terceiro led
    { 
        digitalWrite(led_azul, LOW);
      	delay(500);
      	Serial.println("Terceiro led apagado");
	}
  
}