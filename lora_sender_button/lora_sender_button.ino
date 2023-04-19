/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/ttgo-lora32-sx1276-arduino-ide/
*********/

//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 23
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 866E6

//OLED pins
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

String response;//recieving response from other loras

//BUTTON INITIALIZATION
struct Button {
    const uint8_t PIN;
    uint32_t numberKeyPresses;
    bool pressed;
};

Button button1 = {15, 0, false};
Button button2 = {13, 0, false};
Button button3 = {2, 0, false};
Button button4 = {25, 0, false};
Button button5 = {14, 0, false};

long richter1=0;
long richter2=0;
long richter3=0;
long richter4=0;
long richter5=0;



//variables to keep track of the timing of recent interrupts
bool flag1=false;
bool flag2=false;
bool flag3=false;
bool flag4=false;
bool flag5=false;

int earthquakeCounter = 0;
double button1_time = 0;  
double last_button1_time = 0; 

double button2_time = 1;  
double last_button2_time = 1;

double button3_time = 2;  
double last_button3_time = 2;

double button4_time = 3;  
double last_button4_time = 3;


double button5_time = 4;  
double last_button5_time = 4; 

const char *horizontal;
const char *vertical;


void IRAM_ATTR isr1() {
        richter1=random(1,7);
        button1_time = millis();
    if (button1_time - last_button1_time > 250)
    {
           flag1=true;
            button1.numberKeyPresses++;
            button1.pressed = true;
            last_button1_time = button1_time;
            //  Serial.println("richter1: ");
            //  Serial.println(richter1);
    }
}




void IRAM_ATTR isr2() {
        richter2=random(1,7);
        button2_time = millis();
    if (button2_time - last_button2_time > 250)
    {
      flag2=true;
          
            button2.numberKeyPresses++;
            button2.pressed = true;
            last_button2_time = button2_time;
            //  Serial.println("richter2: ");
            //  Serial.println(richter2);
            
    }
}

void IRAM_ATTR isr3() {
        richter3=random(1,7);
        button3_time = millis();
    if (button3_time - last_button3_time > 250)
    {
            flag3=true;
                
            button3.numberKeyPresses++;
            button3.pressed = true;
            last_button3_time = button3_time;
            // Serial.println("richter3: ");
            //  Serial.println(richter3);  
           
    }
}

void IRAM_ATTR isr4() {
        richter4=random(1,7);
        button4_time = millis();
    if (button4_time - last_button4_time > 250)
    {
            flag4=true;
          
            button4.numberKeyPresses++;
            button4.pressed = true;
           
            last_button4_time = button4_time;
            //  Serial.println("richter4: ");
            //  Serial.println(richter4);
         
    }
}

void IRAM_ATTR isr5() {
        richter5=random(1,7);
        button5_time = millis();
    if (button5_time - last_button5_time > 250)
    {
            flag5=true;
           
            button5.numberKeyPresses++;
            button5.pressed = true;
            
            last_button5_time = button5_time;
            //  Serial.println("richter5: ");
            //  Serial.println(richter5);
          
    }

}








//packet counter
int counter = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  
  //BUTTON
  pinMode(button1.PIN, INPUT_PULLUP);
  attachInterrupt(button1.PIN, isr1, FALLING);
  pinMode(button2.PIN, INPUT_PULLUP);
  attachInterrupt(button2.PIN, isr2, FALLING);
  pinMode(button3.PIN, INPUT_PULLUP);
  attachInterrupt(button3.PIN, isr3, FALLING);
  pinMode(button4.PIN, INPUT_PULLUP);
  attachInterrupt(button4.PIN, isr4, FALLING);
  pinMode(button5.PIN, INPUT_PULLUP);
  attachInterrupt(button5.PIN, isr5, FALLING);




  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LORA SENDER ");
  display.display();
  
  Serial.println("LoRa Sender Test");

  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!");
  display.display();
  delay(2000);
}

void loop() {
  
 
            if ((millis()-button1_time)>2000){
              flag1=false;
            }
              if ((millis()-button2_time)>2000){
              flag2=false;
            }
             if ((millis()-button3_time)>2000){
              flag3=false;
            } 
              if ((millis()-button4_time)>2000){
              flag4=false;
            }
             if ((millis()-button5_time)>2000){
              flag5=false;
            }
   //BUTTON
   if ((flag1)&&(flag2)&&(flag3)&&(flag4)&&(flag5)) {

         if(richter1>richter2){
           horizontal="east";
           }
           else if(richter1==richter2)
           {
             horizontal="";
           }
           else{
             horizontal="west";
           }
         
           if(richter3>richter4){
           vertical="north";
           }
           else if(richter3==richter4){
           vertical="";
           }
           else{
             vertical="south";
           }


        earthquakeCounter=earthquakeCounter+1;         

     
 
        button1.pressed = false;
        button2.pressed = false;
        button3.pressed = false;
        button4.pressed = false;
        button5.pressed = false;
      //Send LoRa packet to receiver
        LoRa.beginPacket();
         LoRa.print("location:");
         LoRa.print(vertical);
         LoRa.print(horizontal);
         LoRa.print(",");
        LoRa.endPacket();

   




 

 
 
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("LORA SENDER");
  display.setCursor(0,20);
  display.setTextSize(1);
  display.print("LoRa packet sent.");
  display.setCursor(0,30);
  display.print("earthquake detected ");
  display.setCursor(180,40);
 
    
  display.display();
  
  delay(4000);
 
  

    //try to parse packet
  int packetSize1 = LoRa.parsePacket();
  Serial.print(packetSize1);
  
  if (packetSize1) {
    //received a packet
    Serial.print("mphka");
    Serial.print("Received packet ");
  

    //read packet
    while (LoRa.available()) {
      response = LoRa.readString();
      Serial.print(response);
    }
    display.clearDisplay();
    display.setCursor(0,0);
    display.print(response);

   display.display();  

  }
  
 }

}




