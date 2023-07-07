#include <iostream>
#include <fstream>
#include <cmath>
#include "Quiz.h"

//Standard Konstruktor
Quiz::Quiz() : m_size(0), m_total(0), m_quiz(nullptr) {}

void Quiz::addSize(unsigned int newSize)
{
    //Neuen Array im dynamischen Speicher erstellen
    Question *tempQuiz = new Question[m_size+newSize];
    //Alle Objekte aus dem alten Array in den neuen kopieren
    for(int i=0; i<m_size; i++)
    {
        // "=" Operator aufrufen -> Objekt Question kopieren
        tempQuiz[i] = m_quiz[i];
    }
    //Alten Array löschen
    delete m_quiz;
    //Pointer auf den neu angelegten Array zeigen lassen
    m_quiz = tempQuiz;
    //Größen Variable updaten
    m_size = m_size+newSize;
    return;
}

//Ladefunktion
void Quiz::load(string inputDataFileName)
{
    // Den angegebenen File einlsen
    ifstream readFile(inputDataFileName);
    if(!readFile)
    {
        // Fehler wenn nicht gefunden
        cout << "Lesefehler: Datei \"" << inputDataFileName << "\" existiert nicht!" << endl;
        exit(EXIT_FAILURE);
    }

    /*
        Es gibt drei verschieden Zustände
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
            addQuestion(konstruktorInput[0], konstruktorInput[1], konstruktorInput[2], konstruktorInput[3], konstruktorInput[4]);
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
        writeFile << m_quiz[i].m_question;
        writeFile << "\n";
        for(int a=0; a<4; a++)
        {
            writeFile << "#A\n";
            writeFile << m_quiz[i].m_answers[a];
            writeFile << "\n";
        }
        writeFile << "#E\n\n";
    }
    writeFile << "#ENDFILE";
    writeFile.close();
}

void Quiz::addQuestion(string inputQuestion, string inputRightAnswer, string inputFalseAnswer1, string inputFalseAnswer2, string inputFalseAnswer3)
{
    //Wenn Array voll -> Größe um Eins erhöhen
    if(m_size == m_total) addSize(1);
    m_quiz[m_total].setValues(inputQuestion, inputRightAnswer, inputFalseAnswer1, inputFalseAnswer2, inputFalseAnswer3);
    m_total++;
}

//Hauptfunktion des Quizes
void Quiz::start()
{
    cout << endl;
    printLogo();

    //Eingabemaske
    while(true)
    {
        midPrint("[Main-Menu]",'=');
        midPrint("[Geladenen Fragen: "+ to_string(m_total)+"]");
        midPrint("Quiz Spielen [s]");
        midPrint("Fragen auflisten [l]");
        midPrint("Fragen erstellen [h]");
        midPrint("Fragen loeschen [d]");
        midPrint("Beenden [b]");
        cout << "(Auswahl:) " ;
        char eingabe;
        cin >> eingabe;
        if(eingabe=='s' || eingabe=='S')
        {
            cout << endl << "================================================================================" << endl;
            m_quiz->m_askedQuestions=0;
            m_quiz->m_rightAnswers=0;

            //Verkettete Liste durch Zufall druchgehen und Fragen abfragen
            //Zufällige Reihenfolge erstellen
            int randomArray[m_size];
            for(int i=0; i<m_size; i++)
            {
                randomArray[i] = i;
            }
            //Reihenfolge durchmischen
            for(int i=0; i<m_size; i++)
            {
                int randIndex = rand() % m_size;
                int tmp = randomArray[i];
                randomArray[i] = randomArray[randIndex];
                randomArray[randIndex] = tmp;
            }

            for(int i=0; i<m_total; i++)
            {
                if(!m_quiz[randomArray[i]].ask()) break;
            }

            //Statistik ausgeben
            double grade = ((double)m_quiz->m_rightAnswers/(double)m_quiz->m_askedQuestions)*100;
            grade = ceil(grade*100.0) / 100.0;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "Richtige Fragen: " << m_quiz->m_rightAnswers << "/" << m_quiz->m_askedQuestions << endl;
            cout << "Note: " << grade << "%" << endl;

        }
        else if(eingabe=='h' || eingabe=='H')
        {
            addNew();
        }
        else if(eingabe=='d' || eingabe=='D')
        {
            deleteOld();
        }
        else if(eingabe=='b' || eingabe=='B')
        {
            return;
        }
        else if(eingabe=='l' || eingabe=='L')
        {
            listQuestions();
        }
        else
        {
            cout << "Ungueltige Eingabe!" << endl;
        }
    }
}

void Quiz::addNew()
{
    while(true)
    {
        string input[5];
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Neue Frage: ";
        cin.ignore();
        getline(cin,input[0]);
        cout << "Richtige Antwort: ";
        getline(cin,input[1]);
        cout << "Falsche Antwort: ";
        getline(cin,input[2]);
        cout << "Falsche Antwort: ";
        getline(cin,input[3]);
        cout << "Falsche Antwort: ";
        getline(cin,input[4]);
        addQuestion(input[0],input[1],input[2],input[3],input[4]);

        while(true)
        {
            char eingabe;
            cout << "Weitere Frage hinzufuegen [y/n]? ";
            cin >> eingabe;
            if(eingabe=='n')
            {
                save();
                return;
            }
            else if(eingabe=='y') break;
            else cout << "Eingabefehler!" << endl;
        }
    }
}

void Quiz::deleteOld()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    if(m_total==0)
    {
        cout << "Es wurden keine Fragen gefunden!" << endl;
        return;
    }
    int tempCount=1;
    cout << "Welche Frage soll geloescht werden?" << endl << endl;
    for(int i=0; i<m_total; i++)
    {
        cout << "[" << tempCount << "] " << m_quiz[i].m_question << endl;
        tempCount++;
    }
    while(true)
    {
        cout << endl << "(Antwort:) ";
        string answer;
        cin >> answer;
        try
        {
            //Falls eine Zahl angegeben wurde die nicht zwischen 1 und 4 liegt
            if(stoi(answer)>m_total || stoi(answer)<1)
            {
                cout << "{Eingabefehler: Bitte gib eine Zahl zwischen 1 und " << m_total << " ein!}" << endl;
            }
            else
            {
                //Angegebene Zahl löschen
                //Neuen Array erschaffen (nur einen kleiner)
                int indexDelete = stoi(answer)-1;
                //Wenn nur eine Frage existiert gesamtes Array löschen
                if(m_size==1)
                {
                    delete m_quiz;
                }
                else
                {
                    Question *tempArray = new Question[m_size-1];
                    //Alles links von der Zahl in den Array kopieren
                    for(int i=0; i<indexDelete; i++)
                    {
                        tempArray[i] = m_quiz[i];
                    }
                    //Alles rechts von der Zahl in den Array kopieren
                    for(int i=indexDelete+1; i<m_size; i++)
                    {
                        tempArray[i-1] = m_quiz[i];
                    }
                    delete m_quiz;
                    m_quiz = tempArray;
                }
                m_size--;
                m_total--;
                save();
                return;
            }
        }
        catch(invalid_argument const& ex)
        {
            cout << "{Eingabefehler: Bitte gib eine Zahl ein!}" << endl;
        }
    }
}

void Quiz::midPrint(string text, char symbol)
{
    for(unsigned int i=0; i< (LINE_LENGTH/2)-(text.length()/2)-1; i++)
    {
        cout << symbol;
    }
    cout << text;
    for(unsigned int i=0; i< (LINE_LENGTH/2)-(text.length()/2); i++)
    {
        cout << symbol;
    }
    cout << endl;
}

void Quiz::listQuestions()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Liste aller Fragen:" << endl;
    for(int i=0; i<m_total; i++)
    {
        cout << "[" << i+1 << "] " << m_quiz[i].m_question << endl;
    }
}

//Logo auf der Konsole ausgeben
void Quiz::printLogo()
{
    string line;
    ifstream logo;
    logo.open("logo.txt");
    if(logo.is_open())
    {
        while (getline(logo, line))
        {
            cout << line << endl;
        }
        logo.close();
    }
    else
    {
        cout << "No Logo inmplemented!" << endl;
    }
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
