void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  if (digitalRead(13) == 1) {
    tone(3, 98, 1000); // play tone 31 (G2 = 98 Hz)
  }
  if (digitalRead(12) == 1) {
    tone(3, 208, 1000); // play tone 44 (G#3 = 208 Hz)
  }
  if (digitalRead(11) == 1) {
    tone(3, 392, 1000); // play tone 55 (G4 = 392 Hz)
  }
  if (digitalRead(10) == 1) {
    tone(3, 1245, 1000); // play tone 75 (D#6 = 1245 Hz)
  }
  if (digitalRead(9) == 1) {
    tone(3, 3951, 1000); // play tone 95 (B7 = 3951 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}