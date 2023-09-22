#ifndef PANELBASE_H_INCLUDED
#define PANELBASE_H_INCLUDED

#include <wx/wx.h>
#include "QuizTable.h"

class PanelBase : public wxPanel
{
public:
    //Konstruktor
    PanelBase(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP) :
        //Vaterklassen Konstruktor aufrufen
        wxPanel(parentFrame),
        //Pointer auf QuizTable setzen
        m_pointerTable(pointerTable),
        //Pointer des Parent Panels setzen
        m_selfP(selfP),
        //Bodentext
        m_bottom_quote(new wxStaticText(this, wxID_ANY, "Entwickelt von Loris Els - ©2023", wxPoint(0,575), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL))
    {

    }
protected:
    //Pointer auf den QuizTable
    QuizTable *m_pointerTable;
    //Pointer auf das Panel Parent Frames
    PanelBase *m_selfP;
private:
    //Bodentext
    wxStaticText *m_bottom_quote;
};

#endif // PANELBASE_H_INCLUDED
