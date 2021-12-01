#include "FEHLCD.h"

/*
 * Entry point to the application
 */
int main() {
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    LCD.WriteLine("My name is Tyler");
    
    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}