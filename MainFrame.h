#ifndef MAINFRAME_H_INCLUDED
#define MAINFRAME_H_INCLUDED

//Hauptfenster
#include "PanelBase.h"
#include "QuizTable.h"
#include <wx/wx.h>

//Konstanten
const int FRAME_WIDTH=800;
const int FRAME_HEIGHT=600;

class MainFrame : public wxFrame
{
public:
    //Konstruktor
    MainFrame(const wxString &title, QuizTable *pointerTable);
private:
    //Pointer für das Panel
    PanelBase *m_panel;
    //Pointer auf den QuizTable
    QuizTable *m_pointerTable;
};

#endif // MAINFRAME_H_INCLUDED
