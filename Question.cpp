#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include "Question.h"

//Fragenzähler
int Question::count=0;

//Konstruktor
Question::Question(string inputQuestion, string inputRight, string inputFalse1, string inputFalse2, string inputFalse3)
    : next(nullptr), m_question(inputQuestion), m_answers{inputRight, inputFalse1, inputFalse2, inputFalse3}
{
    count++;
}

//Destruktor
Question::~Question()
{
    count--;
}

//Fragenausgabe
void Question::ask()
{
    //Frage auf der Konsole ausgeben
    cout << m_question << endl << endl;

    //Random Reihenfolge erzeugen
    int sequence[4] = {0,1,2,3};
    for(int i=0; i<4; i++)
    {
        int randIndex = rand()%4;
        int temp = sequence[i];
        sequence[i] = sequence[randIndex];
        sequence[randIndex] = temp;
    }

    //Random Reihenfolge der Antworten ausgeben
    for(int i=0; i<4; i++)
    {
        cout << "[" << i+1 << "] "<< m_answers[sequence[i]] << endl;
    }
    cout << endl;

    //Richtige Antwort in der Sequenz suchen
    int rightIndex;
    for(int i=0; i<4; i++)
    {
        if(sequence[i]==0)
        {
            rightIndex = i;
            break;
        }
    }

    //Antwort abfragen
    while(true)
    {
        string answer;
        cout << "(Antwort:) ";
        cin >> answer;
        //Feedback geben
        try
        {
            //Falls eine Zahl angegeben wurde die nicht zwischen 1 und 4 liegt
            if(stoi(answer)>4 || stoi(answer)<1)
            {
                cout << "{Eingabefehler: Bitte gib eine Zahl zwischen 1 und 4 ein!}" << endl;
            }else
            {
                //Wenn die eingegeben Zahl dem Index der richtigen Antwort entspricht -> Antwort richtig
                if(stoi(answer)-1==rightIndex) cout << "[Richtig!]" << endl;
                else cout << "[Falsch! Richtige Antwort: " << m_answers[0] << "]" << endl;
                break;
            }
        }
        catch(invalid_argument const& ex)
        {
            cout << "{Eingabefehler: Bitte gib eine Zahl ein!}" << endl;
        }
    }


    cout << "------------------------------------------------------------------------" << endl;
    Sleep(1000);
    return;
}
