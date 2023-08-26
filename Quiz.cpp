#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Quiz.h"
#include "Question.h"
#include "QuestionChoice.h"
#include "QuestionInsert.h"

//Standard Konstruktor
Quiz::Quiz() : m_name("default"), m_size(0), m_total(0), m_quiz(nullptr) {}

void Quiz::addSize(unsigned int newSize)
{
    //Neuen Array im dynamischen Speicher erstellen
    Question **tempQuiz = new Question*[m_size+newSize];
    //Alle Objekte aus dem alten Array in den neuen kopieren
    for(int i=0; i<m_size; i++)
    {
        //Pointer auf die Dynamisch angelegten Objekte kopieren
        tempQuiz[i] = m_quiz[i];
    }
    //Alten Pointer Array löschen
    delete[] m_quiz;
    //Pointer auf den neu angelegten Array zeigen lassen
    m_quiz = tempQuiz;
    //Größen Variable updaten
    m_size = m_size+newSize;
    return;
}

//Ladefunktion
void Quiz::load(string inputDataFileName)
{
    // Den angegebenen File einlesen
    ifstream readFile(inputDataFileName);
    if(!readFile)
    {
        // Fehler wenn nicht gefunden
        cout << "Lesefehler: Datei \"" << inputDataFileName << "\" existiert nicht!" << endl;
        exit(EXIT_FAILURE);
    }

    /*
        Es gibt drei verschieden Zust�nde
        0 - Neue Frage einlesen
        1 - Richtige Antwort einlesen
        2 - Frage einlesen abgeschlossen
    */

    // Zeilenweises einlesen
    string line;
    unsigned int loadCount=0;
    //Datei durchgehen und Größe vom Array ermitteln
    while(getline(readFile,line))
    {
        if(!line.compare(QUESTION_ID)) loadCount++;
    }
    //Größe des Quiz-Arrays setzen
    addSize(loadCount);

    //Vor dem erneuten einlesen getline clearen
    readFile.clear();
    readFile.seekg(0);

    int status=0;
    int firstAnswer=0;
    //Eingelesene
    string konstruktorInput[5];
    while(getline(readFile,line))
    {
        //Status setzen wenn spezielle Symbole eingelesen werden
        if(!line.compare(QUESTION_ID))
        {
            status=0;
            continue;
        }
        if(!line.compare(ANSWER_ID) && firstAnswer==0)
        {
            firstAnswer=1;
            status=1;
            continue;
        }
        if(!line.compare(END_ID))
        {
            status=2;
            continue;
        }
        if(!line.compare(ENDFILE_ID))
        {
            break;
        }

        //Je nach Status Variablen setzen
        if(status==0)
        {
            konstruktorInput[0]=line;
        }
        else if(status==1)
        {
            if(firstAnswer==1)
            {
                konstruktorInput[1]=line;
                firstAnswer++;
            }
            else
            {
                if(!line.compare(ANSWER_ID)) continue;
                switch(firstAnswer)
                {
                case 2:
                {
                    konstruktorInput[2]=line;
                    firstAnswer++;
                    break;
                }
                case 3:
                {
                    konstruktorInput[3]=line;
                    firstAnswer++;
                    break;
                }
                case 4:
                {
                    konstruktorInput[4]=line;
                    break;
                }
                }
            }
        }
        else
        {
            //Wenn Ende erreicht neue Frage der Liste hinzufügen
            //Wenn firstAnswer = 2 -> Frage mit nur einer Antwort
            if(firstAnswer==2) addQuestion(konstruktorInput[0], konstruktorInput[1]);
	    //Sonst -> Frage mit 4 Antwort Möglichkeiten
	    else addQuestion(konstruktorInput[0], konstruktorInput[1], konstruktorInput[2], konstruktorInput[3], konstruktorInput[4]);
            firstAnswer=0;
        }
    }
}

void Quiz::save(string inputDataFileName)
{
    ofstream writeFile;
    if(!writeFile)
    {
        // Fehler wenn nicht gefunden
        cout << "Schreibfehler: Datei \"" << inputDataFileName << "\" existiert nicht!" << endl;
        exit(EXIT_FAILURE);
    }
    //Daten in der Datei löschen
    writeFile.open(inputDataFileName, std::ofstream::out | std::ofstream::trunc);

    //Alle Objekte aus dem Array in eine Datei speichern
    for(int i=0; i<m_total; i++)
    {
        writeFile << "#F\n";
        writeFile << m_quiz[i]->m_question;
        writeFile << "\n";
	writeFile << m_quiz[i]->getAnswerSave();
        writeFile << "#E\n\n";
    }
    writeFile << "#ENDFILE";
    writeFile.close();
}

void Quiz::addQuestion(string inputQuestion, string inputRightAnswer)
{
    //Wenn Array voll -> Größe um Eins erhöhen
    if(m_size == m_total) addSize(1);
    m_quiz[m_total] = new QuestionInsert(inputQuestion, inputRightAnswer);
    m_total++;
}

void Quiz::addQuestion(string inputQuestion, string inputRightAnswer, string inputFalseAnswer1, string inputFalseAnswer2, string inputFalseAnswer3)
{
    //Wenn Array voll -> Größe um Eins erhöhen
    if(m_size == m_total) addSize(1);
    m_quiz[m_total] = new QuestionChoice(inputQuestion, inputRightAnswer, inputFalseAnswer1, inputFalseAnswer2, inputFalseAnswer3);
    m_total++;
}

void Quiz::convertData(string fileName)
{
    ifstream readFile(fileName);
    string line;

    if(!readFile)
    {
        cout << "Lesefehler: Datei \"" << fileName << "\" existiert nicht!" << endl;
        return;
    }

    while(getline(readFile, line))
    {
        //Wenn keine Leerzeile die nächsten 5 Zeilen in Variablen speichern und neue Frage automatisch anlegen
        if(!line.length() == 0)
        {
            string inputsForQuestion[5];
            for(int i=0; i<5; i++)
            {
                inputsForQuestion[i] = line;
                getline(readFile, line);
            }
            addQuestion(inputsForQuestion[0], inputsForQuestion[1], inputsForQuestion[2], inputsForQuestion[3], inputsForQuestion[4]);
        }
    }
}

void Quiz::delArray(int index)
{
    //Wenn kein index angegeben -> alle Objekte im Array löschen
    if(index==-1)
    {
	//Erst alle dynamisch erzeugten Elemente löschen
	for(int i=0; i<m_size; i++)
	{
	    delete m_quiz[i];
	}
    }else //Sonst nur das Objekt am angegeben Index
    {
	if(index<0 || index>=m_size) return; //Wenn Index außerhalb des Arrays -> gar nichts tun
	delete m_quiz[index];
    }
    //Pointer Array löschen
    delete[] m_quiz;
    m_quiz = nullptr;
}
