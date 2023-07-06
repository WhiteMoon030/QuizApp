#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <string>

using namespace std;

class Question
{
public:
    friend class Quiz;
    //Standard Konstruktor
    Question();

    //Methoden
    void setValues(string inputQuestion, string inputRight, string inputFalse1, string inputFalse2, string inputFalse3);
    bool ask();

    //Operatoren
    void operator=(Question &obj);
private:
    //Frage
    string m_question;
    //Antworten
    string m_answers[4];
    //Statistik
    //Anzahl richtiger Antworten
    static unsigned int m_rightAnswers;
    //Anzahl gefragter Fragen
    static unsigned int m_askedQuestions;
};

#endif // QUESTION_H_INCLUDED
