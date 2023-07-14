#ifndef QUESTIONINSERT_H_INCLUDED
#define QUESTIONINSERT_H_INCLUDED

#include "Question.h"

class QuestionInsert : public Question
{
public:
    //Standard-Konstruktor
    QuestionInsert(){}
    void setValues(string inputQuestion, string inputRight);

private:
    string m_rightAnswer;
};

#endif // QUESTIONINSERT_H_INCLUDED
