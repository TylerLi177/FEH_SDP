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
        void blinker();//Blinker function
};

/*Main function*/
int main()
{
Menu game; //Create instance of Menu called game
game.ss(); //Load the start screen
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
    LCD.WriteAt("Stats", 90, 83);
    LCD.WriteAt("Rules", 90, 133);
    LCD.WriteAt("Credits", 90, 183);
    LCD.Update();
    Sleep(250);
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
    LCD.SetBackgroundColor(GREEN);//Generate start screen
    LCD.Clear();//Clear previous background
    LCD.WriteAt("Cannon Defense", 75, 100);
    float x, y, time;
    int loop=0;
    while(loop==0) {
        LCD.SetFontColor(LCD.White);
        time = TimeNow();
        if(LCD.Touch(&x,&y)){ //Enter menu if start screen is touched
            (*this).menu();
            loop=1;
        }       
        if(TimeNow()-time<1.0){
            LCD.SetFontColor(LCD.White);
            LCD.WriteAt("Click To Play", 75, 200);  
            time =TimeNow();
        // Never end
        }
        if(TimeNow()-time<2.0){
            LCD.SetFontColor(LCD.Green);
            LCD.WriteAt("Click To Play", 75, 200);
        }
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
    back();
}

void Menu::stats()
{
    LCD.WriteAt("Status Report:", 0 , 20);
    LCD.WriteAt("You suck at this game", 0, 40);
    LCD.SetBackgroundColor(GREEN);
    back();
}

void Menu::rules()
{
    LCD.WriteAt("Shoot the shapes with the",0,20);
    LCD.WriteAt("cannon. It's not that hard",0,40);
    LCD.SetBackgroundColor(GREEN); 
    back();
}

void Menu::credits()
{
    LCD.WriteAt("The amazing Tyler Li and",0,20);
    LCD.WriteAt("Ben Lerner", 0, 40);
    LCD.SetBackgroundColor(GREEN);
    back();
}

//Back button definiton
void Menu::back()
{
float x, y;
LCD.DrawRectangle(250, 200, 60, 20);
    LCD.WriteAt("Back",255, 203);
    while(true)
    { 
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
