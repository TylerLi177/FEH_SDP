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
int main()
{
float x, y;//Declare variables
Menu game; //Create instance of Menu called game
game.ss(); //Load the start screen
if(LCD.Touch(&x,&y)){ //Enter menu if start screen is touched
    game.menu();
}

//Clicking the instructions button;
while(true)
    {
        /* Clear the touch buffer so touches made before
           this call are discarded */
        LCD.ClearBuffer();
        /* Wait until the user touches the screen */
        while(!LCD.Touch(&x,&y)) {};
        /* Wait until the touch releases */
        while(LCD.Touch(&x,&y)) {};
        if((x > 50 && x < 220) && (y > 20 && y < 60))
        {
            LCD.Clear();
            LCD.Update();
            game.game();
        }
        else if((x > 50 && x < 220) && (y > 70 && y < 110))
        {
            LCD.Clear();
            LCD.Update();
            game.stats();
        }
        else if((x > 50 && x < 220) && (y > 120 && y < 160))
        {
            LCD.Clear();
            LCD.Update();
            game.rules();
        }
        else if((x > 50 && x < 220) && (y > 170 && y < 210))
        {
            LCD.Clear();
            LCD.Update();
            game.credits();
        }
    }


}
/*After int main*/
void Menu::menu() //Menu function defintion 
{
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
    LCD.Update();
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
    // Clear background
    //Set background to green
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    //Set font to white
    LCD.SetFontColor(LCD.White);
    //Create menu options
    LCD.WriteAt("Choose Difficulty", 60, 40);
    LCD.DrawRectangle(50,90,220,40);
    LCD.DrawRectangle(50,150,220,40);
    LCD.WriteAt("Easy", 135, 100);
    LCD.WriteAt("Hard", 135, 160);
    LCD.Update();
}
void Menu::stats()
{
LCD.WriteLine("Status Report: You fucking suck at this game");
LCD.SetBackgroundColor(GREEN);
}
void Menu::rules()
{
LCD.WriteLine("This is the cannon");
LCD.DrawCircle(125, 195, 35);
LCD.DrawCircle(195, 195, 35);
LCD.DrawCircle(160, 55, 35);
LCD.DrawVerticalLine(125,55,160);
LCD.DrawVerticalLine(195,55,160);
LCD.DrawVerticalLine(160,20,25);
LCD.SetBackgroundColor(GREEN); 
}

void Menu::credits()
{
LCD.WriteLine("The amazing Tyler Li and  Ben Lerner");
LCD.SetBackgroundColor(GREEN);
}

