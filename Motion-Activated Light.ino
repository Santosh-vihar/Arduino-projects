#define PIR_SENSOR 2  // PIR sensor output pin
#define LED 13        // LED pin

void setup() {
    pinMode(PIR_SENSOR, INPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int motion = digitalRead(PIR_SENSOR);

    if (motion == HIGH) { // Motion detected
        digitalWrite(LED, HIGH);
        Serial.println("Motion detected! LED ON");
    } else { // No motion
        digitalWrite(LED, LOW);
        Serial.println("No motion detected. LED OFF");
    }

    delay(500);
}
