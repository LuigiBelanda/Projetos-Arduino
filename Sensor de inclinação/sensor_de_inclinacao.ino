int Led = 13;
int SensorIncli = 3;
int Estado; // var responsavel pelo valor do sensor (0 ou 1)

void setup()
{
  pinMode (Led, OUTPUT);
  pinMode (SensorIncli, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // o valor que sensor enviar fica nessa var
  Estado = digitalRead(SensorIncli); 
  if(Estado == LOW){
  	digitalWrite(Led, HIGH);
  } 
  else{
  	digitalWrite(Led, LOW);
  }
  
  // monitor serial
  Serial.print("Estado = "); //mensagem
  Serial.println(Estado); // valor var Estado
  
}