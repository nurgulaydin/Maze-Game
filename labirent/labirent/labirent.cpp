#include <iostream>            
#include <Windows.h>       
#include<conio.h>          
using namespace std;
char giris;        

int labmap[19][24] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					  {0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1},
					  {0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,0,1},
					  {1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,1},
					  {1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1},
					  {1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1},
					  {1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1},
					  {1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,1},
					  {1,0,1,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1},
					  {1,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,1,0,1},
					  {1,0,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,1},
					  {1,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1},
					  {1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1},
					  {1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1},
					  {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,1,0,1},
					  {1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,0,0,2},
					  {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,2},
					  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};



void labr()         
{
	system("color 5");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			switch (labmap[i][j])
			{
			case 0:
				cout << " ";
				break;

			case 1:
				cout << char(219);     
				break;
			case 2:
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
}


void gotoXY(int x, int y)      { 
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
}


void move()
{
	int x = 0;
	int y = 1;
	int x2 = 0;
	int y2 = 1;
	while (true)
	{

		gotoXY(x2, y2);
		cout << " ";

		gotoXY(x, y);   
		cout << char(175);

		giris = _getch();   

		x2 = x;
		y2 = y;

		switch (giris)
		{
		case 'w':
			y -= 1;
			break;
		case 's':
			y += 1;
			break;
		case 'a':
			x -= 1;
			break;
		case 'd':
			x += 1;
			break;
		}


		if (labmap[y][x] == 1)  
		{
			x = x2;
			y = y2;
		}

		else if (labmap[y][x] == 2) 
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << " Tebrikler !! "<< endl;
			system("color 2");
			
		}
	}
}

int main()
{
	labr();
	move();
}