const int audioPin = A0; // audio sinistra
int audio;
int sensitivityValue = 250;
int ledLevel;
boolean check = false;

int brightness = 0;    // how bright the LED is
int fadeAmount = 35;    // how many points to fade the LED by
int counter = 0;
int ledPin1 = 11;
float pulse = 0.7;
int count = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
}

void loop()
{

  analogWrite(ledPin1, 255);

  audio = analogRead(audioPin);
  ledLevel = map(audio, 0, 1023, 0, sensitivityValue);


  if (check == true) {
    Serial.println("pulsa!");
    pulsa();
    
  }




  if (ledLevel > 160) {
    analogWrite(ledPin1, 0);
    delay(200);
    check = true;

  }

}


void pulsa() {

  analogWrite(ledPin1, brightness);
  brightness = brightness - (fadeAmount * pulse);
  if (brightness <= 10 && counter == 0) {
    brightness = 255 ;
    counter = 1;
    fadeAmount = 5;
   // count = count +1;

  }
  else if (brightness <= 1 && counter == 1) {
    delay(32 * 10);
    brightness = 255;
    counter = 0;
    fadeAmount = 35;
    count = count +1;
   if (count > 2)
   {check = false;
   count = 0;}
   Serial.println(count);
  }
  delay(2 * 10);

}
