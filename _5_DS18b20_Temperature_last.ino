#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>

// ********** Software Connections **********
#define IntroDelay 200
#define InfoDelay 3000
#define DeviceNumberDelay 1000
#define DeviceIdDelay 3000
#define loopDelay 3000
#define loadDelay 20

// ********** Hardware Connections **********
#define ONE_WIRE_BUS 18

// ********** Initialise **********
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress CPU , GPU, MOBO, HDD, AMBIENT ;
LiquidCrystal lcd(10, 9, 14, 15, 17, 16);

float CPUt, GPUt, MOBOt, HDDt, AMBIENTt;

unsigned int days, hours, minutes, seconds;

int lines, full_lines, last_lines, i ;

byte Empty[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
};
byte Fil1[8] = {
  B11111,
  B00000,
  B10000,
  B10000,
  B10000,
  B00000,
  B11111,
};
byte Fil2[8] = {
  B11111,
  B00000,
  B11000,
  B11000,
  B11000,
  B00000,
  B11111,
};
byte Fil3[8] = {
  B11111,
  B00000,
  B11100,
  B11100,
  B11100,
  B00000,
  B11111,
};
byte Fil4[8] = {
  B11111,
  B00000,
  B11110,
  B11110,
  B11110,
  B00000,
  B11111,
};
byte Fil5[8] = {
  B11111,
  B00000,
  B11111,
  B11111,
  B11111,
  B00000,
  B11111,
};

void setup(){

  lcd.begin(16, 2);

  lcd.createChar(6, Empty);
  lcd.createChar(1, Fil1);
  lcd.createChar(2, Fil2);
  lcd.createChar(3, Fil3);
  lcd.createChar(4, Fil4);
  lcd.createChar(5, Fil5);

  Intro();

  sensors.begin();
  sensors.isParasitePowerMode();

  sensors.getAddress(CPU, 0);
  sensors.getAddress(GPU, 1);
  sensors.getAddress(MOBO, 2);
  sensors.getAddress(HDD, 3);
  sensors.getAddress(AMBIENT, 4);
  sensors.setResolution(CPU, 12);
  sensors.setResolution(GPU, 12);
  sensors.setResolution(MOBO, 12);
  sensors.setResolution(HDD, 12);
  sensors.setResolution(AMBIENT, 12);
  lcd.clear();
  lcd.print(sensors.getDeviceCount(), DEC);
  lcd.print(" Sensors Found");
  delay(DeviceNumberDelay);
  Boot_Screen();
  Prepare_Screen();
  
}

void loop(){

  lcd.setCursor(0, 0);
  lcd.print("CPU:     ");
  lcd.print(sensors.getTempC(CPU),2);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lines = map(sensors.getTempC(CPU),20,70,0,80);
  full_lines = lines / 5 ;
  for (i=0; i<full_lines; i++)lcd.write(5);
  last_lines = lines%5;
  if ( last_lines == 1 ) lcd.write(1);
  else if ( last_lines == 2 ) lcd.write(2);
  else if ( last_lines == 3 ) lcd.write(3);
  else if ( last_lines == 4 ) lcd.write(4);
  for(i=(full_lines+1); i< 16; i++)lcd.write(6);
  delay(loopDelay);

  lcd.setCursor(0, 0);
  lcd.print("Video:   ");
  lcd.print(sensors.getTempC(GPU),2);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lines = map(sensors.getTempC(GPU),20,70,0,80);
  full_lines = lines / 5 ;
  for (i=0; i<full_lines; i++)lcd.write(5);
  last_lines = lines%5;
  if ( last_lines == 1 ) lcd.write(1);
  else if ( last_lines == 2 ) lcd.write(2);
  else if ( last_lines == 3 ) lcd.write(3);
  else if ( last_lines == 4 ) lcd.write(4);
  for(i=(full_lines+1); i< 16; i++)lcd.write(6);
  delay(loopDelay);

  lcd.setCursor(0, 0);
  lcd.print("Chipset: ");
  lcd.print(sensors.getTempC(MOBO),2);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lines = map(sensors.getTempC(MOBO),20,70,0,80);
  full_lines = lines / 5 ;
  for (i=0; i<full_lines; i++)lcd.write(5);
  last_lines = lines%5;
  if ( last_lines == 1 ) lcd.write(1);
  else if ( last_lines == 2 ) lcd.write(2);
  else if ( last_lines == 3 ) lcd.write(3);
  else if ( last_lines == 4 ) lcd.write(4);
  for(i=(full_lines+1); i< 16; i++)lcd.write(6);
  delay(loopDelay);

  lcd.setCursor(0, 0);
  lcd.print("HDD:     ");
  lcd.print(sensors.getTempC(HDD),2);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lines = map(sensors.getTempC(HDD),20,70,0,80);
  full_lines = lines / 5 ;
  for (i=0; i<full_lines; i++)lcd.write(5);
  last_lines = lines%5;
  if ( last_lines == 1 ) lcd.write(1);
  else if ( last_lines == 2 ) lcd.write(2);
  else if ( last_lines == 3 ) lcd.write(3);
  else if ( last_lines == 4 ) lcd.write(4);
  for(i=(full_lines+1); i< 16; i++)lcd.write(6);
  delay(loopDelay);

  lcd.setCursor(0, 0);
  lcd.print("Case:    ");
  lcd.print(sensors.getTempC(AMBIENT),2);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lines = map(sensors.getTempC(AMBIENT),20,70,0,80);
  full_lines = lines / 5 ;
  for (i=0; i<full_lines; i++)lcd.write(5);
  last_lines = lines%5;
  if ( last_lines == 1 ) lcd.write(1);
  else if ( last_lines == 2 ) lcd.write(2);
  else if ( last_lines == 3 ) lcd.write(3);
  else if ( last_lines == 4 ) lcd.write(4);
  for(i=(full_lines+1); i< 16; i++)lcd.write(6);
  delay(loopDelay);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Uptime:");
  lcd.setCursor(0, 1);
  lcd.print(days);
  lcd.print("d ");
  lcd.print(hours);
  lcd.print("h ");
  lcd.print(minutes);
  lcd.print("m ");
  lcd.print(seconds);
  lcd.print("s");
  sensors.requestTemperatures();
  Calculate_elasped_time();
  delay(loopDelay);
  Prepare_Screen();

}


void Intro(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Temp  Sensor  ");
  delay(InfoDelay);
  lcd.setCursor(2, 1);

  lcd.print("b");
  delay(IntroDelay);
  lcd.print("y");
  lcd.print("  ");
  delay(IntroDelay);
  lcd.print("h");
  delay(IntroDelay);
  lcd.print("e");
  delay(IntroDelay);
  lcd.print("r");
  delay(IntroDelay);
  lcd.print("c");
  delay(IntroDelay);
  lcd.print("t");
  delay(IntroDelay);
  lcd.print("r");
  delay(IntroDelay);
  lcd.print("a");
  delay(IntroDelay);
  lcd.print("p");
  delay(IntroDelay);
  lcd.clear();
}


void Prepare_Screen(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print((char)B11011111);
  lcd.print("C");
  lcd.setCursor(0, 1);
  for ( int i =0; i<16; i++){
    lcd.write(6);
  }
}

void Calculate_elasped_time()
{
  days = millis() / 86400000;
  hours = millis() % 86400000/3600000;
  minutes = millis() % 3600000 / 60000;
  seconds = millis() % 60000 / 1000;
}

void Boot_Screen(){
  lcd.clear();
  lcd.print("    Loading    ");
  lcd.setCursor(0, 1);
  for ( int i =0; i<16; i++){
      for(int j=1; j<=5; j++){
        lcd.setCursor(i, 1);
        lcd.write(j);
        delay(loadDelay);
      }
  }
  delay(200);
}







