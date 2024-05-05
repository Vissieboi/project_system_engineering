#include <Wire.h>
#include <Zumo32U4.h>

const uint32_t sensorThreshold = 1;

//Het object frontProxSensor wordt aangemaakt.
Zumo32U4ProximitySensors frontProxSensor;


void setup() {
  
  //Het object frontProxSensor wordt geconfigureerd, 
  //zodat het alleen de voorste proximity sensor kan gebruiken.
  frontProxSensor.initFrontSensor();
}

void loop() {
  //Lees de waarden van de sensor.
  frontProxSensor.read();

  //hier worden twee variabelen aangemaakt
  //het aantal helderheidniveaus worden terug gegeven voor de linker led,
  //die de voorste proximity sensor heeft geactiveerd.
  uint32_t leftValue = frontProxSensor.countsFrontWithLeftLeds();
  
  //het aantal helderheidniveaus worden terug gegeven voor de rechter led,
  //die de voorste proximity sensor heeft geactiveerd.
  uint32_t rightValue = frontProxSensor.countsFrontWithRightLeds();

  //Omkeren van de waarden.
  leftValue = 5 - leftValue;
  rightValue = 5 - rightValue;

  //Print de waarden.
  Serial.print("Linkerwaarde: ");
  Serial.println(leftValue);
  Serial.print("Rechterwaarde: ");
  Serial.println(rightValue);

  delay(500);
  
  //Als één van de waardes gelijk is aan "0", 
  //dan wordt er geprint "Stop met rijden".
  if (leftValue == 0 || rightValue == 0) {
    Serial.println("Stop met rijden");
    delay(5000);
  }
}
