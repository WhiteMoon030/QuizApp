#ifndef EDITMENUPANEL_H_INCLUDED
#define EDITMENUPANEL_H_INCLUDED

#include "PanelBase.h"

class EditMenuPanel : public PanelBase
{
public:
    //Konstruktor
    EditMenuPanel(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP);
private:
    //Titel
    wxStaticText *m_title;
    //Buttons
    wxButton *m_add_button;
    wxButton *m_edit_button;
    wxButton *m_delete_button;
    wxButton *m_back_button;
    //Checklistbox für alle Stapel
    wxCheckListBox *m_checkBox;
    //Eventhandler Methoden
    void OnAddButtonClicked(wxCommandEvent &evt);
    void OnEditButtonClicked(wxCommandEvent &evt);
    void OnDeleteButtonClicked(wxCommandEvent &evt);
    void OnBackButtonClicked(wxCommandEvent &evt);
    //Methoden zum Laden der einzelnen Stapel in die CheckBox
    void loadQuizTable();

};

#endif // EDITMENUPANEL_H_INCLUDED
