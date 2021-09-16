// C++ code
// Blink LED n times

// For LED
int LED_PIN = 2;
int DELAY = 500;
int counter = 0;

// For Serial Comm.
int number = 0;
String prompt = "Enter number of times you want to blink : ";
String message = "Blinking LED n times, n = ";

void setup()
{
    // Start and test Serial Communication
    Serial.begin(9600);
    Serial.println("Starting Program....");

    // Init LED Pin
    digitalWrite(LED_PIN, LOW);
}

void blink_led()
{
    // ON and OFF LED with delay
    digitalWrite(LED_PIN, HIGH);
    delay(DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(DELAY);
}

void loop()
{
    Serial.println(prompt);
    while (Serial.available() == 0)
    {
    }
    number = Serial.parseInt();
    Serial.print(message);
    Serial.println(number);

    for (counter = 0; counter < number; counter++)
        blink_led();
    delay(100);
}