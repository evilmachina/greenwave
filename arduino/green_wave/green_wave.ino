

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

String beanName = "Green Wave";
const uint8_t statusScratch = 1;

void setup() {

  matrix.begin(0x70);  // pass in the address

  Bean.setBeanName(beanName);
  Bean.enableWakeOnConnect(true);

  // Reset the scratch data area 1. 
  uint8_t resetLedBuffer[] = {0, 0, 0};
  Bean.setScratchData(statusScratch, resetLedBuffer, 3);
}

uint8_t oldStatus = 0;

void loop() {

  bool connected = Bean.getConnectionState();
  
  if(connected) {
    Bean.setLed(0, 255, 0);
    ScratchData receivedData = Bean.readScratchData(statusScratch); 

    uint8_t status = receivedData.data[0];

    if(status != oldStatus)

    switch (status) {
      case 1:
        one();
        break;
      case 2:
        two();
        break;
      case 3:
        tree();
        break;
      case 4:
        foure();
        break;
      case 5:
        five();
        break;
      case 6:
        six();
        break;
      case 7:
        seven();
        break;
      case 8:
        eight();
        break;
      case 9:
        nine();
        break;
      default:
         break; 
        // if nothing else matches, do the default
        // default is optional
    }
    oldStatus = status;
    Bean.sleep(500);
  }else {
    matrix.clear();
    matrix.writeDisplay();
    // Turn LED off and put to sleep. 
    Bean.setLed(255, 0, 0);
    Bean.sleep(0xFFFFFFFF); 
  }
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
