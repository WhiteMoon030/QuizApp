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

    //Neues Menü Fenster erzeugen
    MenuFrame *menuFrame = new MenuFrame("QuizApp");
    //Fenstergröße setzen und mittig auf dem Bildschirm anzeigen lassen
    menuFrame->SetClientSize(FRAME_WIDTH,FRAME_HEIGHT);
    menuFrame->Center();
    //Menü Fenster anzeigen lassen
    menuFrame->Show();
    return true;
}
