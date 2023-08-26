#ifndef MENUFRAME_H_INCLUDED
#define MENUFRAME_H_INCLUDED

//Menü Fenster der Gui Applikation

#include "FrameBase.h"
#include <wx/wx.h>

class MenuFrame : public FrameBase
{
public:
    //Konstruktor
    MenuFrame(const wxString &title, QuizTable *pointer);
private:
    //Titel
    wxStaticText *m_header;
    //Buttons
    wxButton *m_play_button;
    wxButton *m_edit_button;
    wxButton *m_options_button;
    wxButton *m_quit_button;

    //Eventhandler Methoden
    void OnPlayButtonClicked(wxCommandEvent &evt);
    void OnEditButtonClicked(wxCommandEvent &evt);
    void OnOptionsButtonClicked(wxCommandEvent &evt);
    void OnQuitButtonClicked(wxCommandEvent &evt);
};

#endif // MENUFRAME_H_INCLUDED
