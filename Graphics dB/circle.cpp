#include <iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	initwindow(800,800);
	for(int i=300; i<=500 ;i++)
	{
		cleardevice();
		circle(300,i,200);
		delay(10);
//		goto start;
	
	}
	getch();
	return 0;
}

