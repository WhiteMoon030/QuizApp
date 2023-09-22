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
    //Größenverstellbarkeit des Fensters verhindern
    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER));
    //Fenstergröße setzen und mittig auf dem Bildschirm anzeigen lassen
    SetClientSize(FRAME_WIDTH,FRAME_HEIGHT);
    Center();
    //Menü Fenster anzeigen lassen
    Show();
}

