#include <iostream>
using namespace std;

int main(){
    const double PI = 3.14;

    cout << PI << "\n";
    cout << "TOM" << "\n";

    int x = 1, y = 2;

    std::printf("%i", x + y);

    if (x < y)
    {
        std::printf("x ist kleiner als y\n");
    }

    for(int b = 0; b < 5; b++)
    {
        std::printf("#");
        for(int c = 0; c < b; c++)
        {
            std::printf();
        }
    }

}