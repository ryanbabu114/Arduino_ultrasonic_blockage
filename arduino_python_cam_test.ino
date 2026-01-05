#define trigPin 6
#define echoPin 7

long duration;
int distance;

// ✅ DEVICE INFO
String deviceName = "SewerMonitor-01";
String deviceId = "DEV-001";
String installationDate = "2025-12-01";
String locationName = "pala";
// ✅ DEVICE COORDINATES (DECIMAL)
String latitude = "9.71472";
String longitude = "76.68694";

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

  // Debug
  Serial.print(distance);
  Serial.println(" cm");

  // ALERT format:
  // ALERT,<location>,<distance>,<device_name>,<device_id>,<installation_date>,<lat>,<lon>
  if (distance > 0 && distance < 4) {
    Serial.print("ALERT,");
    Serial.print(locationName); Serial.print(",");
    Serial.print(distance); Serial.print(",");
    Serial.print(deviceName); Serial.print(",");
    Serial.print(deviceId); Serial.print(",");
    Serial.print(installationDate); Serial.print(",");
    Serial.print(latitude); Serial.print(",");
    Serial.println(longitude);

    delay(2000);
  }

  delay(500);
}
