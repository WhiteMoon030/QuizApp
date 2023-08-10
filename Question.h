#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <string>

using namespace std;

class Question
{
public:
    friend class Quiz;
    //Standard Konstruktor
    Question() {}
    //Konstruktor
    Question(string inputQuestion) : m_question(inputQuestion) {}
    virtual ~Question() {}

    //Methoden
    virtual void setValues(){};
    virtual bool ask(){ return false; };
    virtual string getAnswerSave(){ return ""; };

protected:
    //Frage
    string m_question;
    //Statistik
    //Anzahl richtiger Antworten
    static unsigned int m_rightAnswers;
    //Anzahl gefragter Fragen
    static unsigned int m_askedQuestions; };

#endif // QUESTION_H_INCLUDED
