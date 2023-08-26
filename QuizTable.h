#ifndef QUIZTABLE_H_INCLUDED
#define QUIZTABLE_H_INCLUDED

#include <string>

#include "Quiz.h"

class QuizTable
{
public:
    friend class Menu;
    friend class EditFrame;
	//Standardkonstruktor
	QuizTable();
	//Methoden
	void addQuiz(string quiz_name);
private:
	//Größe des Arrays
	int m_size;
	//Pointer auf Array von Quiz Objekten
	Quiz **m_table;
};

#endif // QUIZTABLE_H_INCLUDED
