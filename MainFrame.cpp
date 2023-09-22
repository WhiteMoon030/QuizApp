#include "MainFrame.h"
#include "MainMenuPanel.h"

MainFrame::MainFrame(const wxString &title, QuizTable *pointerTable):
    //Aufruf des Vaterklassen Konstruktors von wxFrame
    wxFrame(nullptr, -1, title),
    //Neues Panel erzeugen
    m_panel(new MainMenuPanel(this, pointerTable, m_panel)),
    //QuizTable Pointer zuweisen
    m_pointerTable(pointerTable)
{
    //Gr��enverstellbarkeit des Fensters verhindern
    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER));
    //Fenstergr��e setzen und mittig auf dem Bildschirm anzeigen lassen
    SetClientSize(FRAME_WIDTH,FRAME_HEIGHT);
    Center();
    //Men� Fenster anzeigen lassen
    Show();
}

