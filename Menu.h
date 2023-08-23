#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>

#include "QuizTable.h"

class Menu
{
public:
	//Standardkonstruktor
	Menu();
	//Destruktor
	~Menu();
	//Methoden
	void start();
	void addNew();
	void deleteOld();
	void listQuestions();
	void midPrint(string text, char symbol=' ');
	void printLogo();

	//QuizTable Zugriff
	void addQuiz(string name) { m_quizTable.addQuiz(name); }
	void load(unsigned int index, string fileName) { m_quizTable.m_table[index]->load(fileName); }
	void save(unsigned int index, string fileName) { m_quizTable.m_table[index]->save(fileName); }
private:
	//Variable für die Quiz Objekte
	QuizTable m_quizTable;
};

#endif // MENU_H_INCLUDED
