#ifndef QUESTIONINSERT_H_INCLUDED
#define QUESTIONINSERT_H_INCLUDED

#include <string>
#include "Question.h"

using namespace std;

class QuestionInsert : public Question
{
public:
    //Konstruktor
    QuestionInsert(string inputQuestion, string inputAnswer);

    //Methoden
    bool ask() override;
    string getAnswerSave() override;
private:
    string m_rightAnswer;
};

#endif // QUESTIONINSERT_H_INCLUDED
