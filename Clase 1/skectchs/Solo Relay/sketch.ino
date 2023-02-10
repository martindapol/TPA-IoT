#include <LiquidCrystal_I2C.h>

const short PIN_RELAY = 26;

LiquidCrystal_I2C lcd(0x27, 16, 2); // este es el objeto lcd

void actualizarLCD(bool estado){
  lcd.clear();
  lcd.setCursor(0, 0);
  if(!estado){
    lcd.print("ENCENDIDO!");
  }else{
    lcd.print("APAGADO!");
  }
}

void setup() {
  pinMode(PIN_RELAY, OUTPUT);
  lcd.init();
  // Encender la luz del fondo de pantalla
  lcd.backlight();
}

void loop() {
  digitalWrite(PIN_RELAY, HIGH);
  delay(1000); // cada segundo cambiar el estado
  actualizarLCD(true);
  digitalWrite(PIN_RELAY, LOW);
  delay(1000); 
  actualizarLCD(false);
}
