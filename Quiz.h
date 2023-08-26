#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED

#include <string>

#include "Question.h"

using namespace std;

const string QUESTION_ID = "#F";
const string ANSWER_ID = "#A";
const string END_ID = "#E";
const string ENDFILE_ID = "#ENDFILE";

const unsigned int LINE_LENGTH = 96;

class Quiz
{
public:
    friend class Menu;
    friend class EditFrame;
    //Standard Konstruktor
    Quiz();
    //Funktionen zum Laden und Speichern der Fragen in eine Textdatei
    void load(string inputDataFileName="data.txt");
    void save(string inputDataFileName="data.txt");
    //Array erweitern
    void addSize(unsigned int newSize);
    //Funktionen zum hinzufügen von Fragen zum Array
    void addQuestion(string inputQuestion, string inputRightAnswer);
    void addQuestion(string inputQuestion, string inputRightAnswer, string inputFalseAnswer1, string inputFalseAnswer2, string inputFalseAnswer3);
    //Visuelle Ausgabe auf der Konsole
    void midPrint(string text, char symbol=' ');
    void convertData(string fileName);
    //Methoden zum Löschen einzelner Fragen oder aller Fragen
    void delArray(int index=-1);
    //Namen setzen
    void setName(string inputName) { m_name = inputName; }
private:
    //Name des Quiz
    string m_name;
    //Größe des Arrays
    int m_size;
    //Tatsächlich belegte Member vom Array
    int m_total;
    //Pointer auf Array aus Fragen
    Question **m_quiz;
};

#endif // QUIZ_H_INCLUDED
