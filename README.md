# QuizApp
A console application for creating, deleting and querying quizzes. (For Windows and Linux systems)
Developed with CodeBlocks 20.03 and compiled with MinGW-W64-builds-4.3.5
GUI was made with wxWidgets 3.1.7

## Application Logic
  1. Read saved questions from "data.txt"
  2. Starts the Main Menu
  3. You can create, delete, edit play your own Quizzes
  4. When you close the Application all loaded questions will be saved again in "data.txt"

## Files
  ### Main Quiz Source Files: 
  main.cpp, Quiz.h, Quiz.cpp, Question.h, Question.cpp, QuestionChoice.h, QuestionChoice.cpp, QuestionInsert.h, QuestionInsert.cpp
  ### wxWidget Frame Source Files:
  FrameBase.h, MenuFrame.h, MenuFrame.cpp, EditFrame.h, EditFrame.cpp
  ### CodeBlocks Project Files: 
  QuizApp.cbp, QuizApp.depend, QuizApp.layout, /obj
  ### Git Files: 
  .gitignore, README.md
  ### Release Files: 
  /bin
