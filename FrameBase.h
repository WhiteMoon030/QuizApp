#ifndef FRAMEBASE_H_INCLUDED
#define FRAMEBASE_H_INCLUDED

//Basis Klasse für alle Fenster
#include "QuizTable.h"
#include <wx/wx.h>

//Konstanten
const int FRAME_WIDTH=800;
const int FRAME_HEIGHT=600;

class FrameBase : public wxFrame
{
public:
    //Konstruktor
    FrameBase(const wxString &title, QuizTable *pointer):
    //Aufruf des Vaterklassen Konstruktors von wxFrame
    wxFrame(nullptr, -1, title),
    //Neues Panel erzeugen
    m_panel(new wxPanel(this)),
    //Bodentext
    m_bottom_quote(new wxStaticText(m_panel, wxID_ANY, "Entwickelt von Loris Els - ©2023", wxPoint(0,575), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
    //QuizTable Pointer zuweisen
    m_pointerTable(pointer)
    {
        //Größenverstellbarkeit des Fensters verhindern
        SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER));
        //Fenstergröße setzen und mittig auf dem Bildschirm anzeigen lassen
        SetClientSize(FRAME_WIDTH,FRAME_HEIGHT);
        Center();
        //Menü Fenster anzeigen lassen
        Show();
    }
protected:
    //Panel für jedes Fenster
    wxPanel *m_panel;
    //Bodentext
    wxStaticText *m_bottom_quote;
    //Pointer auf den QuizTable
    QuizTable *m_pointerTable;
};

#endif // FRAMEBASE_H_INCLUDED
