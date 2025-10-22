#define trigPin 5
#define echoPin 6

long duration;
int distance;

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

  // Print distance for debugging
  Serial.print(distance);
  Serial.println(" cm");

  // Only send ALERT if very close (<10 cm)
  if (distance > 0 && distance < 10) {
    Serial.println("ALERT");
    delay(2000);  // Avoid repeated alerts every loop
  }

  delay(500); // Small delay for stable readings
}
