#include <iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int gotoRowCol(int rpos, int cpos);

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

int left_to_right(int sr,int sc,int c_dim,char ch)
{
    for(sc;sc<=c_dim;sc++)
    {
        gotoRowCol(sr,sc);

        cout<<ch<<endl;
    }
}
int top_to_bottom(int sr,int c_dim,int r_dim,char ch)
{
    for(sr ;sr<=r_dim;sr++)
    {
        gotoRowCol(sr,c_dim);

        cout<<ch<<endl;
    }
}

int right_to_left(int r_dim,int c_dim,int sc,char ch)
{
    for(c_dim;c_dim>=sc;c_dim--)
    {
        gotoRowCol(r_dim,c_dim);

        cout<<ch<<endl;
    }
}
int bottom_to_top(int r_dim,int sc,int sr,char ch)
{
    for(r_dim;r_dim>=sr;r_dim--)
    {
        gotoRowCol(r_dim,sc);

        cout<<ch<<endl;
    }
}
void init (int B[],int dim)
    {

        for (int i=0;i<dim*dim;i++)
            {
                B[i]=(i+1);

            }
    }


void printboard(int sr,int sc,int r_dim,int c_dim,int B[],int dim,char ch)
{
int f=((dim*dim)-1);
for(int j=1;j<=10;j++)
{
    for(int i=1;i<=10;i++)
        {
            left_to_right(sr,sc,c_dim,ch);
            top_to_bottom(sr,c_dim,r_dim,ch);
            right_to_left(r_dim,c_dim,sc,ch);
            bottom_to_top(r_dim,sc,sr,ch);
            int num_c=sc+4;
            int num_r=r_dim-4;
            gotoRowCol (num_r,num_c);
            cout<<B[f];
            sc=c_dim;
            c_dim=c_dim+10;
            f--;

        }
sr=r_dim;
r_dim+=8;
sc=0,c_dim=10;
}


}


void details()
{
    int r=5,c=110;
    gotoRowCol(r,c);
    cout <<"Welcome to Snakes and Ladder game!"<<endl;
    r+=5;
    gotoRowCol(r,c);
    cout<<"ladder 1 :  20 -----> 48 "<<endl;
    r+=2;
    gotoRowCol(r,c);
    cout<<"ladder 2 :  34 -----> 76 "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"snake 1  :  57 -----> 27 "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"snake 2  :  99 -----> 13 "<<endl;
    r+=4;
    gotoRowCol(r,c);
    cout<<"symbol for player 1= * "<<endl;
     r+=2;
    gotoRowCol(r,c);
    cout<<"symbol for player 2= % "<<endl;
    gotoRowCol(70,4);
    cout<<"SL_1";
     gotoRowCol(46,24);
    cout<<"EL_1";
     gotoRowCol(54,64);
    cout<<"SL_2";
    gotoRowCol(22,44);
    cout<<"EL_2";

     gotoRowCol(38,34);
    cout<<"SS_1";
     gotoRowCol(62,34);
    cout<<"ES_1";
    gotoRowCol(6,14);
    cout<<"SS_2";

      gotoRowCol(70,74);
    cout<<"ES_2";

     gotoRowCol(50,110);
    cout<<"press (E) or (e) to end game";


}

int diceroll(int ri,int ci)
{
 int d=0;

    while(!kbhit())
    {

        gotoRowCol(ri+2,110);
       d=(rand() % 6)+1;
      cout<<d;


    }
    getch();
    return d;

}

void update_position(char turn,int c_dim,int & ri,int & ci,int dim,int r_dim,int player_score,int number)
{
int mod=player_score/dim;
ci=ci-((player_score%c_dim)*c_dim)*10;

if(ci<6)
{
    ci=106;
    ri=74;
    ci=ci-((player_score%c_dim)*10);
    ri=ri-(r_dim*mod);
}




    gotoRowCol(ri,ci);
    cout<<turn;
}
void remove_position(char turn,int c_dim,int ri,int ci,char ch)
{

    gotoRowCol(ri,ci);
    cout<<ch;
}
int askformove(int turn)
{
   int ri=24,ci=110;
   int num;
 if (turn==0)
 {
gotoRowCol(ri,ci);
cout<<"player "<<(turn+1)<<" turn:"<<endl;
 num=diceroll(ri,ci);
}
if( turn==1)
    {
        ri=ri+4;
        gotoRowCol(ri,ci);
cout<<"player "<<(turn+1)<<" turn:"<<endl;
num=diceroll(ri,ci);
    }
    return num;
}

void change_turn(int & turn)
    {
        turn = (turn+1)%2;
    }

void snakes(int & player_score)
{
    if(player_score==57)
    {
        player_score=27;
    }
    if(player_score==99)
    {
        player_score=13;
    }
}

void ladders(int & player_score)
{
    if(player_score==20)
    {
        player_score=48;
    }
    if(player_score==34)
    {
        player_score=76;
    }
}



void player1(char turnS,int c_dim,int r_dim,int & ri,int & ci,int dim,int turn,int & times,int & player_1_score,char ch)
{


    int number=askformove(turn);
     char c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
    if(number==6 && times==1)
    {
        times=2;
        number=0;
        remove_position(turnS,c_dim,ri, ci, ch);
        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_1_score,number);

            do{
            number=askformove(turn);

             c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
            player_1_score+=number;

            }
            while(number==6);
            if(player_1_score>=18)
            {
                player_1_score=player_1_score-18;
            }

        remove_position(turnS,c_dim,ri, ci, ch);

        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_1_score,number);
    }
    else if(times==2)
    {
        player_1_score+=number;
         if(player_1_score>100)
            {
                player_1_score=player_1_score-number;
            }


        if(player_1_score==100)
            {
                gotoRowCol(32,110);
                cout<<"player 1 total score: "<<player_1_score<<endl;
                gotoRowCol(35,110);
                cout<<"player 1 won!!";
                exit(1);
            }

        remove_position(turnS,c_dim,ri, ci, ch);
        if(number==6)
        {
            int x=0;
            do{
            number=askformove(turn);
            x++;
             c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
            player_1_score+=number;

            }
            while(number==6);
            if(x==3)
            {
                player_1_score=player_1_score-18;
            }
        }
        snakes(player_1_score);
        ladders(player_1_score);
         if(player_1_score>100)
            {
                player_1_score=player_1_score-number;
            }


        if(player_1_score==100)
            {
                gotoRowCol(32,110);
                cout<<"player 1 total score: "<<player_1_score<<endl;
                gotoRowCol(35,110);
                cout<<"player 1 won!!";
                exit(1);
            }
        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_1_score,number);

    }
    gotoRowCol(32,110);
    cout<<"player 1 total score: "<<player_1_score<<endl;
}




void player2(char turnS,int c_dim,int r_dim,int & ri,int & ci,int dim,int turn,int & times,int & player_2_score,char ch)
{


    int number=askformove(turn);
     char c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
    if(number==6 && times==1)
    {
        times=2;
        number=0;
        remove_position(turnS,c_dim,ri, ci, ch);
        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_2_score,number);

            do{
            number=askformove(turn);

             c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
            player_2_score+=number;

            }
            while(number==6);
            if(player_2_score>=18)
            {
                player_2_score=player_2_score-18;
            }

        remove_position(turnS,c_dim,ri, ci, ch);
        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_2_score,number);
    }
    else if(times==2)
    {
        player_2_score+=number;
        if(player_2_score>100)
            {
                player_2_score=player_2_score-number;
            }


        if(player_2_score==100)
            {
                gotoRowCol(34,110);
                cout<<"player 2 total score: "<<player_2_score<<endl;
                gotoRowCol(35,110);
                cout<<"player 2 won!!";
                exit(1);
            }

        remove_position(turnS,c_dim,ri, ci, ch);
         if(number==6)
        {
            int x=0;
            do{
            number=askformove(turn);
             c=getch();
            if (c=='E'|| c=='e')
            {
                exit(1);
            }
            x++;
            getch();
            player_2_score+=number;
            }
            while(number==6);
            if(x==3)
            {
                player_2_score=player_2_score-18;
            }
        }
            snakes(player_2_score);
            ladders(player_2_score);
            if(player_2_score>100)
            {
                player_2_score=player_2_score-number;
            }
            if(player_2_score==100)
            {
                gotoRowCol(34,110);
                cout<<"player 2 total score: "<<player_2_score<<endl;
                gotoRowCol(35,110);
                cout<<"player 2 won!!";
                exit(1);
            }



        update_position(turnS,c_dim,ri,ci,dim,r_dim,player_2_score,number);
    }
    gotoRowCol(34,110);
    cout<<"player 2 total score: "<<player_2_score<<endl;
}




void writer(int turn,int player_1_score,int player_2_score,int timesP1,int timesP2,int ri1,int ci1,int ri2,int ci2)
{
    ofstream R("project_file.txt");
    R<<turn<<' ' ;
     R<<endl;
      R<<player_1_score<<' ' ;
     R<<endl;
      R<<player_2_score<<' ' ;
     R<<endl;
      R<<timesP1<<' ' ;
     R<<endl;
      R<<timesP2<<' ' ;
     R<<endl;
      R<<ri1<<' ' ;
     R<<endl;
      R<<ci1<<' ' ;
     R<<endl;
      R<<ri2<<' ' ;
     R<<endl;
      R<<ci2<<' ' ;
     R<<endl;


}

void reader(int & turn,int & player_1_score,int & player_2_score,int & timesP1,int & timesP2,int & ri1,int & ci1,int & ri2,int & ci2)
{
    ifstream RR("project_file.txt");
    RR>>turn;

      RR>>player_1_score;

      RR>>player_2_score;

      RR>>timesP1;

      RR>>timesP2;

      RR>>ri1;

      RR>>ci1;

      RR>>ri2;

      RR>>ci2 ;


}

int main()
{

int turn=0,player_1_score=0,player_2_score=0,dim=10,sr=0,sc=0,r_dim=8,c_dim=10;
char p_symbol[2]={'*','%'};
int board[dim*dim];
init(board,dim);
char ch=219,ch1=' ',var;

cout<<"press N for new game"<<endl;
cout<<"press L for saved game"<<endl;
cin>>var;
system("cls");
int ri1=74,ci1=108,ri2=76,ci2=106, number=0;
int timesP1=1,timesP2=1;

if(var=='L'|| var=='l')
{
    reader(turn,player_1_score,player_2_score,timesP1,timesP2,ri1,ci1,ri2,ci2);
}
printboard(sr,sc,r_dim,c_dim,board,dim,ch);
details();
do{
if(turn==0)
{

player1(p_symbol[turn],c_dim,r_dim,ri1,ci1,dim,turn,timesP1,player_1_score,ch1);
writer(turn,player_1_score,player_2_score,timesP1,timesP2,ri1,ci1,ri2,ci2);
change_turn(turn);

}


if(turn==1)
{
 player2(p_symbol[turn],c_dim,r_dim,ri2,ci2,dim,turn,timesP2,player_2_score,ch1);
 writer(turn,player_1_score,player_2_score,timesP1,timesP2,ri1,ci1,ri2,ci2);
change_turn(turn);
}

}
while(true);
}
