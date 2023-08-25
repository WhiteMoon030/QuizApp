#include "MenuFrame.h"
#include <wx/wx.h>

#include <iostream>

//Konstruktor, Fügt ein Panel sowie Text und Buttons hinzu
MenuFrame::MenuFrame(const wxString &title) : //Initialisierungsliste
//Aufruf des Vaterklassen Konstruktors von wxFrame
wxFrame(nullptr, -1, title),
//Neues Panel erzeugen
m_panel(new wxPanel(this)),
//Titelschriftzug
m_header(new wxStaticText(m_panel, wxID_ANY, "QuizApp", wxPoint(0,50), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
//Bodentext
m_bottom_quote(new wxStaticText(m_panel, wxID_ANY, "Entwickelt von Loris Els - ©2023", wxPoint(0,575), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
/*
    [Buttons]
    Aufbau:
        - Spielen
        - Stapel bearbeiten
        - Optionen
        - Beenden
*/
m_play_button(new wxButton(m_panel, wxID_ANY, "Spielen", wxPoint(250,120), wxSize(300, 50))),
m_edit_button(new wxButton(m_panel, wxID_ANY, "Stapel bearbeiten", wxPoint(250,180), wxSize(300, 50))),
m_options_button(new wxButton(m_panel, wxID_ANY, "Optionen", wxPoint(250,240), wxSize(300, 50))),
m_quit_button(new wxButton(m_panel, wxID_ANY, "Beenden", wxPoint(250,300), wxSize(300, 50)))
{
    //Event Methoden dynamisch an die einzelnen Buttons binden
    m_play_button->Bind(wxEVT_BUTTON, &MenuFrame::OnPlayButtonClicked, this);
    m_edit_button->Bind(wxEVT_BUTTON, &MenuFrame::OnEditButtonClicked, this);
    m_options_button->Bind(wxEVT_BUTTON, &MenuFrame::OnOptionsButtonClicked, this);
    m_quit_button->Bind(wxEVT_BUTTON, &MenuFrame::OnQuitButtonClicked, this);
}

//Eventhandler Methoden
//Spielen Button Event
void MenuFrame::OnPlayButtonClicked(wxCommandEvent &evt)
{
    std::cout << "Play" << std::endl;
}
//Stapel bearbeiten Button Event
void MenuFrame::OnEditButtonClicked(wxCommandEvent &evt)
{
    std::cout << "Edit" << std::endl;
}
//Optionen Button Event
void MenuFrame::OnOptionsButtonClicked(wxCommandEvent &evt)
{
    std::cout << "Options" << std::endl;
}
//Beenden Button Event
void MenuFrame::OnQuitButtonClicked(wxCommandEvent &evt)
{
    //Applikation wird beendet
    Destroy();
}
