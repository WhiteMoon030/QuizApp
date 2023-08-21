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
    //Neues Quiz hinzufügen
    m.addQuiz("default");

    //Aus der Datei "data.txt" alle Fragen in den dynamischen Speicher Laden
    m.load(0, "data.txt");
    m.start();

    //Alle Fragen aus dem dynamischen Speicher in die Datei "data.txt" speichern
    m.save(0, "data.txt");
    return 0;
}
