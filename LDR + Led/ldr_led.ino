#define LED 13
#define LDR A5

// var que irá armazenar o valor do LDR
int valorLDR = 0; 


// funções liga e desliga led
void desligaLED()
{
  digitalWrite(LED, LOW);
}

void ligaLED()
{
  digitalWrite(LED, HIGH);
}


void setup()
{
  // input pois ele irá nos trazer dados
  pinMode(LDR, INPUT); 
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
}


void loop()
{
  // var sensorValue recebe o valor que está sendo lido 
  // na porta analogica A5 pelo ldr
  valorLDR = analogRead(LDR); 
  
  // mostra o valor no monitor serial
  Serial.println(valorLDR);
  
  // se o valor da var valorLDR for maior ou igual a 81 ele 
  // liga o led, se não ele desliga, ele faz isso chamando funções
  if(valorLDR >= 81)
  {
  	ligaLED();
  }
  else
  {
  	desligaLED();
  }
  
  delay(400); 
  
}