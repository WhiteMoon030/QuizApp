#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Question.h"
#include "Quiz.h"

using namespace std;

int main()
{
    //Jedes Mal neue Zufallszahlen erzeugen
    srand(time(NULL));

    //Ein Quiz Objekt erstellen
    Quiz q;

    //Aus der Datei "data.txt" alle Fragen in den dynamischen Speicher Laden
    q.load("data.txt");
    q.start();

    //Alle Fragen aus dem dynamischen Speicher in die Datei "data.txt" speichern
    q.save("data.txt");
    return 0;
}
