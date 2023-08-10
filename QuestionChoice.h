#ifndef QUESTIONCHOICE_H_INCLUDED
#define QUESTIONCHOICE_H_INCLUDED

#include <string>
#include "Question.h"

using namespace std;

class QuestionChoice : public Question
{
public:
    //Standard Konstruktor
    QuestionChoice(string inputQuestion, string inputRight, string inputFalse1, string inputFalse2, string inputFalse3);

    //Methoden
    bool ask() override;
    string getAnswerSave() override;

    //Operatoren
    void operator=(QuestionChoice &obj);

private:
    //Antworten
    string m_answers[4];
};

#endif // QUESTIONCHOICE_H_INCLUDED
