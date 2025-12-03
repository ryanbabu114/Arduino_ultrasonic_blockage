#define trigPin 5
#define echoPin 6

long duration;
int distance;

// ✅ STORED LOCATION NAME
String locationName = "pala";

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Debug output
  Serial.print(distance);
  Serial.println(" cm");

  // ✅ Send ALERT with LOCATION + DISTANCE
  if (distance > 0 && distance < 10) {
    Serial.print("ALERT,");
    Serial.print(locationName);
    Serial.print(",");
    Serial.println(distance);   // Example: ALERT,pala,8

    delay(2000);  // Prevent spam alerts
  }

  delay(500);
}
