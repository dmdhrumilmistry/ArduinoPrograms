// C++ code
#include <LiquidCrystal.h>

// LiquidCrystal lcd(RS, RE, D4, D5, D6, D7);
LiquidCrystal lcd(7, 8, 6, 5, 4, 3);

void setup()
{
  	lcd.begin(16,2);
    lcd.clear();
}

void loop()
{
  	lcd.print("This is a test");
	// set the cursor to column 0, line 1
  	// (note: line 1 is the second row, since counting begins with 0):
  	// source : LiquidCrystal Documentation
  	lcd.setCursor(0, 1);
  	lcd.print("Example");
 	delay(100); 
  	
    // set cursor to column 0, line 0
  	lcd.setCursor(0,0);
}