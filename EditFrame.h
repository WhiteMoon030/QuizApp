#ifndef EDITFRAME_H_INCLUDED
#define EDITFRAME_H_INCLUDED

#include "FrameBase.h"

class EditFrame : public FrameBase
{
public:
    EditFrame(const wxString &title, QuizTable *pointer);
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

#endif // EDITFRAME_H_INCLUDED
