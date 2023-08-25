#ifndef MENUFRAME_H_INCLUDED
#define MENUFRAME_H_INCLUDED

//Menü Fenster der Gui Applikation

#include <wx/wx.h>

class MenuFrame : public wxFrame
{
public:
    //Konstruktor
    MenuFrame(const wxString &title);
private:
    //GUI Elemente
    wxPanel *m_panel;
    //Text
    wxStaticText *m_header;
    wxStaticText *m_bottom_quote;
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
