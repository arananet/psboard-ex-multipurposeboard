
/*--------------------------------------------------------------
  Program:      voltmeter_LCD

  Description:  2 channel DC voltmeter with voltages displayed
                on OLED to 1 decimal place
  
  Hardware:     multipurpose board available on this repo.
                
  Software:     Developed using Arduino 1.6.5 software

  Date:         27 May 2013 / 07-02-2021
 
  Author:       W.A. Smith, http://startingelectronics.org
                Adapter for the multipurposeboard
		Support for Oled screens
		by @edu_arana - info@arananet.net
--------------------------------------------------------------*/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Picopixel.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// number of analog samples to take per reading, per channel
#define NUM_SAMPLES 10

// voltage divider calibration values
#define DIV_1    11.1346
#define DIV_2    11.1969

#define DIV_1    11.1346
#define DIV_2    11.1969

// ADC reference voltage / calibration value
#define V_REF    4.991

int sum[4] = {0};                // sums of samples taken
unsigned char sample_count = 0;  // current sample number
float voltage[4] = {0.0};        // calculated voltages
char l_cnt = 0;                  // used in 'for' loops

void setup()
{
      //setup the oled display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  //clear the display
  display.clearDisplay();
  showintro();
}


void showintro(void) {
  display.clearDisplay();

  display.setTextSize(1);             
  display.setTextColor(SSD1306_WHITE);       
  display.setCursor(0,0);             
  display.println(F("The Amiga"));
  
  display.setTextSize(2); 
  display.setCursor(0,13); 
  display.setFont(&Picopixel);
  display.println("SUPERSUPPLY");

  display.setTextSize(1);             
  display.setCursor(0,30); 
  display.setTextColor(SSD1306_WHITE);
  display.print("Designed by @edu_arana"); //keep the author.
  display.display();
  delay(3000);
}

void loop()
{
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        // sample each channel A2 to A5
        for (l_cnt = 0; l_cnt < 4; l_cnt++) {
            sum[l_cnt] += analogRead(A2 + l_cnt);
        }
        sample_count++;
        delay(10);
    }
    // calculate the voltage for each channel
    for (l_cnt = 0; l_cnt < 4; l_cnt++) {
        voltage[l_cnt] = ((float)sum[l_cnt] / (float)NUM_SAMPLES * V_REF) / 1024.0;
    }
    // display voltages on OLED
    // each voltage is multiplied by the resistor network
    // division factor to calculate the actual voltage
	
    // voltage 1 - A (pin A2)
 
    display.clearDisplay();
    display.setFont(&Picopixel);
    display.setTextColor(WHITE);
    
    display.setTextSize(2);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.print("A ");
    display.setCursor(18, 10);
    display.print(voltage[1] * DIV_1, 1); //watchout for voltage param number, this is referenced with the physical connection.        
    display.print("V ");      
	
    display.setCursor(0, 28);
    display.print("B ");     
    display.setCursor(18, 28);    
    display.print(voltage[0] * DIV_2, 1); //watchout for voltage param number, this is referenced with the physical connection.      
    display.print("V "); 
    
    display.setTextSize(2); 
    display.setCursor(65,10); 
    display.setFont(&Picopixel);
    display.println("A = 5V");
    display.setCursor(65,28); 
    display.println("B = 12V");

    display.display();
	
    // reset count and sums
    sample_count = 0;
    for (l_cnt = 0; l_cnt < 4; l_cnt++) {
        sum[l_cnt] = 0;
    }
}
