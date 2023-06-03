const int trigPin = 2;
const int echoPin = 3;
const int level4 = 8;
const int level3 = 11;
const int level2 = 12;
const int level1 = 13;
 
// defines variables
long duration;
int distance;
int safetyDistance;
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(level4, OUTPUT);
pinMode(level3, OUTPUT);
pinMode(level2, OUTPUT);
pinMode(level1, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (distance <=5)
{
  digitalWrite(level4, HIGH);
}
else
{
  digitalWrite(level4, LOW);
}
if (distance <=10)
{
  digitalWrite(level3, HIGH);
}
else
{
  digitalWrite(level3, LOW);
}
if (distance <=15)
{
  digitalWrite(level2, HIGH);
}
else
{
  digitalWrite(level2, LOW);
}
if (distance <=100)
{
  digitalWrite(level1, HIGH);
}
else
{
  digitalWrite(level1, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
