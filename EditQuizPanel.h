#ifndef EDITQUIZPANEL_H_INCLUDED
#define EDITQUIZPANEL_H_INCLUDED

#include <wx/wx.h>
#include "PanelBase.h"

class EditQuizPanel : public PanelBase
{
public:
    //Konstrukor
    EditQuizPanel(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP);
};

#endif // EDITQUIZPANEL_H_INCLUDED
