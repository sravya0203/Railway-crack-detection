#include <LiquidCrystal.h> LiquidCrystal lcd(8,9,10,11,12,13);

void sendmsgs()
{
Serial.println("AT+CMGF=1"); delay(1000);
Serial.println("AT+CMGS=\"+919787887901\"\r"); delay(1000);
Serial.println("External Crack Detected"); delay(1000);
Serial.println("https://www.latlong.net/c/?lat=12.8713&long=80.2224"); delay(1000);
Serial.println((char)26); delay(4000);
}


int count =0;


void setup()
{
lcd.begin(16, 2);
lcd.setCursor(0, 1);lcd.print("Smart Railway"); delay(1500);
lcd.clear(); Serial.begin(9600);
pinMode(6,OUTPUT);pinMode(7,OUTPUT);

digitalWrite(6,1);digitalWrite(7,1);
}


void loop()
{
int Cr=analogRead(A0); lcd.setCursor(0,0);lcd.print("ICD :");lcd.print(Cr);



int Cr1=analogRead(A1); lcd.setCursor(0,1);lcd.print("OCD :");lcd.print(Cr1);



if(Cr<900)
{
digitalWrite(6,0);digitalWrite(7,0); Serial.println("AT+CMGF=1"); delay(1000);
Serial.println("AT+CMGS=\"+919787887901\"\r"); delay(1000);
Serial.println("Internal Crack Detected"); delay(1000);
Serial.println("https://www.latlong.net/c/?lat=12.8713&long=80.2224"); delay(3000);
Serial.println((char)26); delay(4000); digitalWrite(6,1);digitalWrite(7,1);
}

if(Cr1<900)
{
count =count+1; lcd.setCursor(14,1);lcd.print(count); if(count>10)
{
digitalWrite(6,0);digitalWrite(7,0); sendmsgs();
count =0; digitalWrite(6,1);digitalWrite(7,1);
}
delay(500);
}
delay(1000); lcd.clear();
}