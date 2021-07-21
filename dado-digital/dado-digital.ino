const int a=3, b=4, c=5, d=6, e=7, f=8, g=9;

const int PIN_BUTTON = 2;

const int num[6][6] {
  {b, c},           // um
  {a, b, e, d, g},  // dois
  {a, b, c, d, g},  // tres
  {b, c, f, g},     // quatro
  {a, c, d, f, g},  // cinco
  {a, c, d, e, f, g} // seis
};

void setup() { 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(PIN_BUTTON, INPUT_PULLUP);

  digitalWrite(a, HIGH);
  delay(100);
  digitalWrite(b, HIGH);
  delay(100);
  digitalWrite(c, HIGH);
  delay(100);
  digitalWrite(d, HIGH);
  delay(100);
  digitalWrite(e, HIGH);
  delay(100);
  digitalWrite(f, HIGH);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    rollDice();
  }
}

void rollDice() {
  int choosedNumber = random(6);
  
  for (int i = 0; i < 6; i++) {
    erase();
    int randomNumber = random(6);
    printNumber(randomNumber);
    delay(100);
  }
  
  erase();
  printNumber(choosedNumber);
}

void erase() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void printNumber(int n) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(num[n][i], HIGH);
  }
}
