#include "EditFrame.h"
#include "MenuFrame.h"

EditFrame::EditFrame(const wxString &title, QuizTable *pointer) :
//Aufruf des Vaterklassen Konstruktors von FrameBase
FrameBase(title, pointer),
//Titel
m_title(new wxStaticText(m_panel, wxID_ANY, "Quiz Liste", wxPoint(0,20), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
//Buttons
m_add_button(new wxButton(m_panel, wxID_ANY, "Hinzufügen", wxPoint(40,520), wxSize(180, 40))),
m_edit_button(new wxButton(m_panel, wxID_ANY, "Bearbeiten", wxPoint(220,520), wxSize(180, 40))),
m_delete_button(new wxButton(m_panel, wxID_ANY, "Löschen", wxPoint(400,520), wxSize(180, 40))),
m_back_button(new wxButton(m_panel, wxID_ANY, "Zurück", wxPoint(580,520), wxSize(180, 40))),
//Checklist Box
m_checkBox(new wxCheckListBox(m_panel, wxID_ANY, wxPoint(40, 50), wxSize(720, 450)))
{
    //Event Methoden dynamisch an die einzelnen Buttons binden
    m_add_button->Bind(wxEVT_BUTTON, &EditFrame::OnAddButtonClicked, this);
    m_edit_button->Bind(wxEVT_BUTTON, &EditFrame::OnEditButtonClicked, this);
    m_delete_button->Bind(wxEVT_BUTTON, &EditFrame::OnDeleteButtonClicked, this);
    m_back_button->Bind(wxEVT_BUTTON, &EditFrame::OnBackButtonClicked, this);
    //Stapel in die CheckBox Laden
    loadQuizTable();
}

//Eventhandler Methoden
//Hinzufügen Button Event
void EditFrame::OnAddButtonClicked(wxCommandEvent &evt)
{
    m_pointerTable->addQuiz("Default");
    loadQuizTable();
}
//Bearbeiten Button Event
void EditFrame::OnEditButtonClicked(wxCommandEvent &evt)
{

}
//Löschen Button Event
void EditFrame::OnDeleteButtonClicked(wxCommandEvent &evt)
{

}
//Zurück Button Event
void EditFrame::OnBackButtonClicked(wxCommandEvent &evt)
{
    //Neues Menü Fenster erzeugen
    MenuFrame *menuFrame = new MenuFrame("QuizApp", m_pointerTable);
    Close();
}

//Methoden zum Laden der einzelnen Stapel in die CheckBox
void EditFrame::loadQuizTable()
{
    m_checkBox->Clear();
    //Stapel der geladenen Quizze durchgehen und alle in die CheckBox hinzufügen
    for(int i=0; i<m_pointerTable->m_size; i++)
    {
        m_checkBox->Insert(m_pointerTable->m_table[i]->m_name, m_checkBox->GetCount());
    }
}
