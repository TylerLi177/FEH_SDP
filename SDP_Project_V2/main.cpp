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
        void back(); //Back button function
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
}

/*After int main*/
void Menu::menu() //Menu function definition 
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
    LCD.Update();
    Sleep(1);
    LCD.ClearBuffer();
    while(true)
    {
        /* Clear the touch buffer so touches made before
           this call are discarded */
        LCD.ClearBuffer();
        /* Wait until the user touches the screen */
        while(!LCD.Touch(&x,&y)) {};
        /* Wait until the touch releases */
        while(LCD.Touch(&x,&y)) {};
        if((x > 50 && x < 270) && (y > 20 && y < 60))
        {
            LCD.Clear();
            LCD.Update();
            (*this).game();
            break;
        }
        else if((x > 50 && x < 270) && (y > 70 && y < 110))
        {
            LCD.Clear();
            LCD.Update();
            (*this).stats();
            break;
        }
        else if((x > 50 && x < 270) && (y > 120 && y < 160))
        {
            LCD.Clear();
            LCD.Update();
            (*this).rules();
            break;
        }
        else if((x > 50 && x < 270) && (y > 170 && y < 210))
        {
            LCD.Clear();
            LCD.Update();
            (*this).credits();
            break;
        }
        LCD.Update();
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
    float x, y;
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
    back();
}

void Menu::stats()
{
float x, y;
LCD.WriteLine("Status Report: You suck at this game");
LCD.SetBackgroundColor(GREEN);
back();
}

void Menu::rules()
{
float x, y;
LCD.WriteLine("Shoot the shapes with the cannon. It's not that hard");
LCD.SetBackgroundColor(GREEN); 
back();
}

void Menu::credits()
{
LCD.WriteLine("The amazing Tyler Li and  Ben Lerner");
LCD.SetBackgroundColor(GREEN);
back();
}

//Back button definiton
void Menu::back()
{
float x, y;
LCD.DrawRectangle(250, 200, 60, 20);
    LCD.WriteAt("Back",250, 205);
    while(!LCD.Touch(&x,&y))
    {
       LCD.Update(); 
    }
    while(true)
    {
        /* Clear the touch buffer so touches made before
           this call are discarded */
        LCD.Clear();
        LCD.ClearBuffer();
        /* Wait until the user touches the screen */
        while(!LCD.Touch(&x,&y)) {};
        /* Wait until the touch releases */
        while(LCD.Touch(&x,&y)) {};
        if((x > 250 && x < 310) && (y > 200 && y < 220))
        {
            LCD.Clear();
            LCD.Update();
            (*this).menu();
        }
    }
}