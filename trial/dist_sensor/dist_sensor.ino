int tones[] = {
  261,
  277,
  294,
  311,
  329,
  349,
  370,
  392,
  415,
  440,
  466,
  494,
  523
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = map(analogRead(0) >> 2, 20, 160, 0, 12);
  Serial.println(val);
  //if(val > 20) {
    tone(8, tones[val]);
  //} else {
  //  noTone(8);
  //}
  //delay(100);
}
