

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


void setup() {

  // put your setup code here, to run once:
 Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address


}


void loop() {


  one();
  delay(1000);

  two();
  delay(1000);

  tree();
  delay(1000);


  foure();
  delay(1000);


  five();
  delay(1000);


  six();
  delay(1000);


  seven();
  delay(1000);

  eight();
  delay(1000);


  nine();
  delay(1000);

}

void one(){
  matrix.clear();

  matrix.drawLine(0,0, 8,0, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display
  matrix.fillRect(3,4, 2,2, LED_RED);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void two(){
  matrix.clear();
 
  matrix.drawLine(0,1, 8, 1, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display

  matrix.fillRect(3,4, 2, 2, LED_YELLOW);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void tree(){
  matrix.clear();


  
  matrix.drawLine(0,2, 8, 2, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display


 matrix.fillRect(3,4, 2, 2, LED_YELLOW);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}


void foure(){
  matrix.clear();

  matrix.drawLine(0,3, 8, 3, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display

  matrix.fillRect(3,4, 2, 2, LED_YELLOW);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void five(){
  matrix.clear();
  
  matrix.drawLine(0,3, 8, 3, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display


  matrix.drawLine(0,4, 8, 4, LED_GREEN);
  matrix.writeDisplay(); 
}

void six(){
  matrix.clear();

  
  matrix.drawLine(0,4, 8, 4, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display


  matrix.fillRect(3,2, 2, 2, LED_YELLOW);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void seven(){
  matrix.clear();

  matrix.drawLine(0,4, 8, 4, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display

  matrix.fillRect(3,1, 2, 2, LED_YELLOW);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void eight(){
  matrix.clear();

  matrix.drawLine(0,5, 8, 5, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display


  matrix.fillRect(3,1, 2, 2, LED_RED);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}

void nine(){
  matrix.clear();
  
  matrix.drawLine(0,6, 8, 6, LED_GREEN);
  matrix.writeDisplay();  // write the changes we just made to the display

  matrix.fillRect(3,1, 2, 2, LED_RED);
  
  matrix.writeDisplay();  // write the changes we just made to the display
}
