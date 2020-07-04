int incomingByte = 0;
int led1 = 13;
int led2 = 2;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    // read the incoming byte:
    incomingByte = Serial.read();

    switch (char(incomingByte)) {
      case 'A':
        Serial.println("LED 1 ON");
        ledOn(led1);
        break;
      case 'a':
        Serial.println("LED 1 OFF");
        ledOff(led1);
        break;
      case 'B':
        Serial.println("LED 2 ON");
        ledOn(led2);
        break;
      case 'b':
        Serial.println("LED 2 OFF");
        ledOff(led2);
        break;
      default:
        Serial.println("Oops");
    }

    // say what you got:
    //Serial.print("I received: ");
    //Serial.println(char(incomingByte));
  }
}

void ledOn(int pin) {
  digitalWrite(pin, HIGH);
}

void ledOff(int pin) {
  digitalWrite(pin, LOW);
}
