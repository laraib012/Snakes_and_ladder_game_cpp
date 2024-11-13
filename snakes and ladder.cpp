#include <iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
using namespace std;
int gotoRowCol(int rpos, int cpos);
int sleep(int m);
int gotoRowCol(int rpos, int cpos)
{
int xpos=cpos, ypos = rpos;
COORD scrn;
HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
scrn.X = cpos;
scrn.Y = rpos;
int r=SetConsoleCursorPosition(hOuput, scrn);
return r;
}
int sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {
        }
}

int left_to_right(int sr,int sc,int c,char ch)
{
    for(sc;sc<=c;sc++)
    {
        gotoRowCol(sr,sc);

        cout<<ch<<endl;
    }
}
int top_to_bottom(int sr,int c,int r,char ch)
{
    for(sr ;sr<=r;sr++)
    {
        gotoRowCol(sr,c);

        cout<<ch<<endl;
    }
}

int right_to_left(int r,int c,int sc,char ch)
{
    for(c;c>=sc;c--)
    {
        gotoRowCol(r,c);

        cout<<ch<<endl;
    }
}
int bottom_to_top(int r,int sc,int sr,char ch)
{
    for(r;r>=sr;r--)
    {
        gotoRowCol(r,sc);

        cout<<ch<<endl;
    }
}
void init (int B[],int dim)
    {
        //int c=1;
        for (int i=0;i<dim*dim;i++)
            {
                B[i]=(i+1);
               // c++;
            }
    }


void printboard(int sr,int sc,int r,int c,int Gr,int Gc,int B[],int dim,char ch)
{
int f=((dim*dim)-1);
for(int j=1;j<=10;j++)
{
    for(int i=1;i<=10;i++)
        {
            left_to_right(sr,sc,c,ch);
            top_to_bottom(sr,c,r,ch);
            right_to_left(r,c,sc,ch);
            bottom_to_top(r,sc,sr,ch);
            Gc=sc+4;
            Gr=r-4;
            gotoRowCol (Gr,Gc);
            cout<<B[f];
            sc=c;
            c=c+10;
            f--;
            //counter--;
        }
sr=r;
r+=8;
sc=0,c=10;
}


}


void details()
{
    int r=5,c=110;
    gotoRowCol(r,c);
    cout <<"Welcome to Snakes and Ladder game!"<<endl;
    r+=5;
    gotoRowCol(r,c);
    cout<<"ladder 1 from 9 to 31 "<<endl;
    r+=2;
    gotoRowCol(r,c);
    cout<<"ladder 2 from 20 to 38 "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"snake 1 from 39 to 26 "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"snake 2 from 99 to 13 "<<endl;
    r+=2;
    gotoRowCol(r,c);
    cout<<"symbol for player 1= * "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"symbol for player 2= % "<<endl;


}

void diceroll()
{


    while(!kbhit())
    {
        gotoRowCol(24,110);
      int d=(rand() % 6)+1;
      cout<<d;
    }
    getch();
}


int main()
{

//int Size =50;
//int B[Size];
//array_1(B,Size);
int dim=10;
int board[dim*dim];
init(board,dim);
//printboard(board,dim);
int sr=0,sc=0,r=8,c=10,Gr,Gc,counter=100;
char ch=219;
printboard(sr,sc,r,c,Gr,Gc,board,dim,ch);
details();
diceroll();
}

