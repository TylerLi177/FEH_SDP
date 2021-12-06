/*Pre Processor Directives*/
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

class Menu
{
public:
    void ss();           //Start screen function prototype
    void menu();         //Menu function prototype
    void game();         //New game function prototype
    void stats();        //Stats function prototype
    void rules();        //Instructions function prototype
    void credits();      //Credits function prototype
    void back();         //Back button function prototype
    void difficulties(); //Difficulties menu function prototype
};

void cannon();       //Cannon function prototype
void graphics();     //Graphics function prototype

/*Main function*/
int main()
{
    float x, y; //Declare variables
    Menu game;  //Create instance of Menu called game
    game.ss();  //Load the start screen
    if (LCD.Touch(&x, &y))
    { //Enter menu if start screen is touched
        game.menu();
    }
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
    LCD.DrawRectangle(50, 20, 220, 40);
    LCD.DrawRectangle(50, 70, 220, 40);
    LCD.DrawRectangle(50, 120, 220, 40);
    LCD.DrawRectangle(50, 170, 220, 40);
    LCD.WriteAt("New Game", 90, 33);
    LCD.WriteAt("Statistics", 90, 83);
    LCD.WriteAt("Instructions", 90, 133);
    LCD.WriteAt("Credits", 90, 183);
    LCD.Update();
    Sleep(250);
    LCD.ClearBuffer();
    while (true)
    {
        /* Clear the touch buffer so touches made before
           this call are discarded */
        LCD.ClearBuffer();
        /* Wait until the user touches the screen */
        while (!LCD.Touch(&x, &y))
        {
        };
        /* Wait until the touch releases */
        while (LCD.Touch(&x, &y))
        {
        };
        if ((x > 50 && x < 270) && (y > 20 && y < 60))
        {
            LCD.Clear();
            LCD.Update();
            (*this).game();
            break;
        }
        else if ((x > 50 && x < 270) && (y > 70 && y < 110))
        {
            LCD.Clear();
            LCD.Update();
            (*this).stats();
            break;
        }
        else if ((x > 50 && x < 270) && (y > 120 && y < 160))
        {
            LCD.Clear();
            LCD.Update();
            (*this).rules();
            break;
        }
        else if ((x > 50 && x < 270) && (y > 170 && y < 210))
        {
            LCD.Clear();
            LCD.Update();
            (*this).credits();
            break;
        }
        LCD.Update();
    }
}

//Start screen function
void Menu::ss()
{
    LCD.SetBackgroundColor(GREEN); //Generate start screen
    LCD.Clear();                   //Clear previous background
    LCD.WriteAt("Cannon Defense", 75, 100);
    float x, y, time;
    int loop=0;
    time = TimeNow();
while(loop==0) {
        LCD.SetFontColor(LCD.White);
        if(LCD.Touch(&x,&y)){ //Enter menu if start screen is touched
            (*this).menu();
            loop=1;
        }       
        if(TimeNow()-time>1.0 && TimeNow()-time<1.1){
            LCD.SetFontColor(LCD.White);
            LCD.WriteAt("Click To Play", 78, 200);  
        }
        if(TimeNow()-time>2.0 && TimeNow()-time<2.1){
            LCD.SetFontColor(LCD.Green);
            LCD.WriteAt("Click To Play", 78, 200);
        }
        else if(TimeNow()-time>2.0)
        {
            time =TimeNow();
        }
    }
}

//Difficulty menu function definition
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
    LCD.DrawRectangle(50, 90, 220, 40);
    LCD.DrawRectangle(50, 150, 220, 40);
    LCD.WriteAt("Easy", 135, 100);
    LCD.WriteAt("Hard", 135, 160);
    difficulties();
}

//Stats function definition
void Menu::stats()
{
    LCD.WriteAt("Games won: ", 0, 0);
    LCD.WriteAt("0", 240, 0);
    LCD.WriteAt("Games lost:", 0, 50);
    LCD.WriteAt("0", 240, 50);
    LCD.WriteAt("Enemies killed:", 0, 100);
    LCD.WriteAt("0", 240, 100);
    LCD.SetBackgroundColor(GREEN);
    back();
}

//Instructions function definition
void Menu::rules()
{
    LCD.WriteAt("Click the cannon to", 0, 20);
    LCD.WriteAt("shoot the invading shapes.", 0, 40);
    LCD.WriteAt("To move the cannon, ", 0, 60);
    LCD.WriteAt("click behind the line of", 0, 80);
    LCD.WriteAt("the lane you want the", 0, 100);
    LCD.WriteAt("cannon to go to.", 0, 120);
    LCD.WriteAt("If they get past your", 0, 140);
    LCD.WriteAt("cannon, you lose!", 0, 160);
    LCD.SetBackgroundColor(GREEN);
    back();
}

//Credits function definition
void Menu::credits()
{
    LCD.WriteAt("The amazing Tyler Li and", 0, 20);
    LCD.WriteAt("Ben Lerner", 0, 40);
    LCD.SetBackgroundColor(GREEN);
    back();
}

//Back button definiton
void Menu::back()
{
    float x, y;
    int loop = 1;
    LCD.DrawRectangle(250, 200, 60, 20);
    LCD.WriteAt("Back", 250, 205);
    LCD.Update();
    while (loop)
    {
        /* Wait until the user touches the screen */
        while (!LCD.Touch(&x, &y))
        {
        };
        /* Wait until the touch releases */
        while (LCD.Touch(&x, &y))
        {
        };
        if ((x > 250 && x < 310) && (y > 200 && y < 220))
        {
            LCD.Clear();
            LCD.Update();
            (*this).menu();
            loop = 0;
        }
    }
}

//Difficulties menu selection function definition
void Menu::difficulties()
{
    float x, y;
    while (true)
    {
        LCD.DrawRectangle(250, 200, 60, 20);
        LCD.WriteAt("Back", 250, 205);
        /* Wait until the user touches the screen */
        while (!LCD.Touch(&x, &y))
        {
        };
        /* Wait until the touch releases */
        while (LCD.Touch(&x, &y))
        {
        };
        //Easy difficulty
        if ((x > 50 && x < 270) && (y > 90 && y < 130))
        {
            LCD.Clear();
            LCD.Update();
            int lane[3] = {15, 95, 175};
            int randInt = rand() % 3, enemy_health = 1 + rand() % 5, i = 270, j = 288;
            while (enemy_health > 0)
            {
                graphics();
                cannon();
                LCD.DrawRectangle(i, lane[randInt], 50, 50);
                LCD.WriteAt(enemy_health, j, lane[randInt] + 17);
                i--;
                j--;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
                if (i == 80)
                {
                    enemy_health = 0;
                    LCD.Clear();
                    LCD.Update();
                    LCD.WriteAt("YOU LOSE", 100, 100);
                    back();
                }
            }
        }
        //Hard difficulty
        else if ((x > 50 && x < 270) && (y > 150 && y < 190))
        {
            LCD.Clear();
            LCD.Update();
            graphics();
            int lane[3] = {15, 95, 175};
            int randInt = rand() % 3, enemy_health = 1 + rand() % 5, i = 270, j = 288;
            while (enemy_health > 0)
            {
                graphics();
                cannon();
                LCD.DrawRectangle(i, lane[randInt], 50, 50);
                LCD.WriteAt(enemy_health, j, lane[randInt] + 17);
                i -= 3;
                j -= 3;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
                if (i <= 80)
                {
                    enemy_health = 0;
                    LCD.Clear();
                    LCD.Update();
                    LCD.WriteAt("YOU LOSE", 100, 100);
                    back();
                }
            }
        }
        else if ((x > 250 && x < 310) && (y > 200 && y < 220))
        {
            LCD.Update();
            LCD.Clear();
            LCD.Update();
            (*this).menu();
            break;
        }
        LCD.Update();
    }
}

//Cannon function definition
void cannon()
{
    float x, y;
    int a = 110, b = 130, c = 110;
    LCD.DrawCircle(10, 110, 10);
    LCD.DrawCircle(10, 130, 10);
    LCD.DrawRectangle(20, 110, 50, 20);
    while (true)
    {
        /* Clear the touch buffer so touches made before
           this call are discarded */
        LCD.ClearBuffer();
        /* Wait until the user touches the screen */
        while (!LCD.Touch(&x, &y))
        {
        };
        /* Wait until the touch releases */
        while (LCD.Touch(&x, &y))
        {
        };
        //First lane
        if ((x > 0 && x < 70) && (y > 0 && y < 80))
        {
            while (a != 30 && b != 50 && c != 20)
            {
                graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
                a -= 5;
                b -= 5;
                c -= 5;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
            }
            //Cannonball projectile
            int i = 80;
            while (i < 310)
            {
                graphics();
                LCD.DrawCircle(i, 40, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 40, 10);
                i += 10;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
            }
        }
        //Second lane
        else if ((x > 0 && x < 70) && (y > 80 && y < 160))
        {
            while (a != 110 && b != 130 && c != 110)
            {
                graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
                if (a < 110 && b < 130 && c < 110)
                {
                    a += 5;
                    b += 5;
                    c += 5;
                    Sleep(1);
                    LCD.Clear();
                    LCD.Update();
                }
                else if (a > 110 && b > 130 && c > 110)
                {
                    a -= 5;
                    b -= 5;
                    c -= 5;
                    Sleep(1);
                    LCD.Clear();
                    LCD.Update();
                }
            }
            int i = 80;
            while (i < 310)
            {
                graphics();
                LCD.DrawCircle(i, 120, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 120, 10);
                i += 10;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
            }
        }
        //Third lane
        else if ((x > 0 && x < 70) && (y > 160 && y < 240))
        {
            while (a != 190 && b != 210 && c != 190)
            {
                graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
                a += 5;
                b += 5;
                c += 5;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
            }
            int i = 80;
            while (i < 310)
            {
                graphics();
                LCD.DrawCircle(i, 200, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 200, 10);
                i += 10;
                Sleep(1);
                LCD.Clear();
                LCD.Update();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
            }
        }
        graphics();
    }
}

//Graphics fucnction definition
void graphics()
{
    LCD.SetBackgroundColor(GREEN);
    //Draw Lanes
    LCD.DrawHorizontalLine(80, 80, 319);
    LCD.DrawHorizontalLine(160, 80, 319);
    LCD.DrawVerticalLine(80, 0, 239);
}
