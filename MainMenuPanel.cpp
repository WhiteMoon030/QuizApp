#include "MainMenuPanel.h"

//Konstruktor
MainMenuPanel::MainMenuPanel(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP):
    //Aufruf des Vaterklassenkonstruktors
    PanelBase(parentFrame, pointerTable, selfP),
    //Titelschriftzug
    m_header(new wxStaticText(this, wxID_ANY, "QuizApp", wxPoint(0,50), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
    /*
        [Buttons]
        Aufbau:
            - Spielen
            - Stapel bearbeiten
            - Optionen
            - Beenden
    */
    m_play_button(new wxButton(this, wxID_ANY, "Spielen", wxPoint(250,120), wxSize(300, 50))),
    m_edit_button(new wxButton(this, wxID_ANY, "Stapel bearbeiten", wxPoint(250,180), wxSize(300, 50))),
    m_options_button(new wxButton(this, wxID_ANY, "Optionen", wxPoint(250,240), wxSize(300, 50))),
    m_quit_button(new wxButton(this, wxID_ANY, "Beenden", wxPoint(250,300), wxSize(300, 50)))
{
    //Event Methoden dynamisch an die einzelnen Buttons binden
    m_play_button->Bind(wxEVT_BUTTON, &MainMenuPanel::OnPlayButtonClicked, this);
    m_edit_button->Bind(wxEVT_BUTTON, &MainMenuPanel::OnEditButtonClicked, this);
    m_options_button->Bind(wxEVT_BUTTON, &MainMenuPanel::OnOptionsButtonClicked, this);
    m_quit_button->Bind(wxEVT_BUTTON, &MainMenuPanel::OnQuitButtonClicked, this);
}

//Eventhandler Methoden
//Spielen Button Event
void MainMenuPanel::OnPlayButtonClicked(wxCommandEvent &evt)
{
    wxMessageBox("Feature \"Spielen\" noch in Entwicklung!", "Information");
}
//Stapel bearbeiten Button Event
void MainMenuPanel::OnEditButtonClicked(wxCommandEvent &evt)
{
    //selfP = new EditMenuPanel(,,)

}
//Optionen Button Event
void MainMenuPanel::OnOptionsButtonClicked(wxCommandEvent &evt)
{
    wxMessageBox("Feature \"Optionen\" noch in Entwicklung!", "Information");
}
//Beenden Button Event
void MainMenuPanel::OnQuitButtonClicked(wxCommandEvent &evt)
{
    //Applikation wird beendet
    Close();
}
