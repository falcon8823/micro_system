import processing.serial.*;

Serial myPort;
String myString = null;
int x, y, z;

void setup() {
  size(500, 500);
  
  for(String n : Serial.list()) {
    println(n);
  }
  
  String portName = Serial.list()[5];
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  myString = myPort.readStringUntil('\n');
  myString = null;
}

void draw() {
  background(0);
  if(myPort.available() > 0) {
    myString = myPort.readStringUntil('\n');
    if(myString != null) {
      String[] vals = myString.trim().split(",", 0);
      if(vals.length == 3) {
        x = int(vals[0]);
        y = int(vals[1]);
        z = int(vals[2]);
      }
      println(x, y, z);
    }
  }
  
  fill(255, 0, 0);
  rect(width / 2, 50, x, 20);
  fill(0, 255, 0);
  rect(width / 2, 75, y, 20);
  fill(0, 0, 255);
  rect(width / 2, 105, z, 20);
}

