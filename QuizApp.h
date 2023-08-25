#ifndef QUIZAPP_H_INCLUDED
#define QUIZAPP_H_INCLUDED

//wxWidget Applikationsklasse

#include <wx/app.h>

//Konstanten
const int FRAME_WIDTH=800;
const int FRAME_HEIGHT=600;

class QuizApp : public wxApp
{
public:
    bool OnInit();
};


#endif // QUIZAPP_H_INCLUDED
