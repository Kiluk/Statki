#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;


int main()
{
    int N = 10;
    int planszaGracza[N-1][N-1]={0};
    int planszaKomputera[N-1][N-1]={0};

    srand((unsigned) time(NULL));

    vector < int > wiersze;
    vector < int > kolumny;

    for(int i=1; i<N/2; i++)
    {
        bool zajetePola[N-1][N-1]={false};	 
        wiersze.clear();
        kolumny.clear();
        for (int licznik = 0; licznik < i; licznik++)
        {
            wiersze.push_back( (rand() % 10) );
            kolumny.push_back( (rand() % 10) );
        }
         for ( int licznik = 0; licznik < i; licznik++)
         {
            if(wiersze[licznik]-(N/2-i)<=0)
                {
                    if(kolumny[licznik]<=N/2-i)
                    {
                        if( int j=(rand()%2) != 0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]+k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                        }
                        else if(j==0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                        }
                    }
                    else if (kolumny[licznik]>=N-(N/2-i))
                    {
                        if( int j=(rand()%2) != 0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]+k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                        }
                        else if(j==0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                        }
                    }
                    else
                    {
                        switch (int j=(rand()%3))
                        {
                            case 0:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]+k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                            case 1:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                            break;
                            case 2:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                            break;
                        }
                    }
                }
            else if (wiersze[licznik]+(N/2-i)>N)
                {
                    if(kolumny[licznik]<=N/2-i)
                    {
                        if( int j=(rand()%2) != 0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                        }
                        else if(j==0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                        }
                    }
                    else if (kolumny[licznik]>=N-(N/2-i))
                    {
                        if( int j=(rand()%2) != 0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                        }
                        else if(j==0)
                        {
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                        }
                    }
                    else
                    {
                        switch (int j=(rand()%3))
                        {
                            case 0:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                            case 1:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                            break;
                            case 2:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                            break;
                        }
                    }
                    
                }
            else
            {
                    if(kolumny[licznik]<=N/2-i)
                    {
                        switch (int j=(rand()%3))
                        {
                            case 0:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                            case 1:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                            break;
                            case 2:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]+k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                        }
                    }
                    else if (kolumny[licznik]>=N-(N/2-i))
                    {
                        switch (int j=(rand()%3))
                        {
                            case 0:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                            case 1:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                            break;
                            case 2:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]+k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]+k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                        }
                    }
                    else
                    {
                        switch (int j=(rand()%4))
                        {
                            case 0:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]-k][kolumny[licznik]]=1;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]+1]=true;
                                zajetePola[wiersze[licznik]-k][kolumny[licznik]-1]=true;
                            }
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                            case 1:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]+k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]+k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]+k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]+(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+(N/2-i)]=true;
                            break;
                            case 2:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]+1][kolumny[licznik]-(N/2-i)]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-(N/2-i)]=true;
                            break;
                            case 3:
                            for (int k=0; k<=(N/2-i);k++)
                            {
                                planszaGracza[wiersze[licznik]][kolumny[licznik]-k]=1;
                                zajetePola[wiersze[licznik]][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]+1][kolumny[licznik]-k]=true;
                                zajetePola[wiersze[licznik]-1][kolumny[licznik]-k]=true;
                            }
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]-1][kolumny[licznik]-1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]+1]=true;
                            zajetePola[wiersze[licznik]+(N/2-i)][kolumny[licznik]-1]=true;
                            break;
                        }
                    }
                
            }    
         }
    }
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<planszaKomputera[i][j]<<" "; 
		}
		cout<<endl;
	}
    
    return 0;
}


