String message;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available());
  message = Serial.readString();
  Serial.print("Received Message: ");
  Serial.println(message);
}