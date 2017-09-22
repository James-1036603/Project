#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Engine myEngine;
    myEngine.start();
    cout << "Hello world!" << endl;
    return 0;
}
