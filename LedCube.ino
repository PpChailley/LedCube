#define DATA(x) (12-x)
#define OUTENA_  3
#define CLK     2


char outByte = 0x1;

void setup() 
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(DATA(i), OUTPUT);
  }
  pinMode(OUTENA_, OUTPUT);
  pinMode(CLK, OUTPUT);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA(i), LOW);
  }
  digitalWrite(OUTENA_, LOW);
  digitalWrite(CLK, LOW);
  
}


void display(unsigned char d)
{
  digitalWrite(CLK, LOW);
  delay(100);

  int led_ON = 0;
  switch(d)
  {
    case 0:   led_ON = 8; break;
    case 1:   led_ON = 0; break;
    case 2:   led_ON = 1; break;
    case 4:   led_ON = 2; break;
    case 8:   led_ON = 3; break;
    case 16:   led_ON = 4; break;
    case 32:   led_ON = 5; break;
    case 64:   led_ON = 6; break;
    case 128:   led_ON = 7; break;
    default:  led_ON = 8; break;
  }

  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA(i), (i==led_ON ? HIGH: LOW));
  }
  digitalWrite(CLK, HIGH);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
 // digitalWrite(DATA(0), HIGH);
  delay(100);
 digitalWrite(LED_BUILTIN, LOW);
 // digitalWrite(DATA(0), LOW);
  delay(200);
  
  //outByte = (outByte ? outByte <<1 : 0x1);

  if (outByte == 0 || outByte > 8)
    outByte = 0x1;
  else
    outByte = outByte * 2 ;
  
  //Serial.println(F("Byte value"));
  //Serial.println(outByte);
  display(outByte);
  

}

