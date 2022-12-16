const short PIN_LED = 12; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(1000); // this speeds up the simulation
  digitalWrite(PIN_LED, LOW);
  delay(1000); // this speeds up the simulation
}
