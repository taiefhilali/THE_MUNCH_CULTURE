
#define buzzer 10
#define  smokeA0 A5
// Your threshold value
int sensorThres = 400;
char data;
int i = 0;


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  noTone(buzzer);
}

void loop() {


  
  if (Serial.available())
  {
        data = Serial.read();
    if (data == '0')
      {
        i=0;
        noTone(buzzer);
        Serial.write('0');
      }
  }
    int analogSensor = analogRead(smokeA0);
 
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    // Checks if it has reached the threshold value
    if (analogSensor > sensorThres  )   
     { i = 1;
     }
    if (i == 1)
    {
      tone(buzzer, 1000, 200);
      Serial.write('1');      
    }
    delay(100);
  
}
