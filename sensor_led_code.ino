// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 11 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 12 //attach pin D3 Arduino to pin Trig of HC-SR04
int led_1 = 8;
int led_2 = 7;
int led_3 = 5;
int led_4 = 4;
int buzzerpin = 31;
bool once = true;
bool onceled_1 = true;
bool onceled_2 = true;
bool onceled_3 = true;
bool onceled_4 = true;
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance >=0 && distance <=10 ){
    digitalWrite(LED_BUILTIN, HIGH);
    if (once == true){
    digitalWrite(buzzerpin, HIGH);
    delay (10);
    digitalWrite(buzzerpin, LOW);
    once = false;
    }
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    once = true;
  }
    if (distance >=11 && distance <=20){
    digitalWrite(led_1, HIGH);
    if (onceled_1 == true){
    digitalWrite(buzzerpin, HIGH);
    delay (10);
    digitalWrite(buzzerpin, LOW);
    onceled_1 = false;
    }
  }
  else {
    digitalWrite(led_1, LOW);
    onceled_1 = true;
  } 
  if (distance >=21 && distance <=30){
    digitalWrite(led_2, HIGH);
    if (onceled_2 == true){
    digitalWrite(buzzerpin, HIGH);
    delay (10);
    digitalWrite(buzzerpin, LOW);
    onceled_2 = false;
    }
  }
  else {
    digitalWrite(led_2, LOW);
    onceled_2 = true;
  } 
  if (distance >=31 && distance <=40){
    digitalWrite(led_3, HIGH);
    if (onceled_3 == true){
    digitalWrite(buzzerpin, HIGH);
    delay (10);
    digitalWrite(buzzerpin, LOW);
    onceled_3 = false;
    }
  }
  else {
    digitalWrite(led_3, LOW);
    onceled_3 = true;
  } 
  if (distance >=41 && distance <=50){
    digitalWrite(led_4, HIGH);
    if (onceled_4 == true){
    digitalWrite(buzzerpin, HIGH);
    delay (10);
    digitalWrite(buzzerpin, LOW);
    onceled_4 = false;
    }
  }
  else {
    digitalWrite(led_4, LOW);
    onceled_4 = true;
  } 
  }
