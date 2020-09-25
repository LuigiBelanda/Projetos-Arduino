int PIRval = 0;


void setup()
{
  pinMode(13, OUTPUT); // led verde
  pinMode(12, OUTPUT); // led vermelho
  pinMode(2, INPUT); // sensor
}

void loop()
{
  PIRval = digitalRead(2); // le o valor do pino 2
  
  if (PIRval == HIGH)
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
 
  else 
  {
  	digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  
}