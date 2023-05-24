//#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    system("color e0");
    cout << "Can You Catch Sonic?" << endl;
    cout << "Can you find which block Sonic is hiding under? Keep your eyes peeled for that speedy hedgehog and try to find him after the blocks stop moving" << endl;
    CreateWindow(TEXT("button"), TEXT("Easy"), WS_CHILD | WS_VISIBLE, 10, 10, 80, 25, NULL, NULL, NULL, NULL);
    return 0;
} 
