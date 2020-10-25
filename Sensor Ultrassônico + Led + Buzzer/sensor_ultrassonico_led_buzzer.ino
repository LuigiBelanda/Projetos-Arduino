#define trigger 12
#define echo 11

float distancia;
float duracao;
float velocidade = 0.0172316;
int led = 8;
int buzzer = 2;


void alarme_lig()
{
	digitalWrite(led, 1);
  	tone(buzzer, 700);
  	delay(500);
  
  	digitalWrite(led, 0);
  	tone(buzzer, 900);
  	delay(500);
}

void alarme_desl()
{
  	digitalWrite(led, 0);
  	noTone(buzzer);
}

void setup()
{
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
  
	Serial.begin(9600);
  
	pinMode(led, OUTPUT);
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	digitalWrite(trigger, 0);
	delayMicroseconds(5);
	digitalWrite(trigger, 1);
	delayMicroseconds(10);
	digitalWrite(trigger, 0);
  
	duracao = pulseIn(echo, 1);
	distancia = duracao * velocidade;
  
	Serial.print("cm: ");
	Serial.println(distancia);
	delay(100);
  
  	if (distancia < 90)
  	{
		alarme_lig();  
  	}
  	else
  	{
  		alarme_desl();
  	}
}