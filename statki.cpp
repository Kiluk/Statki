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
    void drawShipUp(int mast,int row,int column)
    {

        for (int k=1; k<=mast;k++)
        {
            table[row-k+1][column] = 1 ;
            placedShips[row-k+1][column] = true;
            if(column!=9)
            {
                placedShips[row-k+1][column+1] = true;
            }
            if(column!=0)
            {
                placedShips[row-k+1][column-1] = true;
            }
        }
        if(row!=9)
        {
        placedShips[row+1][column] = true;
            if(column!=9)
            {
                placedShips[row+1][column+1] = true;
            }
            if(column!=0)
            {
                placedShips[row+1][column-1] = true;
            }
        }
        if(column!=9)
        {
            placedShips[row-mast][column] = true;
            if(column!=9)
            {
                placedShips[row-mast][column+1] = true;
            }
            if(column!=0)
            {
                placedShips[row-mast][column-1] = true;
            }
        }
    }

    void drawShipDown(int mast,int row,int column)
    {
        for (int k=1; k<=mast;k++)
        {
            table[row+k-1][column]=1;
            placedShips[row+k-1][column] = true;
            if(column!=9)
            {
                placedShips[row+k-1][column+1] = true;
            }
            if(column!=0)
            {
                placedShips[row+k-1][column-1] = true;
            }
        }
        if(row!=0)
        {
            placedShips[row-1][column] = true;
            if(column!=9)
            {
                placedShips[row-1][column+1] = true;
            }
            if(column!=0)
            {
                placedShips[row-1][column-1] = true;
            }
        }
            if(row<=9-mast)
        {
            placedShips[row+mast][column] = true;
            if(column!=9){placedShips[row+mast][column+1] = true;}
            if(column!=0){placedShips[row+mast][column-1] = true;}
        }
    }

    void drawShipRight(int mast,int row,int column)
    {
        for (int k=1; k<=mast;k++)
        {
            table[row][column+k-1]=1;
            placedShips[row][column+k-1] = true;
            if(row!=9)
            {
                placedShips[row+1][column+k-1] = true;
            }
            if(row!=0)
            {
                placedShips[row-1][column+k-1]=  true;
            }
        }
        if(column!=0)
        {
            placedShips[row][column-1] = true;
            if(row!=9)
            {
                placedShips[row+1][column-1] = true;
            }
            if(row!=0)
            {
                placedShips[row-1][column-1] = true;
            }
        }
        if(column<9-mast)
        {
            placedShips[row][column+mast] = true;
            if(row!=9)
            {
                placedShips[row+1][column+mast] = true;
            }
            if(row!=0)
            {
                placedShips[row-1][column+mast] = true;
            }
        }
    }

    void drawShipLeft(int mast,int row,int column)
{
    for (int k=1; k<=mast;k++)
    {
        table[row][column-k+1]=1;
        placedShips[row][column-k+1] = true;
        if(row!=9){placedShips[row+1][column-k+1] = true;}
        if(row!=0){placedShips[row-1][column-k+1] = true;}
    }
    if(column!=9)
    {
        placedShips[row][column+1] = true;
        if(row!=9)
        {
            placedShips[row+1][column+1] = true;
        }
        if(row!=0)
        {
            placedShips[row-1][column+1] = true;
        }
    }
    if(column>=mast)
    {
        placedShips[row][column-mast] = true;
        if(row!=9)
        {
            placedShips[row+1][column-mast] = true;
        }
        if(row!=0)
        {
            placedShips[row-1][column-mast] = true;
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

    for(int i=1; i<N/2; i++) 
    {	 
        int row , column;
        for ( int licznik = 0; licznik < i; licznik++)
        {
            
            do
            {
                row = (rand() % 10); 
                column = (rand() % 10);
            } while (computerBoard.canIDrowHere(((N/2)-i),row,column) != true );
        
        if(column <=(N/2-i-1))
        {
            if(row<=(N/2-i-1))
            {
                if( (rand()%2) != 0 && computerBoard.canIDrowDown((N/2-i),row,column) == true)
                {
                    computerBoard.drawShipDown((N/2-i),row,column);
                }
                else
                {
                    computerBoard.drawShipRight((N/2-i),row,column);
                }
            }
            else if (row>=(N/2+i+1))
            {
                if((rand()%2) != 0 && computerBoard.canIDrowUp((N/2-i),row,column) == true)
                {
                    computerBoard.drawShipUp((N/2-i),row,column);
                }
                else
                {
                    computerBoard.drawShipRight((N/2-i),row,column);
                }
            }
            else
            {
                int count = (rand()%3);
                
                if(count == 2 && computerBoard.canIDrowRight((N/2-i),row,column) == false)
                {
                count--;
                } 
                if(count == 1 && computerBoard.canIDrowUp((N/2-i),row,column) == false)
                {
                count-- ;
                }
                if (count == 0 && computerBoard.canIDrowDown((N/2-i),row,column) == false)
                {
                count = 2;
                }
                switch (count)
                {
                    
                    case 0:
                    computerBoard.drawShipDown((N/2-i),row,column);
                    break;
                    case 1:
                    computerBoard.drawShipUp((N/2-i),row,column);
                    break;
                    case 2:
                    computerBoard.drawShipRight((N/2-i),row,column);
                    break;
                }
            }
        }
        else if (column>=(N/2+i+1))
            {
                if(row<=(N/2-i-1))
                {
                    if( (rand()%2) != 0 && computerBoard.canIDrowDown((N/2-i),row,column) == true)
                    {
                        computerBoard.drawShipDown((N/2-i),row,column);
                    }
                    else
                    {
                        computerBoard.drawShipLeft((N/2-i),row,column);
                    }
                }
                else if (row>=(N/2+i+1))
                {
                    if((rand()%2) != 0 && computerBoard.canIDrowUp((N/2-i),row,column) == true)
                    {
                        computerBoard.drawShipUp((N/2-i),row,column);
                    }
                    else
                    {
                        computerBoard.drawShipLeft((N/2-i),row,column);
                    }
                }
                else
                {
                    int count = (rand()%3);
                    if(count == 2 && computerBoard.canIDrowLeft((N/2-i),row,column) == false)
                    {
                        count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowDown((N/2-i),row,column) == false)
                    {
                        count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowUp((N/2-i),row,column) == false)
                    {
                        count = 2;
                    }
                        
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipUp((N/2-i),row,column);
                            break;
                            case 1:
                            computerBoard.drawShipDown((N/2-i),row,column);
                            break;
                            case 2:
                            computerBoard.drawShipLeft((N/2-i),row,column);
                            break;
                        }
                }
                
            }
            else
            {
                    if(row<=(N/2-i-1))
                    {
                        int count = (rand()%3);
                    
                        if(count == 2 && computerBoard.canIDrowDown((N/2-i),row,column) == false)
                        {
                            count--;
                        } 
                        if(count == 1 && computerBoard.canIDrowRight((N/2-i),row,column) == false)
                        {
                            count-- ;
                        }
                        if (count == 0 && computerBoard.canIDrowLeft((N/2-i),row,column) == false)
                        {
                            count = 2;
                        }
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipLeft((N/2-i),row,column);
                            break;
                            case 1:
                            computerBoard.drawShipRight((N/2-i),row,column);
                            break;
                            case 2:
                            computerBoard.drawShipDown((N/2-i),row,column);
                            break;
                        }
                    }
                    else if (row>=N-((N/2-i)))
                    {
                         int count = (rand()%3);
                    
                    if(count == 2 && computerBoard.canIDrowRight((N/2-i),row,column) == false)
                    {
                    count--;
                    } 
                    if(count == 1 && computerBoard.canIDrowLeft((N/2-i),row,column) == false)
                    {
                    count-- ;
                    }
                    if (count == 0 && computerBoard.canIDrowUp((N/2-i),row,column) == false)
                    {
                    count = 2;
                    }
                        switch (count)
                        {
                            case 0:
                            computerBoard.drawShipUp((N/2-i),row,column);
                            break;
                            case 1:
                            computerBoard.drawShipLeft((N/2-i),row,column);
                            break;
                            case 2:
                            computerBoard.drawShipRight((N/2-i),row,column);
                            break;
                        }
                    }
                    else
                    {
                        int count = (rand()%4);
                    
                    if(count == 3 && computerBoard.canIDrowLeft((N/2-i),row,column) == false)
                    {
                    count--;
                    } 
                    if(count == 2 && computerBoard.canIDrowRight((N/2-i),row,column) == false)
                    {
                    count-- ;
                    }
                    if(count == 1 && computerBoard.canIDrowUp((N/2-i),row,column) == false)
                    {
                    count--;
                    }
                    if(count == 0 && computerBoard.canIDrowDown((N/2-i),row,column) == false)
                    {
                    count = 3;
                    }
                        switch ((rand()%4))
                        {
                            case 0:
                            computerBoard.drawShipDown((N/2-i),row,column);
                            break;
                            case 1:
                            computerBoard.drawShipUp((N/2-i),row,column);
                            break;
                            case 2:
                            computerBoard.drawShipRight((N/2-i),row,column);
                            break;
                            case 3:
                            computerBoard.drawShipLeft((N/2-i),row,column);
                            break;
                        }
                    }
                
            }
        }    
    }
    computerBoard.drawBoard(); 
    return 0;
}
