#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<winuser.h>
using namespace std;
int x=50,y=450,radius=15,a=0,b=600,c,page=0,posx=0;
float g=8,dx,dy,tx=10,screenwidth=1566, screenheight=720;
void loading_screen()
{	
	setcolor(CYAN);
	settextstyle(4,HORIZ_DIR,5);
    outtextxy(450,350, "L O A D I N G" );
    for(int i=0;i<100;i=i+10)
    {
    	int e=i*2;
    	setcolor(RED);
    	line (200+e,200,400,200);
    	line (300,100+e,300,300);
    	delay(10);
    	int j=i*2.1;
    	setcolor(CYAN);
		line (200,200,400+j,200);
    	line (300,100,300,300+j);
    	delay(10);
    	int k=i*2.3;
		setcolor(BLUE);
		line (200,200,400,200+k);
    	line (300,100,300+k,300);
    	delay(10);
    	int l=i*2.6;
		setcolor(LIGHTGREEN);
		line (200,200,400,200+l);
    	line (300,100,300+l,300);
    	delay(10);
    	int m=i*2.5;
		setcolor(GREEN);
		line (200,200+m,400,200);
    	line (300+m,100,300,300);
	}
		for(int a=0;a<30;a=a+10) 		//main loop for loading dots
		{                  
				setcolor(CYAN);
				setfillstyle(SOLID_FILL,CYAN);
				rectangle(860+a,375,865+a,380);
				floodfill(861+a,379,CYAN);
				delay(1000);
		}
		cleardevice();
//    do{
//	    	setcolor(BLUE);
//			setfillstyle(SOLID_FILL,BLUE);
//			circle(200+count,250,10);
//			floodfill(200+count,250,BLUE);
//			delay(10);
//			setcolor(GREEN);
//			setfillstyle(SOLID_FILL,GREEN);
//			circle(210+count,250,10);
//			floodfill(210+count,250,GREEN);
//			delay(10);
//			setcolor(RED);
//			setfillstyle(SOLID_FILL,RED);
//			circle(220+count,250,10);
//			floodfill(220+count,250,RED);
//			delay(10);
//			count+=30;
//	}while(count < 100);


}
void start()
{
	setcolor(CYAN);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(450,350, "Press enter to play game" );
}
void body(int x,int y,int radius){ 
        //stickman//
            //head//
            setcolor(WHITE);
            circle(x, y, radius);
            //eyes//
            circle(x-5, y-4, 3);
            circle(x+5, y-4, 3);
            //      //
            //mouth//
            line(x-5,y+8,x+5,y+8);
            //
            //torso//
            line(x, y + radius, x, y + radius + 20);
            //hand
            line(x,y+radius+5,x-15,y+radius+20);
            line(x,y+radius+5,x+15,y+radius+20);
            //legs//
            line(x,y+radius+20,x-10,y+radius+40);
            line(x,y+radius+20,x+10,y+radius+40);
            // Sun
            setlinestyle(0,0,2);
            setfillstyle(SOLID_FILL,YELLOW);
            circle(x+1000,50,100);
            floodfill(x+1000,50,WHITE);
            //
            //ground
            line(a,b,a+10000,b); 
            //ground color
            setfillstyle(SOLID_FILL,BROWN);
            rectangle(a,b,a+10000,b+100);
            floodfill(5000,b+20,WHITE);
            //
            //ellipse as cloud and lines as a spike   
            //spikes in loop
            for(int j=1; j<40; j++){
            line(30+300*j,b,30+300*j,b-20);
            line(50+300*j,b,50+300*j,b-20);
            line(70+300*j,b,70+300*j,b-20);
            }
            //ellipse(cloud) in loops;
            for(int i=0; i<20;i++){
            setfillstyle(SOLID_FILL,WHITE);
            ellipse(100, 100, 0, 360, 200, 100);
            fillellipse(100+i*2000, 100,200, 100);
            fillellipse(340+i*2000, 50,200, 100);
            fillellipse(300+i*2000, 120,200, 100);
            }
            //
			//rectangle(100,450,900,600);
			//rectangle(8900,450,9000,600);

}
void gravity(){
            if(y+radius+46<b ){
                cleardevice();
                body(x,y,radius);
                delay(1);
                dy=dy+g;
            }
}
void background(){
	
        // background color according to coordinates / using as different environment scene
        if(x>7000){setbkcolor(BLACK);}
        else if(x>5000&&x<6000){setbkcolor(LIGHTGRAY);}
        else if(x>6000&&x<7000){setbkcolor(LIGHTMAGENTA);}
        else if(x>4000&&x<5000){setbkcolor(RED);}
        else if(x>2000&&x<3000){setbkcolor(LIGHTBLUE);}
        else if(x>1000&&x<2000){setbkcolor(CYAN);}
        else{setbkcolor(2);}
}
void collision()
{
    end:
    // using spike as an obstacle
    for(int j=1; j<50; j++){
    if( (y+radius+40>=b-20 && x-8>=30+300*j && x-8<=70+300*j)|| (y+radius+40>=b-20 && x+8>=30+300*j && x+8<=70+300*j)){
                main:
                setbkcolor(RED);
                cleardevice();
                settextstyle(4,HORIZ_DIR,4);
                outtextxy(screenwidth-1050,400, "You died.Press enter to restart" );
                if(GetAsyncKeyState(VK_RETURN)&1){ // setting it as a restart mechanism
                    dx=67;                         // placing player in starting position
                    posx=0;                        // resetting the coordinate of camera tracker for player in intital position
                    screenwidth=1566;
                    setviewport(posx,0,screenwidth,screenheight, 1);//placing the camera track in intial position
                    goto end;                       // exiting loop to continue the main program
                    cleardevice();}
                if(GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState(VK_UP)){// making the player stand still to show the "you are dead "message
                    goto main;
                }
    }}
}
int main(){
    // initializing velocity
    dx=x;
    dy=y;
    //
    initwindow(10000,700);   
    loading_screen();
    cleardevice();
    while (1)
    {
    start();
    if(GetAsyncKeyState(VK_RETURN)){
        while(1)
        {   
            // to remove flickering / buffering of the images seen in window
            setactivepage(page);
            setvisualpage(1-page);
            //
            cleardevice();
            body(x,y,radius);
            background();
            gravity();
            collision();
            if(GetAsyncKeyState(VK_RIGHT)&& x<=9000){      // max position that a player can go right is upto 9000
                dx+=10;                                    // player moves right direction with 10 velocity
            if(x>400 && x<=8000){                          //camera track only starts after player coordinate is greater than 400
            setviewport(posx,0,screenwidth,screenheight, 1);//camera track
            posx=posx-tx;
            screenwidth+=tx;}
            }
            if(GetAsyncKeyState(VK_LEFT)&&x>=17 && x<=9000){// min position that a player can go left is upto 17
                dx-=10;                                     // player moves left direction with 10 velocity
            if(x>300&&x<=8000){
            setviewport(posx,0,screenwidth,screenheight, 1);
            posx=posx+tx;
            screenwidth-=tx;}
            }
            if(GetAsyncKeyState(VK_UP)&1 && y>=500){        // max position that a player can go up is upto 9000
                for(int i=0; i<100;i++){
                dy-=1;                                      // loop for jump
                }
                delay(10);
                
                if(GetAsyncKeyState(VK_RIGHT)){dx+=3;}  
                if(GetAsyncKeyState(VK_LEFT)){dx-=3;}  
            }
            
                
            page=1-page;
            x=dx;
            y=dy;
            if(GetAsyncKeyState(VK_ESCAPE)){break;}
            delay(1);
        }
        
            cleardevice();
    }
    if(GetAsyncKeyState(VK_ESCAPE)){break;}
    }
    getch();
    //closegraph();
}
