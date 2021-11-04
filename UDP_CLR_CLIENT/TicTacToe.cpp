#include "TicTacToe.h"
#include <iostream>
#include <random>


char* TicTacToe::moveField(int position) {
    int temp = 1;
  
    for (size_t i = 0; i < sizeof(arrayField) / sizeof(*arrayField); i++)
    {
        for (size_t j = 0; j < sizeof(arrayField) / sizeof(*arrayField); j++)
        {
            
            if (position == temp && isTurnPlayer ) {
                if (arrayField[i][j] == PlayerNum || arrayField[i][j] == CPUNum) return (char*)"this cell is busy.Try again";
                arrayField[i][j] = PlayerNum;
                DrawMoveOnMap(position);

                isTurnPlayer = false;
                delay(1000);
                if (!isTurnPlayer) {
                    cpuNumtemp = CPUmode();
                    DrawMoveOnMap(cpuNumtemp);
                }
               
            isTurnPlayer = true;

            }

            temp++;
        }

       
    }
    if (WinHuman()  && WinCPU()) {
        graphicsLib.DrawText(10, 10, 2, 10, 255, 255, 255, "tie");
        return (char*)"tie";
    }
    else if (WinHuman() == true) {
        graphicsLib.DrawText(10, 10, 2, 10, 255, 255,255, "HUMAN WINS");
        return (char*)"human wins";
    }
    else if (WinCPU() == true) {
        graphicsLib.DrawText(10, 10, 2, 10, 255, 255, 255, "ROBOT WINS");
        return (char*)"robot wins";
    }

    return (char*)"game move success";
  
}
void TicTacToe::drawMap() {
 
    int step = 100;
    for (size_t i = 0; i < 2; i++)
    {
        graphicsLib.FillRectangle(250, 190 + step, 750, 200 + step, 255, 255, 255);
        step += step;
    }
    step = 100;
    for (size_t i = 0; i < 2; i++)
    {
        graphicsLib.FillRectangle(300 + step, 200, 310 + step, 500  , 255, 255, 255);
        step += 200;
    }

}

void TicTacToe::DrawMoveOnMap(int position) {
      
    int r = isTurnPlayer ? 255 : 0;
    int g = isTurnPlayer ? 0 : 0;
    int b = isTurnPlayer ? 0 : 255;
    switch (position) {
    case 1:
        graphicsLib.DrawText(300, 190, 0, 10 , r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 2:
        graphicsLib.DrawText(490, 190, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 3:
        graphicsLib.DrawText(660, 190, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 4:
        graphicsLib.DrawText(300, 310, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 5:
        graphicsLib.DrawText(490, 310, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 6:
        graphicsLib.DrawText(660, 310, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 7:
        graphicsLib.DrawText(300, 410, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 8:
        graphicsLib.DrawText(490, 410, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    case 9:
        graphicsLib.DrawText(660, 410, 0, 10, r, g, b, isTurnPlayer ? "X" : "O");
        break;
    }
}

int TicTacToe::CPUmode() {

    int temp = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);
    int rand_row;
    int rand_col;
    while (true) {

         rand_row = dist(gen);
         rand_col = dist(gen);

      

             if (arrayField[rand_row][rand_col] == 0) {
                 arrayField[rand_row][rand_col] = CPUNum ;
                 break;
             }
           
   
       

    }
   
    for (size_t i = 0; i < sizeof(arrayField) / sizeof(*arrayField); i++)
    {
        for (size_t j = 0; j < sizeof(arrayField) / sizeof(*arrayField); j++)
        {
            if (rand_row == i && rand_col == j) {
                
                
                return temp;
            }

            temp++;
        }
       
    }

  
}

bool TicTacToe::WinHuman() {
    if (arrayField[0][0] == PlayerNum && arrayField[0][1] == PlayerNum && arrayField[0][2] == PlayerNum ||
        arrayField[1][0] == PlayerNum && arrayField[1][1] == PlayerNum && arrayField[1][2] == PlayerNum ||
        arrayField[2][0] == PlayerNum && arrayField[2][1] == PlayerNum && arrayField[2][2] == PlayerNum ||

        arrayField[0][0] == PlayerNum && arrayField[1][0] == PlayerNum && arrayField[2][0] == PlayerNum ||
        arrayField[0][1] == PlayerNum && arrayField[1][1] == PlayerNum && arrayField[2][1] == PlayerNum ||
        arrayField[0][2] == PlayerNum && arrayField[1][2] == PlayerNum && arrayField[2][2] == PlayerNum ||

        arrayField[0][0] == PlayerNum && arrayField[1][1] == PlayerNum && arrayField[2][2] == PlayerNum ||
        arrayField[0][2] == PlayerNum && arrayField[1][1] == PlayerNum && arrayField[2][0] == PlayerNum
        )
    {
        return true;
    }
    else {
        return false;
    }
}
bool TicTacToe::WinCPU() {
    if (arrayField[0][0] == CPUNum && arrayField[0][1] == CPUNum && arrayField[0][2] == CPUNum ||
        arrayField[1][0] == CPUNum && arrayField[1][1] == CPUNum && arrayField[1][2] == CPUNum ||
        arrayField[2][0] == CPUNum && arrayField[2][1] == CPUNum && arrayField[2][2] == CPUNum ||

        arrayField[0][0] == CPUNum && arrayField[1][0] == CPUNum && arrayField[2][0] == CPUNum ||
        arrayField[0][1] == CPUNum && arrayField[1][1] == CPUNum && arrayField[2][1] == CPUNum ||
        arrayField[0][2] == CPUNum && arrayField[1][2] == CPUNum && arrayField[2][2] == CPUNum ||

        arrayField[0][0] == CPUNum && arrayField[1][1] == CPUNum && arrayField[2][2] == CPUNum ||
        arrayField[0][2] == CPUNum && arrayField[1][1] == CPUNum && arrayField[2][0] == CPUNum
        )
    {
        return true;
    }
    else {
        return false;
    }

}

void TicTacToe::resetField() {
    for (size_t i = 0; i < sizeof(arrayField) / sizeof(*arrayField); i++)
    {
        for (size_t j = 0; j < sizeof(arrayField) / sizeof(*arrayField); j++)
        {
            arrayField[i][j] = 0;
        }


    }
}

void TicTacToe::restart() {
    graphicsLib.ClearDisplay();
    resetField();
    delay(100);
    drawMap();
    drawMap();
    
}

int TicTacToe::getStep(int iIndex , int jIndex) {
    int temp = 1;

    for (size_t i = 0; i < sizeof(arrayField) / sizeof(*arrayField); i++)
    {
        for (size_t j = 0; j < sizeof(arrayField) / sizeof(*arrayField); j++)
        {

            if (arrayField[iIndex][jIndex] == arrayField[i][j]) {
                return temp;
            }

            temp++;
        }


    }
}