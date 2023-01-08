#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
const int N = 10;

class Board
{
  private:
    int table[N][N]={0};
    bool placedShips[N][N]={false};

  public:
    bool canIDrowHere(int sizeOfShip,int row,int column)
    {
        bool canI = true;
        for (int x = 0; x < sizeOfShip; x++)
        {
            if(placedShips[row][column] == true || placedShips[row][column+x] == true || placedShips[row+x][column] == true || placedShips[row-x][column] == true || placedShips[row][column-x] == true )
            {
                canI = false;
            }
        }
        return canI;
        
    }

    bool canIDrowRight(int sizeOfShip,int row,int column)
    {
        bool canI = true;
        for (int x = 0; x < sizeOfShip; x++)
        {
            if(placedShips[row][column+x] == true)
            {
                canI = false;
            }
        }
        return canI;
    }
    bool canIDrowLeft(int sizeOfShip,int row,int column)
    {
        bool canI = true;
        for (int x = 0; x < sizeOfShip; x++)
        {
            if(placedShips[row][column-x] == true )
            {
                canI = false;
            }
        }
        return canI;
    }
    bool canIDrowUp(int sizeOfShip,int row,int column)
    {
        bool canI = true;
        for (int x = 0; x < sizeOfShip; x++)
        {
            if(placedShips[row-x][column] == true)
            {
                canI = false;
            }
        }
        return canI;
    }
    bool canIDrowDown(int sizeOfShip,int row,int column)
    {
        bool canI = true;
        for (int x = 0; x < sizeOfShip; x++)
        {
            if(placedShips[row+x][column] == true)
            {
                canI = false;
            }
        }
        return canI;
    }
    void drawShipUp(int mast,int index,vector< int > row,vector< int > column)
    {

        for (int k=1; k<=mast;k++)
        {
            table[row[index]-k+1][column[index]] = 1 ;
            placedShips[row[index]-k+1][column[index]] = true;
            if(column[index]!=9)
            {
                placedShips[row[index]-k+1][column[index]+1] = true;
            }
            if(column[index]!=0)
            {
                placedShips[row[index]-k+1][column[index]-1] = true;
            }
        }
        if(row[index]!=9)
        {
        placedShips[row[index]+1][column[index]] = true;
            if(column[index]!=9)
            {
                placedShips[row[index]+1][column[index]+1] = true;
            }
            if(column[index]!=0)
            {
                placedShips[row[index]+1][column[index]-1] = true;
            }
        }
        if(column[index]!=9)
        {
            placedShips[row[index]-mast][column[index]] = true;
            if(column[index]!=9)
            {
                placedShips[row[index]-mast][column[index]+1] = true;
            }
            if(column[index]!=0)
            {
                placedShips[row[index]-mast][column[index]-1] = true;
            }
        }
    }

    void drawShipDown(int mast,int index,vector< int > row,vector< int > column)
    {
        for (int k=1; k<=mast;k++)
        {
            table[row[index]+k-1][column[index]]=1;
            placedShips[row[index]+k-1][column[index]] = true;
            if(column[index]!=9)
            {
                placedShips[row[index]+k-1][column[index]+1] = true;
            }
            if(column[index]!=0)
            {
                placedShips[row[index]+k-1][column[index]-1] = true;
            }
        }
        if(row[index]!=0)
        {
            placedShips[row[index]-1][column[index]] = true;
            if(column[index]!=9)
            {
                placedShips[row[index]-1][column[index]+1] = true;
            }
            if(column[index]!=0)
            {
                placedShips[row[index]-1][column[index]-1] = true;
            }
        }
            if(row[index]<=9-mast)
        {
            placedShips[row[index]+mast][column[index]] = true;
            if(column[index]!=9){placedShips[row[index]+mast][column[index]+1] = true;}
            if(column[index]!=0){placedShips[row[index]+mast][column[index]-1] = true;}
        }
    }

    void drawShipRight(int mast,int index,vector< int > row,vector< int > column)
    {
        for (int k=1; k<=mast;k++)
        {
            table[row[index]][column[index]+k-1]=1;
            placedShips[row[index]][column[index]+k-1] = true;
            if(row[index]!=9)
            {
                placedShips[row[index]+1][column[index]+k-1] = true;
            }
            if(row[index]!=0)
            {
                placedShips[row[index]-1][column[index]+k-1]=  true;
            }
        }
        if(column[index]!=0)
        {
            placedShips[row[index]][column[index]-1] = true;
            if(row[index]!=9)
            {
                placedShips[row[index]+1][column[index]-1] = true;
            }
            if(row[index]!=0)
            {
                placedShips[row[index]-1][column[index]-1] = true;
            }
        }
        if(column[index]<9-mast)
        {
            placedShips[row[index]][column[index]+mast] = true;
            if(row[index]!=9)
            {
                placedShips[row[index]+1][column[index]+mast] = true;
            }
            if(row[index]!=0)
            {
                placedShips[row[index]-1][column[index]+mast] = true;
            }
        }
    }

    void drawShipLeft(int mast,int index,vector< int > row,vector< int > column)
{
    for (int k=1; k<=mast;k++)
    {
        table[row[index]][column[index]-k+1]=1;
        placedShips[row[index]][column[index]-k+1] = true;
        if(row[index]!=9){placedShips[row[index]+1][column[index]-k+1] = true;}
        if(row[index]!=0){placedShips[row[index]-1][column[index]-k+1] = true;}
    }
    if(column[index]!=9)
    {
        placedShips[row[index]][column[index]+1] = true;
        if(row[index]!=9)
        {
            placedShips[row[index]+1][column[index]+1] = true;
        }
        if(row[index]!=0)
        {
            placedShips[row[index]-1][column[index]+1] = true;
        }
    }
    if(column[index]>=mast)
    {
        placedShips[row[index]][column[index]-mast] = true;
        if(row[index]!=9)
        {
            placedShips[row[index]+1][column[index]-mast] = true;
        }
        if(row[index]!=0)
        {
            placedShips[row[index]-1][column[index]-mast] = true;
        }
    }
}

    void drawBoard()
    {
        for(int i=0;i<N;i++)
	    {
            for(int j=0;j<N;j++)
            {
                cout<<table[i][j]<<" "; 
            }
            cout<<endl;
	    }
    
    }
};


int main()
{
    Board computerBoard;
    Board playerBoard;

    srand((unsigned) time(NULL));

    vector < int > row;
    vector < int > column;

    for(int i=1; i<N/2; i++) 
    {	 
        row.clear();
        column.clear();

        for (int licznik = 0; licznik < i; licznik++)
        {
            int r,c;
            if (licznik > 0 )
            {
                do
            {
                r = (rand() % 10);
                c = (rand() % 10);
            } while (computerBoard.canIDrowHere(((N/2)-i),r,c) != true || ((r == row.back()) && (c == column.back())));
            }
            else
            {
            do
            {
                r = (rand() % 10); 
                c = (rand() % 10);
            } while (computerBoard.canIDrowHere(((N/2)-i),r,c) != true );
            }
          
                row.push_back(r);
                column.push_back(c); 
        }

         for ( int licznik = 0; licznik < i; licznik++)
         {
            if(column[licznik]<=(N/2-i-1))
            {
                if(row[licznik]<=(N/2-i-1))
                {
                    if( (rand()%2) != 0 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == true)
                    {
                        computerBoard.drawShipDown((N/2-i),licznik,row,column);
                    }
                    else
                    {
                        computerBoard.drawShipRight((N/2-i),licznik,row,column);
                    }
                }
                else if (row[licznik]>=(N/2+i+1))
                {
                    if((rand()%2) != 0 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == true)
                    {
                        computerBoard.drawShipUp((N/2-i),licznik,row,column);
                    }
                    else
                    {
                        computerBoard.drawShipRight((N/2-i),licznik,row,column);
                    }
                }
                else
                {
                    int count = (rand()%3);
                    
                    if(count == 2 && computerBoard.canIDrowRight((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count = 2;
                    }
                    switch (count)
                    {
                        
                        case 0:
                        computerBoard.drawShipDown((N/2-i),licznik,row,column);
                        break;
                        case 1:
                        computerBoard.drawShipUp((N/2-i),licznik,row,column);
                        break;
                        case 2:
                        computerBoard.drawShipRight((N/2-i),licznik,row,column);
                        break;
                    }
                }
            }
            else if (column[licznik]>=(N/2+i+1))
                {
                    if(row[licznik]<=(N/2-i-1))
                    {
                        if( (rand()%2) != 0 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == true)
                        {
                            computerBoard.drawShipDown((N/2-i),licznik,row,column);
                        }
                        else
                        {
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                        }
                    }
                    else if (row[licznik]>=(N/2+i+1))
                    {
                        if((rand()%2) != 0 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == true)
                        {
                            computerBoard.drawShipUp((N/2-i),licznik,row,column);
                        }
                        else
                        {
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                        }
                    }
                    else
                    {
                        int count = (rand()%3);
                    
                    if(count == 2 && computerBoard.canIDrowLeft((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count = 2;
                    }
                        
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipUp((N/2-i),licznik,row,column);
                            break;
                            case 1:
                            computerBoard.drawShipDown((N/2-i),licznik,row,column);
                            break;
                            case 2:
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                            break;
                        }
                    }
                    
                }
            else
            {
                    if(row[licznik]<=(N/2-i-1))
                    {
                        int count = (rand()%3);
                    
                    if(count == 2 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowRight((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowLeft((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count = 2;
                    }
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                            break;
                            case 1:
                            computerBoard.drawShipRight((N/2-i),licznik,row,column);
                            break;
                            case 2:
                            computerBoard.drawShipDown((N/2-i),licznik,row,column);
                            break;
                        }
                    }
                    else if (row[licznik]>=N-((N/2-i)))
                    {
                         int count = (rand()%3);
                    
                    if(count == 2 && computerBoard.canIDrowRight((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowLeft((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count = 2;
                    }
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipUp((N/2-i),licznik,row,column);
                            break;
                            case 1:
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                            break;
                            case 2:
                            computerBoard.drawShipRight((N/2-i),licznik,row,column);
                            break;
                        }
                    }
                    else
                    {
                        int count = (rand()%4);
                    
                    if(count == 3 && computerBoard.canIDrowLeft((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    } 
                    if(count == 2 && computerBoard.canIDrowRight((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count-- ;
                    }
                    if(count == 1 && computerBoard.canIDrowUp((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count--;
                    }
                    if(count == 0 && computerBoard.canIDrowDown((N/2-i),row[licznik],column[licznik]) == false)
                    {
                    count = 3;
                    }
                        switch ((rand()%4))
                        {
                            case 0:
                            computerBoard.drawShipDown((N/2-i),licznik,row,column);
                            break;
                            case 1:
                            computerBoard.drawShipUp((N/2-i),licznik,row,column);
                            break;
                            case 2:
                            computerBoard.drawShipRight((N/2-i),licznik,row,column);
                            break;
                            case 3:
                            computerBoard.drawShipLeft((N/2-i),licznik,row,column);
                            break;
                        }
                    }
                
            }    
         }
    }
    computerBoard.drawBoard();
    return 0;
}