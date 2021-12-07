void cannon()
{
    float x, y;
    int a = 110, b = 130, c = 110;
    LCD.DrawCircle(10, 110, 10);
    LCD.DrawCircle(10, 130, 10);
    LCD.DrawRectangle(20, 110, 50, 20);
    graphics();
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
                //graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
                a -= 5;
                b -= 5;
                c -= 5;
                Sleep(1);
                //LCD.Clear();
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(10, a+5, 10);
                LCD.DrawCircle(10, b+5, 10);
                LCD.DrawRectangle(20, c+5, 50, 20);
                //LCD.Update();
            }
            //Cannonball projectile
            int i = 80;
            while (i < 310)
            {
                //graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(i, 40, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 40, 10);
                i += 10;
                //Sleep(1);
                //LCD.Clear();
                //LCD.Update();
                Sleep(1);
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(i-10, 40, 10);
                LCD.FillCircle(i-10, 40, 10);
                LCD.SetFontColor(WHITE);
                LCD.DrawVerticalLine(80, 0, 239);
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
                //graphics();
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
                    //LCD.Clear();
                    LCD.SetFontColor(GREEN);
                    LCD.DrawCircle(10, a-5, 10);
                    LCD.DrawCircle(10, b-5, 10);
                    LCD.DrawRectangle(20, c-5, 50, 20);
                    //LCD.Update();
                }
                else if (a > 110 && b > 130 && c > 110)
                {
                    a -= 5;
                    b -= 5;
                    c -= 5;
                    Sleep(1);
                    //LCD.Clear();
                    LCD.SetFontColor(GREEN);
                    LCD.DrawCircle(10, a+5, 10);
                    LCD.DrawCircle(10, b+5, 10);
                    LCD.DrawRectangle(20, c+5, 50, 20);
                    //LCD.Update();
                }
            }
            int i = 80;
            while (i < 310)
            {
                //graphics();
                LCD.DrawCircle(i, 120, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 120, 10);
                i += 10;
                //Sleep(1);
                //LCD.Clear();
                //LCD.Update();
                Sleep(1);
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(i-10, 120, 10);
                LCD.FillCircle(i-10, 120, 10);
                LCD.SetFontColor(WHITE);
                LCD.DrawVerticalLine(80, 0, 239);
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
                //graphics();
                LCD.SetFontColor(WHITE);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
                a += 5;
                b += 5;
                c += 5;
                Sleep(1);
                //LCD.Clear();
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(10, a-5, 10);
                LCD.DrawCircle(10, b-5, 10);
                LCD.DrawRectangle(20, c-5, 50, 20);
                //LCD.Update();
            }
            int i = 80;
            while (i < 310)
            {
                //graphics();
                LCD.DrawCircle(i, 200, 10);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(i, 200, 10);
                i += 10;
                //Sleep(1);
                //LCD.Clear();
                //LCD.Update();
                Sleep(1);
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(i-10, 200, 10);
                LCD.FillCircle(i-10, 200, 10);
                LCD.SetFontColor(WHITE);
                LCD.DrawVerticalLine(80, 0, 239);
                LCD.DrawCircle(10, a, 10);
                LCD.DrawCircle(10, b, 10);
                LCD.DrawRectangle(20, c, 50, 20);
            }
        }
        //graphics();
    }
}

void graphics()
{
    int i;
    LCD.SetBackgroundColor(GREEN);
    //Draw Lanes
    for(i=0;i<24;i++)
    {
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle((10*i)+80, 75, 10, 10);
        LCD.DrawRectangle((10*i)+80, 155, 10, 10);
    }
    //LCD.DrawHorizontalLine(80, 80, 319);
    //LCD.DrawHorizontalLine(160, 80, 319);
    LCD.DrawVerticalLine(80, 0, 239);
}
