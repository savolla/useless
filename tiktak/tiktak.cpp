/*
	project: console clock
	author: savolla
	date: 19/06/2019
*/
#include <iostream>
#include <chrono>
#include <thread>
using std::cout;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

// clock graphic
unsigned char watch[11][19] {
{' ',' ',' ',' ',' ',' ',' ',' ',' ','C',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','B',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','2',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ','9',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ','3'},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ','8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','4',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ','7',' ',' ',' ',' ',' ',' ',' ','5',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ','6',' ',' ',' ',' ',' ',' ',' ',' '}};

void updateGraphicalClock(int hour, int minute, int second)
{
/*
 Map of graphical clock
------------------------
 0123456789ABCDEFGH 
0         C                            
1     B   o   1      
2      o  *  o        
3  Ao   * + *   o2   
4    * + + + + *         
5 9o*+    x    +*o3  
6    * + + + + *                       
7  8o   * + *   o4   
8      o  *  o       
9     7   o   5      
A         6          
*/                                    
	switch(second)
	{
		case 0: {watch[2][6] =' ';watch[1][9] ='o';}break;
		case 5: {watch[1][9] =' ';watch[2][12]='o';}break;
		case 10:{watch[2][12]=' ';watch[3][15]='o';}break; 
		case 15:{watch[3][15]=' ';watch[5][16]='o';}break;
		case 20:{watch[5][16]=' ';watch[7][15]='o';}break;
		case 25:{watch[7][15]=' ';watch[8][12]='o';}break;
		case 30:{watch[8][12]=' ';watch[9][9] ='o';}break;
		case 35:{watch[9][9] =' ';watch[8][6] ='o';}break;
		case 40:{watch[8][6] =' ';watch[7][3] ='o';}break;
		case 45:{watch[7][3] =' ';watch[5][2] ='o';}break;
		case 50:{watch[5][2] =' ';watch[3][3] ='o';}break;
		case 55:{watch[3][3] =' ';watch[2][6] ='o';}break;
		default:; break;
	}
	switch(minute)
	{
		case 0: {watch[3][7] =' ';watch[2][9] ='*';}break;
		case 5: {watch[2][9] =' ';watch[3][11]='*';}break;
		case 10:{watch[3][11]=' ';watch[4][14]='*';}break; 
		case 15:{watch[4][14]=' ';watch[5][15]='*';}break;
		case 20:{watch[5][15]=' ';watch[6][14]='*';}break;
		case 25:{watch[6][14]=' ';watch[7][11]='*';}break;
		case 30:{watch[7][11]=' ';watch[8][9] ='*';}break;
		case 35:{watch[8][9] =' ';watch[7][7] ='*';}break;
		case 40:{watch[7][7] =' ';watch[6][4] ='*';}break;
		case 45:{watch[6][4] =' ';watch[5][3] ='*';}break;
		case 50:{watch[5][3] =' ';watch[4][4] ='*';}break;
		case 55:{watch[4][4] =' ';watch[3][7] ='*';}break;
		default:; break;
	}
	switch(hour)
	{
		case 0 :{watch[4][8] =' ';watch[3][9] ='+';}break;
		case 1 :{watch[3][9] =' ';watch[4][10]='+';}break;
		case 2 :{watch[4][10]=' ';watch[4][12]='+';}break; 
		case 3 :{watch[4][12]=' ';watch[5][14]='+';}break;
		case 4 :{watch[5][14]=' ';watch[6][12]='+';}break;
		case 5 :{watch[6][12]=' ';watch[6][10]='+';}break;
		case 6 :{watch[6][10]=' ';watch[7][9] ='+';}break;
		case 7 :{watch[7][9] =' ';watch[6][8] ='+';}break;
		case 8 :{watch[6][8] =' ';watch[6][6] ='+';}break;
		case 9 :{watch[6][6] =' ';watch[5][4] ='+';}break;
		case 10:{watch[5][4] =' ';watch[4][6] ='+';}break;
		case 11:{watch[4][6] =' ';watch[4][8] ='+';}break;
		default:; break;
	}
}

void showGraphicalClock()
{		
	for(auto c : watch)
	{
		cout << c << "\x0a";
	}
}

void showFormattedTime(int h, int m, int s)
{
	// hours
	if(h < 10) { cout <<"\x0A     " <<'0' <<h <<":"; }
	else { cout <<"\x0A     " << h << ":"; }
	// minutes
	if(m < 10) { cout << '0' << m <<":"; }
	else { cout << m <<":"; }
	// seconds
	if(s < 10) { cout << '0' <<s <<"\x0A"; }
	else { cout << s << "\x0A"; }
}

void clearScreen()
{
	for(unsigned i=0; i!=150; ++i)
	{
		cout << "\x0A";
	}
}

int main(void)
{
	while(1)
	{
		unsigned h=0,m=0,s=0;
		for(;h != 12; ++h)
		{
			for(;m != 60; ++m)
			{
				for(; s != 60; ++s)
				{
					clearScreen();
					updateGraphicalClock(h,m,s);
					showGraphicalClock();
					showFormattedTime(h,m,s);
					sleep_for(1s);
				}
			}
		}
	}
	return 0;
}
