#pragma once
#include "GraphicsLib.h"
 class TicTacToe
{
public:
     int arrayField[3][3] = {
         {0,0,0},
         {0,0,0},
         {0,0,0}
     };

     GraphicsLib graphicsLib;
     const int PlayerNum = 1;
     const int CPUNum = 2;
     bool isTurnPlayer = true;
     int cpuNumtemp;
     char* moveField(int position);

     void drawMap();

     void DrawMoveOnMap(int position);

     int CPUmode();

     bool WinHuman();
     bool WinCPU();

     void resetField();
     void restart();

     int getStep(int i ,int j);
};

