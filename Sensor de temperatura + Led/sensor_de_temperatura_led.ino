int led = 12;
int sensorTMP = A5;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensorTMP, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int valorTMP = analogRead(sensorTMP);
  float tensao = valorTMP * 5;
  
  tensao = (tensao / 1023);
  
  float temperaturaC = (tensao-0.5)*100;
    
  Serial.print("Temperatura: ");
  Serial.println(temperaturaC);
 
  if(temperaturaC >= 35)
  {
  	digitalWrite(led, HIGH);
  }
  else 
  {
    digitalWrite(led, LOW);
  }
  
  delay(500);
 
}