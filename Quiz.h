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
    //Standard Konstruktor
    Quiz();
    //Funktionen zum Laden und Speichern der Fragen in eine Textdatei
    void load(string inputDataFileName="data.txt");
    void save(string inputDataFileName="data.txt");
    //Array erweitern
    void addSize(unsigned int newSize);
    //Funktionen zum hinzufügen von Fragen zur verketten Liste
    void addQuestion(string inputQuestion, string inputRightAnswer, string inputFalseAnswer1, string inputFalseAnswer2, string inputFalseAnswer3);
    //Funktion zum starten des Quiz
    void start();
    //Eingabemaske für Neue Fragen
    void addNew();
    void deleteOld();
    void listQuestions();
    //Visuelle Ausgabe auf der Konsole
    void midPrint(string text, char symbol=' ');
    void printLogo();
    void convertData(string fileName);
private:
    //Größe des Arrays
    int m_size;
    //Tatsächlich belegte Member vom Array
    int m_total;
    //Pointer auf Array aus Fragen
    Question **m_quiz;
};

#endif // QUIZ_H_INCLUDED
