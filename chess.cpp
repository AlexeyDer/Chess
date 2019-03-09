#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>

using namespace std;

#define SIZE 8
#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

int main()
{
    cout << "Wecome you in my Chess GAME!\n\n";
    cout << "X - White\n- is black\n";

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
                    cout << "X";
                }
                cout << "     ";
            }
            cout << " " << i << endl;
         }       

         char c = cin.get();
         if(c == 27)
            break;       
    }

    ofstream myfile("/home/alexeyder/Documents/progs/Chess/Website.html");

    myfile.open ("/home/alexeyder/Documents/progs/Chess/Website.html");
    myfile << "<!DOCTYPE html><html><head></head><body>" << endl;
    myfile << "<h1>Wecome you in my Chess GAME!\n\n</h1>";

    myfile << "</body></html>";
    myfile.close();

    return 0;
}