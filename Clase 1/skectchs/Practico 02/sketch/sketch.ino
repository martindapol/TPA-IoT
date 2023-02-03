#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

const short  PIN_PULSADOR = 23;
const short  PIN_LED = 13;
const short  PIN_RELAY = 26;

int pulsador;
bool encendido;

void actualizarLcd(boolean encendido) {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (encendido)
    lcd.print("ENCENDIDO!");
  else
    lcd.print("APAGADO!");
}

void setup() {
  pinMode(PIN_PULSADOR, INPUT_PULLDOWN);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_RELAY, OUTPUT);
  
  encendido = LOW;
  Serial.begin(9600);
  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
  actualizarLcd(false);

}

void loop() {

  //wating..
  while (digitalRead(PIN_PULSADOR) == LOW);
  encendido = !encendido;
  actualizarLcd(encendido);
  //ON-OFF LED
  digitalWrite(PIN_LED, encendido);
  digitalWrite(PIN_RELAY, encendido);
  
  //wating...
  while (digitalRead(PIN_PULSADOR) == HIGH);
}