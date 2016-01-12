int x, y, z;
int ox, oy, oz;

void getAccelerate() {
  x = (analogRead(0) >> 2) - 128 - ox;
  y = (analogRead(1) >> 2) - 128 - oy;
  z = (analogRead(2) >> 2) - 128 - oz;
}

void setup() {
  Serial.begin(9600);
  
  ox = oy = oz = 0;
  for(int i = 0; i < 200; i++) {
    x = (analogRead(0) >> 2) - 128;
    y = (analogRead(1) >> 2) - 128;
    z = (analogRead(2) >> 2) - 128;
    ox += x;
    oy += y;
    oz += z;
    delay(10);
  }
  ox /= 200;
  oy /= 200;
  oz /= 200;
}


void loop() {
  getAccelerate();
  String str = "";
  str.concat(x);
  str.concat(",");
  str.concat(y);
  str.concat(",");
  str.concat(z);
  Serial.println(str);
  delay(50);
}
