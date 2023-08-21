#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <stdexcept>

#include "Quiz.h"
#include "Menu.h"

//Hauptfunktion des Quizes
void Menu::start()
{
    cout << endl;
    printLogo();

    //Eingabemaske
    while(true)
    {
        midPrint("[Main-Menu]",'=');
        midPrint("[Geladenen Fragen: "+ to_string(m_quizTable.m_table[0]->m_total)+"]");
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
    	    cout << endl << "------------------------------------------------------------------------" << endl;
	    if(m_total==0)
	    {
        	cout << "Es wurden keine Fragen gefunden!" << endl;
		continue;
	    }
            m_quiz[0]->m_askedQuestions=0;
            m_quiz[0]->m_rightAnswers=0;

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
            //Statistik ausgeben
            double grade = ((double)m_quiz[0]->m_rightAnswers/(double)m_quiz[0]->m_askedQuestions)*100;
            grade = ceil(grade*100.0) / 100.0;
            cout << "Richtige Fragen: " << m_quiz[0]->m_rightAnswers << "/" << m_quiz[0]->m_askedQuestions << endl;
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
            cout << "Ungültige Eingabe!" << endl;
        }
    }
}

//Eingabemaske zum hinzufügen neuer Fragen
void Menu::addNew()
{
    while(true)
    {
        cout << "--------------------------------------------------------------------------------" << endl;
	while(true)
	{
	    cout << "Eingabefrage oder Singel Choice? [e/s]" << endl;
	    char choice;
	    cin >> choice;
	    if(choice=='e')
	    {
		string input[2];
        	cout << "Neue Frage: ";
		//Bevor getline das letzte eingelsen \n ignorieren
        	cin.ignore(1000, '\n');
        	getline(cin,input[0]);
        	cout << "Richtige Antwort: ";
        	getline(cin,input[1]);
		addQuestion(input[0], input[1]);
		break;
	    }
	    else if(choice=='s')
	    {
        	string input[5];
        	cout << "Neue Frage: ";
		//Bevor getline das letzte eingelsen \n ignorieren
        	cin.ignore(1000, '\n');
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
		break;
	    }
	    else if(choice=='q')
	    {
		save();
		return;
	    }
	    else cout << "Eingabefehler!" << endl;
	}

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

//Eingabemaske zum löschen alter Fragen
void Menu::deleteOld()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    if(m_total==0)
    {
        cout << "Es wurden keine Fragen gefunden!" << endl;
        return;
    }
    cout << "Welche Frage soll geloescht werden?" << endl << endl;
    for(int i=0; i<m_total; i++)
    {
        cout << "[" << i+1 << "] " << m_quiz[i]->m_question << endl;
    }
    while(true)
    {
        cout << endl << "(Antwort:) ";
        string answer;
        cin >> answer;
	if(answer=="q") return;
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
                    delArray();
                }
                else
                {
                    Question **tempArray = new Question*[m_size-1];
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
		    //Element welches gelöscht werden soll entfernen
		    delArray(indexDelete);
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


//Fragen in einer Liste ausgeben
void Menu::listQuestions()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    if (m_total==0)
    {
        cout << "Fragenliste leer!" << endl;
        return;
    }
    cout << "Liste aller Fragen:" << endl;
    for(int i=0; i<m_total; i++)
    {
        cout << "[" << i+1 << "] " << m_quiz[i]->m_question << endl;
    }
}

//Logo auf der Konsole ausgeben
void Menu::printLogo()
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

//Einen Text mittig ausgeben
void Menu::midPrint(string text, char symbol)
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
