#ifndef QUIZTABLE_H_INCLUDED
#define QUIZTABLE_H_INCLUDED

#include <string>

#include "Quiz.h"

class QuizTable
{
public:
    friend class Menu;
    friend class EditMenuPanel;
	//Standardkonstruktor
	QuizTable();
	//Methoden
	void addQuiz(string quiz_name);
	void deleteQuiz(unsigned int index);
	void reconstruct();
private:
	//Tatsächliche Größe des Arrays
	int m_size;
	//Belegte Elemente des Arrays
	int m_elements;
	//Pointer auf Array von Quiz Objekten
	Quiz **m_table;
};

#endif // QUIZTABLE_H_INCLUDED
