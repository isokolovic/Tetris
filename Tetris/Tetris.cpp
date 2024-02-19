// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

wstring tetromino[7];
int nFieldWidth;
int nFieldHeight;
unsigned char* pField = nullptr;

int Rotate(int px, int py, int r) 
{
    switch (r % 4)
    {
    case 0: 
        return py * 4 + px; //0 degrees
    case 1:
        return 12 + py - (px * 4); //90 degrees
    case 2:
        return 15 - (py * 4) - px; //180 degrees
    case 3:
        return 3 - py + (px * 4); //270 degrees
    }
    return 0;
}

int main()
{
    // Create assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X .");
    
    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"... .");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X."); 
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X .");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    pField = new unsigned char[nFieldWidth * nFieldHeight]; //Create play field buffer

    for (int x = 0; x < nFieldWidth; x++) // Create board boundary
    {
        for (int y = 0; x < nFieldHeight; y++) 
        {            
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
        }
    }
}