#ifndef MAINMENUPANEL_H_INCLUDED
#define MAINMENUPANEL_H_INCLUDED

#include "PanelBase.h"

class MainMenuPanel : public PanelBase
{
public:
    //Konstruktor
    MainMenuPanel(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP);
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

#endif // MAINMENUPANEL_H_INCLUDED
