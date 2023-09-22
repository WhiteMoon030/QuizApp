#include "EditMenuPanel.h"
#include <string>

//Konstruktor
EditMenuPanel::EditMenuPanel(wxFrame *parentFrame, QuizTable *pointerTable, PanelBase *selfP):
    //Vaterklassen Konstruktor aufrufen
    PanelBase(parentFrame, pointerTable, selfP),
    //Titel
    m_title(new wxStaticText(this, wxID_ANY, "Quiz Liste", wxPoint(0,20), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL)),
    //Buttons
    m_add_button(new wxButton(this, wxID_ANY, "Hinzufügen", wxPoint(40,520), wxSize(180, 40))),
    m_edit_button(new wxButton(this, wxID_ANY, "Bearbeiten", wxPoint(220,520), wxSize(180, 40))),
    m_delete_button(new wxButton(this, wxID_ANY, "Löschen", wxPoint(400,520), wxSize(180, 40))),
    m_back_button(new wxButton(this, wxID_ANY, "Zurück", wxPoint(580,520), wxSize(180, 40))),
    //Checklist Box
    m_checkBox(new wxCheckListBox(this, wxID_ANY, wxPoint(40, 50), wxSize(720, 450)))
{
    //Event Methoden dynamisch an die einzelnen Buttons binden
    m_add_button->Bind(wxEVT_BUTTON, &EditMenuPanel::OnAddButtonClicked, this);
    m_edit_button->Bind(wxEVT_BUTTON, &EditMenuPanel::OnEditButtonClicked, this);
    m_delete_button->Bind(wxEVT_BUTTON, &EditMenuPanel::OnDeleteButtonClicked, this);
    m_back_button->Bind(wxEVT_BUTTON, &EditMenuPanel::OnBackButtonClicked, this);
    //Stapel in die CheckBox Laden
    loadQuizTable();
}

//Eventhandler Methoden
//Hinzufügen Button Event
void EditMenuPanel::OnAddButtonClicked(wxCommandEvent &evt)
{
    //Eingabe des Quiz Namens
    wxTextEntryDialog *namensEingabe = new wxTextEntryDialog(this, "Quiz-Name:","Neues Quiz", "",wxOK | wxCANCEL | wxCENTRE | wxWS_EX_VALIDATE_RECURSIVELY);
    if(namensEingabe->ShowModal() == wxID_OK)
    {
        //Umwandlung des zurückgegeben wxStrings von GetValue in einen std::string
        std::string eingabe = std::string(namensEingabe->GetValue().mb_str());
        if(eingabe!="")
        {
            //Neues Quiz mit diesem Namen hinzufügen
            m_pointerTable->addQuiz(eingabe);
            loadQuizTable();
        }
    }
    delete namensEingabe;
}

//Bearbeiten Button Event
void EditMenuPanel::OnEditButtonClicked(wxCommandEvent &evt)
{

}
//Löschen Button Event
void EditMenuPanel::OnDeleteButtonClicked(wxCommandEvent &evt)
{
    //Alle Checkboxen durchgehen und die markierten löschen
    for(int i=0; i<m_pointerTable->m_size; i++)
    {
        if(m_checkBox->IsChecked(i))
        {
            std::string text = "Sicher das Sie das Quiz \"" +  m_pointerTable->m_table[i]->m_name + "\" löschen wollen?";
            wxMessageDialog* sicher = new wxMessageDialog(this, text, "Löschen", wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            if(sicher->ShowModal() == wxID_YES) m_pointerTable->deleteQuiz(i);
            delete sicher;
        }
    }
    m_pointerTable->reconstruct();
    loadQuizTable();

}
//Zurück Button Event
void EditMenuPanel::OnBackButtonClicked(wxCommandEvent &evt)
{

}

//Methoden zum Laden der einzelnen Stapel in die CheckBox
void EditMenuPanel::loadQuizTable()
{
    m_checkBox->Clear();
    //Stapel der geladenen Quizze durchgehen und alle in die CheckBox hinzufügen
    for(int i=0; i<m_pointerTable->m_size; i++)
    {
        m_checkBox->Insert(m_pointerTable->m_table[i]->m_name, m_checkBox->GetCount());
    }
}
