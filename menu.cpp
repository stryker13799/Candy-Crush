#include "menu.h"
#include<GL/glut.h>
#include <fstream>
#include "util.h"
using namespace std;
#include <string>

void menu::setstate(int stt)
{
	state = stt;
}

int menu::getstate()
{
	return state;
}

void menu::drawmenu()
{
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawSquare(300, 150, 40, colors[RED]);
	DrawRectangle(350,155, 40, 25, colors[GREEN]);
	DrawCircle(315, 220, 20, colors[YELLOW]);
	Torus2d(360, 250, 250, 70, 20, 20, 3, colors[BLUE]);
	
	DrawString(10, 50, "OOP Project", colors[MISTY_ROSE]);
	DrawString(50, 100, "BY", colors[MISTY_ROSE]);
	DrawString(20, 150, "Ali Kamal", colors[MISTY_ROSE]);
	DrawString(20, 200, "19I-1865", colors[MISTY_ROSE]);
	DrawString(20, 250, "BSDS(N)", colors[MISTY_ROSE]);
	DrawString(300, 300, "START", colors[MISTY_ROSE]);
	DrawString(300, 350, "SETTINGS", colors[MISTY_ROSE]);
	DrawString(300, 400, "HIGH SCORES", colors[MISTY_ROSE]);
	DrawString(300, 450, "LEVELS", colors[MISTY_ROSE]);
	DrawString(300, 500, "LEVEL MODES", colors[MISTY_ROSE]);
}

void menu::settings()
{
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(300, 400, "How To Play", colors[MISTY_ROSE]);
	DrawString(300, 450, "Player Profile", colors[MISTY_ROSE]);
	DrawString(300, 500, "Music & Sound", colors[MISTY_ROSE]);
	DrawString(300, 550, "Go Back", colors[MISTY_ROSE]);
}

void menu::howtoplay()
{
	DrawString(100, 250, "Use your left mouse button to drag and drop different gems", colors[MISTY_ROSE]);
	DrawString(100, 300, "Match 3 or more gems of the same type to score points", colors[MISTY_ROSE]);
	DrawString(100, 350, "Matching more than 3 gems gives you additional points!", colors[MISTY_ROSE]);
	DrawString(100, 400, "In Time Trial mode, you must race against the clock to finish ", colors[MISTY_ROSE]);
	DrawString(100, 450, "your progress bar before it depletes!", colors[MISTY_ROSE]);
	DrawString(100, 500, "GOOD LUCK!", colors[MISTY_ROSE]);
	DrawString(100, 690, "Go Back", colors[MISTY_ROSE]);
}

void menu::highscores()
{
	int high_score = 0, high_score_2 = 0, high_score_3 = 0, high_score_4 = 0;
	ifstream file;
	file.open("Highscores.txt");
	if (file.good())
	{
		file >> high_score;
		file >> high_score_2;
		file >> high_score_3;
		file >> high_score_4;
		file.close();
	}
	else
	{
		high_score = high_score_2 = high_score_3 = high_score_4 = 0;
		file.close();
	}
	string h1, h2, h3, h4;
	h1 = Num2Str(high_score);
	h2 = Num2Str(high_score_2);
	h3 = Num2Str(high_score_3);
	h4 = Num2Str(high_score_4);

	DrawString(300, 400, "1. ", colors[MISTY_ROSE]);
	DrawString(330, 400, h1, colors[MISTY_ROSE]);
	
	DrawString(300, 450, "2. ", colors[MISTY_ROSE]);
	DrawString(330, 450, h2, colors[MISTY_ROSE]);

	DrawString(300, 500, "3. ", colors[MISTY_ROSE]);
	DrawString(330, 500, h3, colors[MISTY_ROSE]);

	DrawString(300, 550, "4. ", colors[MISTY_ROSE]);
	DrawString(330, 550, h4, colors[MISTY_ROSE]);

	DrawString(300, 600, "Go Back", colors[MISTY_ROSE]);
}

void menu::playerprofile()
{
	DrawString(300, 400, "Name", colors[MISTY_ROSE]);
	DrawString(500, 400, "Highest Level", colors[MISTY_ROSE]);

	ifstream file;
	int score = 0;
	string name = "None";
	file.open("profile.txt");
	if (file.good())
	{
		file >> score;
		file >> name;
	}
	file.close();
	DrawString(300, 450, name, colors[MISTY_ROSE]);
	DrawString(500, 450, Num2Str(score), colors[MISTY_ROSE]);

	DrawString(300, 600, "Go Back", colors[MISTY_ROSE]);
}

void menu::levels()
{
	DrawString(10,50, "Completed Levels: ", colors[MISTY_ROSE]);
	DrawString(200, 50, "White", colors[MISTY_ROSE]);
	DrawString(10, 100, "Uncompleted Levels: ", colors[BROWN]);
	DrawString(225, 100, "Brown", colors[BROWN]);

	ifstream file;
	int score = 0, counter = 1;
	file.open("profile.txt");
	if (file.good())
	{
		file >> score;
	}
	file.close();

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (counter <= score)
			{
				DrawString(100 + (i * 50), 100 + (j * 50), Num2Str(counter), colors[MISTY_ROSE]);
			}
			else
			{
				DrawString(100 + (i * 50), 100 + (j * 50), Num2Str(counter), colors[BROWN]);
			}
			counter++;
		}
	}
	DrawString(300, 650, "Go Back", colors[MISTY_ROSE]);
}

void menu::levelmodes()
{
	DrawString(300, 400, "Normal Mode", colors[MISTY_ROSE]);
	DrawString(300, 450, "Time Trial Mode", colors[MISTY_ROSE]);
	DrawString(200, 690, "Go Back", colors[MISTY_ROSE]);
}

void menu::soundmusic()
{
	DrawString(300, 300, "Music off", colors[MISTY_ROSE]);
	DrawString(500, 300, "Music on", colors[MISTY_ROSE]);

	DrawString(300, 400, "Sound off", colors[MISTY_ROSE]);
	DrawString(500, 400, "Sound on", colors[MISTY_ROSE]);

	DrawString(300, 650, "Go Back", colors[MISTY_ROSE]);
}
