/*Pre Processor Directives*/
#include "FEHLCD.h"
#include "FEHUtility.h"
class Menu
{
    public:
        void ss(); //Start screen function
        void menu(); //Menu function
        void game(); //New game function
        void stats(); //Stats function
        void rules(); //Instructions function
        void credits(); //Credits function
};
/*Main function*/
int main(){
float x, y;//Declare variables
Menu game; //Create instance of Menu called game
game.ss(); //Load the start screen
if(LCD.Touch(&x,&y)){ //Enter menu if start screen is touched
    game.menu();
}
}
/*After int main*/
void Menu::menu() //Menu function defintion 
{
    float x, y;
    // Clear background
    //Set background to green
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    //Set font to white
    LCD.SetFontColor(LCD.White);
    //Create menu options
    LCD.DrawRectangle(50,20,220,40);
    LCD.DrawRectangle(50,70,220,40);
    LCD.DrawRectangle(50,120,220,40);
    LCD.DrawRectangle(50,170,220,40);
    LCD.WriteAt("New Game", 90, 33);
    LCD.WriteAt("Statistics", 90, 83);
    LCD.WriteAt("Instructions", 90, 133);
    LCD.WriteAt("Credits", 90, 183);
    while (1) {
        LCD.Update();
        // Never end
    }
}
void Menu::ss()
{
    float x, y;
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    //Generate starting screen
    LCD.SetFontColor(LCD.White);
    LCD.WriteAt("Cannon Defense", 75, 100);
    while (!LCD.Touch(&x,&y)) {
        LCD.Update();
        // Never end
    }
}
void Menu::game()
{
LCD.SetBackgroundColor(GREEN);
}
void Menu::rules()
{
LCD.SetBackgroundColor(GREEN);
}
void Menu::credits()
{
LCD.SetBackgroundColor(GREEN);
}