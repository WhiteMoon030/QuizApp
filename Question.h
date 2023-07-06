#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <string>

using namespace std;

class Question
{
public:
    friend class Quiz;
    //Konstruktor
    Question(string inputQuestion, string inputRight, string inputFalse1, string inputFalse2, string inputFalse3);
    //Destruktor
    ~Question();

    //Methoden
    int getCount() { return count; }
    void ask();
private:
    static int count;
    //Verkettungspointer für eine Einfach verkettete Liste
    Question *next;
    //Frage
    string m_question;
    //Antworten
    string m_answers[4];
};

#endif // QUESTION_H_INCLUDED
