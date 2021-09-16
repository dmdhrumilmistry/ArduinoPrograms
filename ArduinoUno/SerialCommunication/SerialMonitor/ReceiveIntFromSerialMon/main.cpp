// C++ code
// Receive int from Serial Monitor

int number = 0;
String prompt = "Enter your Number : ";

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // Prompt User on Serial Monitor
    Serial.println(prompt);

    // Wait for input
    while (Serial.available() == 0)
    {
    }

    // Parse Integer received from Serial Monitor
    number = Serial.parseInt();

    // Print Number Received
    Serial.print("Received number : ");
    Serial.println(number);
    delay(100);
}