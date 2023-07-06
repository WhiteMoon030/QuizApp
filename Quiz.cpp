#include <iostream>
#include <fstream>
#include "Quiz.h"

//Konstruktor
Quiz::Quiz() : head(nullptr), tail(nullptr) {}

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

    // Zeilenweises einlesen
    string line;

    /*
        Es gibt drei verschieden Zustände
        0 - Neue Frage einlesen
        1 - Richtige Antwort einlesen
        2 - Frage einlesen abgeschlossen
    */

    int status=0;
    int firstAnswer=0;
    string lineQuestion;
    string lineAnswerRight;
    string lineAnswerFalse1;
    string lineAnswerFalse2;
    string lineAnswerFalse3;
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

        //Je nach Status Variablen setzen
        if(status==0)
        {
            lineQuestion=line;
        }
        else if(status==1)
        {
            if(firstAnswer==1)
            {
                lineAnswerRight=line;
                firstAnswer++;
            }
            else
            {
                if(!line.compare(ANSWER_ID)) continue;
                switch(firstAnswer)
                {
                case 2:
                {
                    lineAnswerFalse1=line;
                    firstAnswer++;
                    break;
                }
                case 3:
                {
                    lineAnswerFalse2=line;
                    firstAnswer++;
                    break;
                }
                case 4:
                {
                    lineAnswerFalse3=line;
                    break;
                }
                }

            }
        }
        else
        {
            //Wenn Ende erreicht neue Frage der Liste hinzufügen
            addQuestion(lineQuestion, lineAnswerRight, lineAnswerFalse1, lineAnswerFalse2, lineAnswerFalse3);
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

    //Alle Objekte aus der verketteten Liste in die Datei speichern
    for(Question *p=head; p!=nullptr; p=p->next)
    {
        writeFile << "#F\n";
        writeFile << p->m_question;
        writeFile << "\n";
        for(int i=0; i<4; i++)
        {
            writeFile << "#A\n";
            writeFile << p->m_answers[i];
            writeFile << "\n";
        }
        writeFile << "#E\n\n";
    }
    writeFile << "#ENDFILE";
    writeFile.close();
}

void Quiz::addQuestion(string inputQuestion, string inputRightAnswer, string inputFalseAnswer1, string inputFalseAnswer2, string inputFalseAnswer3)
{
    //Wenn Liste leer an den Anfang hängen
    if(head==nullptr)
    {
        head = new Question(inputQuestion, inputRightAnswer, inputFalseAnswer1, inputFalseAnswer2, inputFalseAnswer3);
        tail = head;
        return;
    }
    else
    {
        //Durch die Liste gehen und schauen ob die Frage bereits existiert
        for(Question *p = head; p!=nullptr; p=p->next)
        {
            //Wenn die Frage gleich nicht hinzufügen!
            if(!p->m_question.compare(inputQuestion))
            {
                return;
            }
        }

        //Wenn am Ende der Liste ans Ende hängen
        tail->next = new Question(inputQuestion, inputRightAnswer, inputFalseAnswer1, inputFalseAnswer2, inputFalseAnswer3);
        tail = tail->next;
    }

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
        midPrint("[Geladenen Fragen: "+ to_string(head->count)+"]");
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

            //Verkettete Liste druchgehen und Fragen abfragen
            for(Question *p = head; p!=nullptr; p=p->next)
            {
                p->ask();
            }
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
        string eingabeQuestion;
        string eingabeAnswerRight;
        string eingabeAnswerFalse1;
        string eingabeAnswerFalse2;
        string eingabeAnswerFalse3;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Neue Frage: ";
        cin.ignore();
        getline(cin,eingabeQuestion);
        cout << "Richtige Antwort: ";
        getline(cin,eingabeAnswerRight);
        cout << "Falsche Antwort: ";
        getline(cin,eingabeAnswerFalse1);
        cout << "Falsche Antwort: ";
        getline(cin,eingabeAnswerFalse2);
        cout << "Falsche Antwort: ";
        getline(cin,eingabeAnswerFalse3);
        addQuestion(eingabeQuestion,eingabeAnswerRight,eingabeAnswerFalse1,eingabeAnswerFalse2,eingabeAnswerFalse3);

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
    if(head==nullptr)
    {
        cout << "Es wurden keine Fragen gefunden!" << endl;
        return;
    }
    int tempCount=1;
    cout << "Welche Frage soll geloescht werden?" << endl << endl;
    for(Question *p=head; p!=nullptr; p=p->next)
    {
        cout << "[" << tempCount << "] " << p->m_question << endl;
        tempCount++;
    }
    while(true)
    {
        cout << endl << endl << "(Antwort:) ";
        string answer;
        cin >> answer;
        try
        {
            //Falls eine Zahl angegeben wurde die nicht zwischen 1 und 4 liegt
            if(stoi(answer)>head->count || stoi(answer)<1)
            {
                cout << "{Eingabefehler: Bitte gib eine Zahl zwischen 1 und" << head->count << "ein!}" << endl;
            }
            else
            {
                //Angegebene Zahl löschen
                if(stoi(answer)==1)
                {
                    if(head==tail) tail=head->next;
                    Question *temp = head->next;
                    delete head;
                    head = temp;
                }
                else if(stoi(answer)==2)
                {
                    if(head->next==tail) tail=head;
                    Question *temp = head->next->next;
                    delete head->next;
                    head->next = temp;
                }
                else
                {
                    Question *p = head;
                    for(int i=0; i<stoi(answer)-2; i++)
                    {
                        p=p->next;
                    }

                    if(p->next==tail) tail=p;
                    Question *temp = p->next->next;
                    delete p->next;
                    p->next = temp;


                }
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
    int listCount = 1;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Liste aller Fragen:" << endl;
    for(Question *p=head; p!=nullptr; p=p->next)
    {
        cout << "[" << listCount << "] " << p->m_question << endl;
        listCount++;
    }
}

//Logo auf der Konsole ausgeben
void Quiz::printLogo() {
    string line;
    ifstream logo;
    logo.open("logo.txt");
    if(logo.is_open()) {
        while (getline(logo, line)) {
            cout << line << endl;
        }
        logo.close();
    } else {
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
