#include "QuizTable.h"

//Standardkonstruktor
QuizTable::QuizTable() : m_size(0), m_elements(0), m_table(nullptr)
{}

//Methoden zum hinzuf�gen von einem Quiz
void QuizTable::addQuiz(string quiz_name)
{
	//Neuen Array erstellen der eins gr��er ist als der alte
	Quiz **temp = new Quiz*[m_size+1];
	//Alle Pointer aus dem alten Array in den neuen kopieren
	for(int i=0; i<m_size; i++)
	{
		temp[i] = m_table[i];
	}
	//Alten Array l�schen
	delete[] m_table;
	//Neues Quiz dynamisch erstellen und hinten an den Array anh�ngen
	temp[m_size] = new Quiz();
	temp[m_size]->setName(quiz_name);
	//Table Pointer setzen
	m_table = temp;
	//Gr��e um Eins erh�hen
	m_size++;
	m_elements++;
	return;
}

//Methoden zum l�schen von einem Quiz -> Array wird NICHT neu strukturiert
void QuizTable::deleteQuiz(unsigned int index)
{
    //Quiz l�schen
    delete m_table[index];
    m_table[index] = nullptr;
    m_elements--;
}

//Methoden zum neustrukturieren des Arrays (alle Nullpointer Elemente l�schen)
void QuizTable::reconstruct()
{
    //Array neu strukturieren
    Quiz **temp = new Quiz*[m_elements];
    //Index zum mitz�hlen an welcher Stelle des neuen Arrays sich der Einschub gerade befindet
    int tempIndex = 0;
    //Alle Element Pointer die keine Nullpointer sind werden im tempor�ren Array gespeichert
    for(int i=0; i<m_size; i++)
    {
        if(m_table[i]!=nullptr)
        {
            temp[tempIndex] = m_table[i];
            tempIndex++;
        }
    }
    //Alten Array l�schen und Gr��en Variable anpassen
    delete[] m_table;
    m_table = temp;
    m_size = m_elements;
}
