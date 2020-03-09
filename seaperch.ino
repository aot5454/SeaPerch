//Motor
int speedA = 5;
int speedB = 6;
int speedC = 3;

int dir1PinA = 10;
int dir2PinA = 11;
int dir1PinB = 12;
int dir2PinB = 13;
int dir1PinC = 9;
int dir2PinC = 8;

//Joy
int vrx = A0;
int vry = A1;

//BTN
int btnUp = A2;
int btnDown = A3;

void setup() {
  Serial.begin(9600);
  //Motor
  pinMode(speedA, OUTPUT);
  pinMode(speedB, OUTPUT);
  pinMode(speedC, OUTPUT);
  pinMode(dir1PinC, OUTPUT);
  pinMode(dir2PinC, OUTPUT);
  //Joy
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  //btn
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
}
void loop() {
  int x = analogRead(vrx);
  int y = analogRead(vry);
  Serial.print("x = ");
  Serial.println(x);
  Serial.print("y = ");
  Serial.println(y);
  if (x >= 450 and x <= 600 and y >= 450 and y <= 600) {
    stop();
  } else {
    if (x < 450) {
      run();
    }
    if (x > 600) {
      back();
    }
    if (y < 450) {
      turnR();
    }
    if (y > 600) {
      turnL();
    }
  }
  // BTN
  int btnU = digitalRead(btnUp); //<20 ทำงาน
  int btnD = digitalRead(btnDown); //<20 ทำงาน

  if (btnU == 0) {
    up();
    Serial.println("z = 1");
  }
  if (btnD == 0) {
    down();
    Serial.println("z = -1");
  }
  Serial.println("---------------");
  delay(100);
}//end loop

void back() {
  analogWrite(speedA, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  analogWrite(speedB, 255);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
}

void run() {
  analogWrite(speedA, 255);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  analogWrite(speedB, 255);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
}

void turnR() {
  analogWrite(speedA, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  analogWrite(speedB, 255);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
}

void turnL() {
  analogWrite(speedA, 255);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  analogWrite(speedB, 255);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
}

void stop() {
  analogWrite(speedA, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);

  analogWrite(speedB, 255);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);

  analogWrite(speedC, 255);
  digitalWrite(dir1PinC, LOW);
  digitalWrite(dir2PinC, LOW);
}

void up() {
  analogWrite(speedC, 255);
  digitalWrite(dir1PinC, HIGH);
  digitalWrite(dir2PinC, LOW);
}

void down() {
  analogWrite(speedC, 255);
  digitalWrite(dir1PinC, LOW);
  digitalWrite(dir2PinC, HIGH);
}
