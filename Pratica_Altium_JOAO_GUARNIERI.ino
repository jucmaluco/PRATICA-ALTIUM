#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219_1(0x40); 
Adafruit_INA219 ina219_2(0x41); 
Adafruit_INA219 ina219_3(0x42); 
Adafruit_INA219 ina219_3(0x43); 

void setup(void) {
  Serial.begin(115200); //taxa de bits da comunicação serial?
  while (!Serial) {
      delay(1); 
  }

  ina219_1.begin(); //inicializando os sensores
  ina219_2.begin();
  ina219_3.begin();
  ina219_4.begin();
}

void loop(void) {
  Serial.println("INA219_1");  
  readAndPrintINA219(ina219_1);
  Serial.println("INA219_2");
  readAndPrintINA219(ina219_2);
  Serial.println("INA219_3");
  readAndPrintINA219(ina219_3);
  Serial.println("INA219_4");
  readAndPrintINA219(ina219_4);
  
  delay(2000);
}

void readAndPrintINA219(Adafruit_INA219& ina219) {  //leitura dos parâmetros do sensor
  float shuntVoltage = ina219.getShuntVoltage_mV();
  float busVoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();

  Serial.print("Bus Voltage:   "); Serial.print(busVoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntVoltage); Serial.println(" mV");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");
}