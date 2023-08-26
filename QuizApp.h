#ifndef QUIZAPP_H_INCLUDED
#define QUIZAPP_H_INCLUDED

//wxWidget Applikationsklasse
#include "QuizTable.h"
#include <wx/app.h>

class QuizApp : public wxApp
{
public:
    bool OnInit();
private:
    QuizTable *m_table;
};


#endif // QUIZAPP_H_INCLUDED
