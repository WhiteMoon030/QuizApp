#include "QuizTable.h"

//Standardkonstruktor
QuizTable::QuizTable() : m_size(0), m_table(nullptr)
{}

//Methoden zum hinzufügen von einem Quiz
void QuizTable::addQuiz(string quiz_name)
{
	//Neuen Array erstellen der eins größer ist als der alte
	Quiz **temp = new Quiz*[m_size+1];
	//Alle Pointer aus dem alten Array in den neuen kopieren
	for(int i=0; i<m_size; i++)
	{
		temp[i] = m_table[i];
	}
	//Alten Array löschen
	delete[] m_table;
	//Neues Quiz dynamisch erstellen und hinten an den Array anhängen
	temp[m_size] = new Quiz();
	temp[m_size]->setName(quiz_name);
	//Table Pointer setzen
	m_table = temp;
	//Größe um Eins erhöhen
	m_size++;
	return;
}
