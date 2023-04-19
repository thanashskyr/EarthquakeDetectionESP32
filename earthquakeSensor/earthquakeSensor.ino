#define led 4//led pin
 
#define x  14// x_out pin of Accelerometer
#define y 25 // y_out pin of Accelerometer
#define z 15 // z_out pin of Accelerometer
 
/*variables*/
int xsample=0;
int ysample=0;
int zsample=0;
long start;
int buz=0;
 
/*Macros*/
#define samples 50
#define maxVal 500// max change limit
#define minVal -500// min change limit
#define buzTime 2000 // buzzer on time     
 
void setup()
{

Serial.begin(115200); // initializing serial
delay(1000);

pinMode(led, OUTPUT);
buz=0;

digitalWrite(led, buz);
for(int i=0;i<samples;i++) // taking samples for calibration
{
xsample+=analogRead(x);
ysample+=analogRead(y);
zsample+=analogRead(z);
}
 
xsample/=samples; // taking avg for x
ysample/=samples; // taking avg for y
zsample/=samples; // taking avg for z
 
delay(3000);

}

 
void loop()
{
int value1=analogRead(x); // reading x out
int value2=analogRead(y); //reading y out
int value3=analogRead(z); //reading z out
 
int xValue=xsample-value1; // finding change in x
int yValue=ysample-value2; // finding change in y
int zValue=zsample-value3; // finding change in z
 
/* comparing change with predefined limits*/
if(xValue < minVal || xValue > maxVal || yValue < minVal || yValue > maxVal || zValue < minVal || zValue > maxVal)
{
      if(buz == 0)
      {
        start=millis(); // timer start
        buz=1; // buzzer / led flag activated
       
      }else // buzzer flag activated then alerting earthquake
      {
        
        if(millis()>= start+buzTime){
         buz=0;
        }
      }      
}else

{
    if(millis()>= start+buzTime){
         buz=0;
        }
   // Serial.println(" X Y Z ");
}
  

  digitalWrite(led, buz); // led on and off command
 
  /*sending values to processing for plot over the graph*/
    if (xValue>maxVal||xValue<minVal)
    {Serial.print("x=");
    Serial.println(xValue);}
     if (xValue>maxVal||xValue<minVal)
    {Serial.print("y=");
    Serial.println(yValue);}
     if (xValue>maxVal||xValue<minVal){
    Serial.print("z=");
    Serial.println(zValue);}
   // Serial.println(" $");
   
}