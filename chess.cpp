#include <iostream>
#include <cstdlib>
#include <ostream>
#include <fstream>

using namespace std;

#define SIZE 8

int main()
{
    while(1)
    {
        ofstream myfile("/home/alexeyder/Documents/progs/Chess/hello.txt");
        myfile << "Wecome you in my Chess GAME!\n\n";
        myfile << "X - White\n- is black\n";
        myfile << "   A     B     C     D     E     F     G     H\n\n";
        
        for(int i = 1; i <= SIZE; i++)
         {  
            myfile << "   ";
            for(int j = 1; j <= SIZE;j++)
            {
                if((i+j) % 2)
                {
                    myfile << "-";
                } else {
                    myfile << "X";
                }
                myfile << "     ";
            }
            myfile << " " << i << endl;
         }       
         
         
         char c = cin.get();
         if(c == 27)
         {
            myfile.close();
            break;  
         }     

    }

    return 0;
}