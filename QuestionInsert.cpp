#include <iostream>
#include <unistd.h>
#include "QuestionInsert.h"

QuestionInsert::QuestionInsert(string inputQuestion, string inputAnswer) : Question(inputQuestion), m_rightAnswer(inputAnswer) {}

//Fragenausgabe
bool QuestionInsert::ask()
{
    //Frage auf der Konsole ausgeben und abfragen
    cout << m_question << endl << endl << "(Antwort:) ";
    string answer;
    cin >> answer;
    //Feedback geben
    if(answer=="q")
    {
        return false;
    }else if(answer==m_rightAnswer)
    {
        cout << "[Richtig!]" << endl;
        m_rightAnswers++;
    }else
    {
	cout << "[Falsch!]" << endl;
	sleep(1);
	cout << "[Richtige Antwort: \"" << m_rightAnswer << "\"]" << endl;
    }
    m_askedQuestions++;
    cout << "------------------------------------------------------------------------" << endl;
    sleep(1);
    return true;
}

string QuestionInsert::getAnswerSave()
{
    return "#A\n"+m_rightAnswer+"\n";
}
