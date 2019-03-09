#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 8
#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

int main()
{
    cout << "Wecome you in my Chess GAME!\n\n";
    cout << "The DECK:\n\n ";

    while(1)
    {
        cout << "   A     B     C     D     E     F     G     H\n\n";
        
        for(int i = 1; i <= SIZE; i++)
         {  
            cout << "   ";
            for(int j = 1; j <= SIZE;j++)
            {
                if((i+j) % 2)
                {
                    cout << "-";
                } else {
                    cout << "x";
                }
                cout << "     ";
            }
            cout << " " << i << endl;
         }       

         char c = cin.get();
         if(c == 27)
            exit(0);
         
    }
    return 0;
}