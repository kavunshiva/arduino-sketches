#define SENSE_PIN 0 // use pin A0 to detect voltage at capacitor
#define INDIC_PIN 13 // use pin 13 to pump capacitor

const int volt_percent = 50; // set set point for power output relative to rails
int time = 0; // define time variable
int cc_value = 0;

void setup() {
  pinMode(A0, INPUT); // voltage detect
  pinMode(13, OUTPUT); // capacitor pump
  digitalWrite(13, LOW); // set pin low
  // Serial.begin(9600);
  // log time, start fan, and start cooldown at 90% duty cycle (90% of 24 V = 21.6 V)
  time=millis();
}

void loop() {
  cc_value = analogRead(A0); // returns charge status of capacitor as int from 0 to 1023
  // Serial.println(cc_value);
  if (cc_value < (10*volt_percent - 50)) {
    // Serial.println(10*volt_percent);
    digitalWrite(13, HIGH); // if low, pump it up
  }
  if (cc_value > (10*volt_percent + 50)) {
    digitalWrite(13, LOW); // if high, take a chill pill
  }
  delay(2);
}
