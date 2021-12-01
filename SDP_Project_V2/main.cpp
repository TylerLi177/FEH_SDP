#include "FEHLCD.h"

/*
 * Entry point to the application
 */
int main() {
    // Clear background
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();

    LCD.WriteAt("Canaan Defense", 75, 100);
    //Hello there
    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}