#include "MenuFrame.h"
#include "QuizApp.h"
#include <wx/wx.h>
#include <stdlib.h>
#include <time.h>

wxIMPLEMENT_APP(QuizApp);

bool QuizApp::OnInit()
{
    //Jedes Mal neue Zufallszahlen erzeugen
    srand(time(NULL));

    //Neues Men� Fenster erzeugen
    MenuFrame *menuFrame = new MenuFrame("QuizApp");
    //Men� Fenster anzeigen lassen
    menuFrame->Show();
    return true;
}
