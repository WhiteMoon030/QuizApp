#include "MainFrame.h"
#include "QuizApp.h"
#include <wx/wx.h>
#include <stdlib.h>
#include <time.h>

wxIMPLEMENT_APP(QuizApp);

bool QuizApp::OnInit()
{
    //Jedes Mal neue Zufallszahlen erzeugen
    srand(time(NULL));

    //Neuen Quiz Table erzeugen
    m_table = new QuizTable();

    //Neues Hauptfenster erzeugen
    MainFrame *mainFrame = new MainFrame("QuizApp", m_table);
    return true;
}
