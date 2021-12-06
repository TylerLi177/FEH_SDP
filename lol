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
