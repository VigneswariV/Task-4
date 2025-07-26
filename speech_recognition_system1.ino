#define LED_PIN 3
#define FAN_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  Serial.println("Ready for voice commands (type in serial monitor)");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // remove spaces or newline

    if (command == "light on") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Light turned ON");
    }
    else if (command == "light off") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("Light turned OFF");
    }
    else if (command == "fan on") {
      digitalWrite(FAN_PIN, HIGH);
      Serial.println("Fan turned ON");
    }
    else if (command == "fan off") {
      digitalWrite(FAN_PIN, LOW);
      Serial.println("Fan turned OFF");
    }
    else if (command == "stop") {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(FAN_PIN, LOW);
      Serial.println("All devices OFF");
    }
    else {
      Serial.println("Invalid command. Try: light on, fan off, stop");
    }
  }
}
