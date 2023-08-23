#include <stdlib.h>
#include <time.h>

#include "Menu.h"

using namespace std;

int main()
{
    //Jedes Mal neue Zufallszahlen erzeugen
    srand(time(NULL));

    //Ein Menu Objekt erstellen
    Menu m;
    m.start();

    return 0;
}
