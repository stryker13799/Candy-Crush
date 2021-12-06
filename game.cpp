#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include<GL/glut.h>
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include "board.h"
#include "menu.h"
using namespace std;


void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


menu m1;
board b1;
void GameDisplay()
{
	glClearColor(0, 0,0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 

	if (m1.getstate() == 0)
	{
		m1.drawmenu();
	}

	if (m1.getstate() == 1)
	{
		if (b1.gettimetrial())
		{
			b1.decrementprogressbar();
			if (b1.getactualscore()<=0)
			{
				b1.decrementlives();
				b1.setactualscore(b1.getrequiredscore() / 2);
			}
			if (b1.getlives() <= 0)
			{
				DrawString(600, 400, "GAME OVER", colors[MISTY_ROSE]);
				b1.setactualscore(b1.getrequiredscore() / 2);
				b1.setlives(3);
				b1.randomizegrid();
				b1.setscore(0);
			}
		}
		b1.draw_grid();
		if (b1.gethint() == 1)
		{
			b1.sethint(0);
			b1.grid2togrid();
		}
		if (b1.getpaused())
		{
			DrawString(600, 400, "GAME PAUSED", colors[MISTY_ROSE]);
		}

		string scr = b1.convert_score_to_string();
		string req_scr = b1.convert_required_score_to_string();
		DrawString(10, 20, "Score:", colors[MISTY_ROSE]);
		DrawString(80, 20, scr, colors[MISTY_ROSE]);
		DrawString(150, 20, "/", colors[MISTY_ROSE]);
		DrawString(160, 20, req_scr, colors[MISTY_ROSE]);

		string highscr = b1.convert_highscore_to_string();
		DrawString(10, 60, "High Score:", colors[MISTY_ROSE]);
		DrawString(135, 60, highscr, colors[MISTY_ROSE]);

		string lvl = b1.convert_level_to_string();
		DrawString(320, 20, "Level:", colors[MISTY_ROSE]);
		DrawString(390, 20, lvl, colors[MISTY_ROSE]);

		DrawString(620, 20, "Lives:", colors[MISTY_ROSE]);
		b1.draw_lives();

		b1.setprogressbar();
		DrawString(10, 650, "Progress:", colors[MISTY_ROSE]);
		b1.drawprogressbar();

		DrawString(600, 200, "Press 'H' for hint", colors[MISTY_ROSE]);
		DrawString(600, 250, "Press 'P' to pause", colors[MISTY_ROSE]);
		DrawString(600, 275, "and unpause", colors[MISTY_ROSE]);
		DrawString(600, 300, "the game", colors[MISTY_ROSE]);
	}

	if (m1.getstate() == 2)
	{
		m1.settings();
	}

	if (m1.getstate() == 3)
	{
		m1.howtoplay();
	}

	if (m1.getstate() == 4)
	{
		m1.highscores();
	}

	if (m1.getstate() == 5)
	{
		m1.playerprofile();
	}

	if (m1.getstate() == 6)
	{
		m1.levels();
	}
	
	if (m1.getstate() == 7)
	{
		m1.levelmodes();
	}

	if (m1.getstate() == 8)
	{
		m1.soundmusic();
	}

	glutSwapBuffers();
}


void NonPrintableKeys(int key, int x, int y) 
{
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{

	} 
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{

	} 
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{

	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{

	}

	if (b1.getpaused() == 0)
	{
		glutPostRedisplay();
	}

}

void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27/* Escape key ASCII*/)
	{
		b1.check_if_highscore();
		b1.playerprofile();
		b1.gamestate();
		exit(1);
	}

	if (key == 'h' || key == 'H') 
	{
		b1.setscore(((b1.getlevel() - 1) * 500));
		b1.setactualscore(0);
		b1.gridtogrid2();
		b1.sethint(1);

		for (int i = 0; i < b1.getrow(); i++)
		{
			for (int j = 0; j < b1.getcol(); j++)
			{
				if (i < 8)
				{
					if (b1.grid[i + 1][j] == b1.grid[i][j])
					{
						if (j < 9 && b1.grid[i + 2][j + 1] == b1.grid[i][j])
						{
							b1.grid[i + 2][j + 1] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
						else if (j > 0 && b1.grid[i + 2][j - 1] == b1.grid[i][j])
						{
							b1.grid[i + 2][j - 1] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i < 7 && b1.grid[i + 3][j] == b1.grid[i][j])
						{
							b1.grid[i + 3][j] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i > 0 && b1.grid[i - 1][j + 1] == b1.grid[i][j])
						{
							b1.grid[i - 1][j + 1] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i > 0 && j > 0 && b1.grid[i - 1][j - 1] == b1.grid[i][j])
						{
							b1.grid[i - 1][j - 1] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i > 1 && b1.grid[i - 2][j] == b1.grid[i][j])
						{
							b1.grid[i - 2][j] = -1;
							b1.grid[i + 1][j] = -1;
							b1.grid[i][j] = -1;
						}
					}
				}

				if (j < 8)
				{
					if (b1.grid[i][j + 1] == b1.grid[i][j])
					{
						if (i < 9 && b1.grid[i + 1][j + 2] == b1.grid[i][j])
						{
							b1.grid[i + 1][j + 2] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i > 0 && b1.grid[i - 1][j + 2] == b1.grid[i][j])
						{
							b1.grid[i - 1][j + 1] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}
						else if (j < 7 && b1.grid[i][j + 3] == b1.grid[i][j])
						{
							b1.grid[i][j + 3] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i < 9 && j>0 && b1.grid[i + 1][j - 1] == b1.grid[i][j])
						{
							b1.grid[i + 1][j - 1] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}
						else if (i > 0 && j > 0 && b1.grid[i - 1][j - 1] == b1.grid[i][j])
						{
							b1.grid[i - 1][j - 1] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}
						else if (j > 1 && b1.grid[i][j - 2] == b1.grid[i][j])
						{
							b1.grid[i][j - 2] = -1;
							b1.grid[i][j + 1] = -1;
							b1.grid[i][j] = -1;
						}

					}
				}
			}
		}
	}

	if (key == 'p' || key == 'P')
	{
		if (b1.getpaused() == 0)
		{
			b1.setpaused(1);
			DrawString(600, 400, "GAME PAUSED", colors[MISTY_ROSE]);
			glutPostRedisplay();
		}
		else if (b1.getpaused() == 1)
		{
			b1.setpaused(0);
		}
	}

	if (b1.getpaused() == 0)
	{
		glutPostRedisplay();
	}
}

void Timer(int m)
{
	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y)
{
	if (b1.getpaused() == 0)
	{
		glutPostRedisplay();
	}
}
void MouseMoved(int x, int y)
{
	if (b1.getpaused() == 0)
	{
		glutPostRedisplay();
	}
}

void MouseClicked(int button, int state, int x, int y)
{
	if (b1.getpaused() == 0)
	{
		int initial_x = -5, initial_y = -5, end_x = -5, end_y = -5;
		int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
		static int tempx, tempy;
		if (button == GLUT_LEFT_BUTTON)
		{
			if (m1.getstate() == 0)
			{
				if ((x >= 300 && y >= 280) && (x <= 375 && y <= 300))
				{
					if (b1.gettimetrial())
					{
						b1.setactualscore(b1.getrequiredscore() / 2);
					}
					m1.setstate(1);
				}
				else if ((x >= 300 && y >= 330) && (x <= 415 && y <= 350))
				{
					m1.setstate(2);
				}
				else if ((x >= 300 && y >= 380) && x <= 460 && y <= 400)
				{
					m1.setstate(4);
				}
				else if ((x >= 300 && y >= 430) && x <= 390 && y<= 450)
				{
					m1.setstate(6);
				}
				else if ((x >= 300 && y >= 480) && x <= 456 && y <= 500)
				{
					m1.setstate(7);
				}
			}
			if (m1.getstate() == 1)
			{
				if (state == 0)
				{
					initial_x = x;
					initial_y = y;
					tempx = x;
					tempy = y;
					end_x = 0;
					end_y = 0;
				}
				else if (state == 1)
				{
					initial_x = tempx;
					initial_y = tempy;
					end_x = x;
					end_y = y;
				}
				i1 = initial_x - 100;
				i1 /= 50;
				j1 = initial_y - 100;
				j1 /= 50;

				i2 = end_x - 100;
				i2 /= 50;
				j2 = end_y - 100;
				j2 /= 50;
				if (abs(i2 - i1) <= 1 && abs(j2 - j1) <= 1)
				{
					if (i2 < 10 && i1 < 10 && j2 < 10 && j1 < 10)
					{
						if ((abs(i2 - i1) == 0 || abs(j2 - j1) == 0))
						{
							bool flag = 0;
							if (i2 >= 2)
							{
								if (b1.grid[i2 - 1][j2] == b1.grid[i1][j1] && b1.grid[i2 - 2][j2] == b1.grid[i1][j1] && i2 - 1 != i1 && i2 - 2 != i1)
								{
									flag = 1;
								}
							}
							if (i2 <= 7)
							{
								if (b1.grid[i2 + 1][j2] == b1.grid[i1][j1] && b1.grid[i2 + 2][j2] == b1.grid[i1][j1] && i2 + 1 != i1 && i2 + 2 != i1)
								{
									flag = 1;
								}
							}
							if (j2 >= 2)
							{
								if (b1.grid[i2][j2 - 1] == b1.grid[i1][j1] && b1.grid[i2][j2 - 2] == b1.grid[i1][j1] && j2 - 1 != j1 && j2 - 2 != j1)
								{
									flag = 1;
								}
							}
							if (j2 <= 7)
							{
								if (b1.grid[i2][j2 + 1] == b1.grid[i1][j1] && b1.grid[i2][j2 + 2] == b1.grid[i1][j1] && j2 + 1 != j1 && j2 + 2 != j1)
								{
									flag = 1;
								}
							}
							if (j2 > -1)
							{
								if (i2 > 0 && i2 < 9)
								{
									if (b1.grid[i2 - 1][j2] == b1.grid[i1][j1] && b1.grid[i2 + 1][j2] == b1.grid[i1][j1] && i2 - 1 != i1 && i2 + 1 != i1)
									{
										flag = 1;
									}
								}
								else if (j2 > 0 && j2 < 9)
								{
									if (b1.grid[i2][j2 + 1] == b1.grid[i1][j1] && b1.grid[i2][j2 - 1] == b1.grid[i1][j1] && j2 - 1 != j1 && j2 + 1 != j1)
									{
										flag = 1;
									}
								}
							}
							if (flag == 1)
							{
								swap(b1.grid[i1][j1], b1.grid[i2][j2]);
								initial_x = -5, initial_y = -5, end_x = -5, end_y = -5, tempx = y, tempy = 0;
							}
						}
					}
				}
				bool flag = 0;
				while (flag == 0)
				{
					bool if_match = b1.check_for_matches();
					b1.movegemsdown();
					b1.populate_grid_after_match();
					b1.draw_grid();
					if (if_match != true)
					{
						flag = 1;
					}
				}
			}

			if (m1.getstate() == 2)
			{
				if ((x >= 300 && y >= 530) && x <= 390 && y <= 550)
				{
					m1.setstate(0);
				}
				else if ((x >= 300 && y >= 380) && x <= 433 && y <= 405)
				{
					m1.setstate(3);
				}
				else if ((x >= 300 && y >= 430) && x <= 435 && y <= 450)
				{
					m1.setstate(5);
				}
				else if ((x >= 300 && y >= 480) && x <= 460 && y <= 500)
				{
					m1.setstate(8);
				}
			}

			if (m1.getstate() == 3)
			{
				if ((x >= 100 && y >= 670) && x <= 190 && y <= 690)
				{
					m1.setstate(2);
				}
			}

			if (m1.getstate() == 4)
			{
				if ((x >= 300 && y >= 580) && (x <= 380 && y <= 600))
				{
					m1.setstate(0);
				}
			}

			if (m1.getstate() == 5)
			{
				if ((x >= 300 && y >= 580) && x <= 390 && y <= 600)
				{
					m1.setstate(2);
				}
			}

			if (m1.getstate() == 6)
			{
				if ((x >= 300 && y >= 630) && x <= 390 && y <= 650)
				{
					m1.setstate(0);
				}
			}

			if (m1.getstate() == 7)
			{
				if ((x >= 200 && y >= 670) && x <= 290 && y <= 690)
				{
					m1.setstate(0);
				}
				else if ((x >= 300 && y >= 430) && x <= 470 && y <= 450)
				{
					b1.settimetrial(1);
				}
				else if ((x >= 300 && y >= 380) && x <= 440 && y <= 400)
				{
					b1.settimetrial(0);
				}
			}

			if (m1.getstate() == 8)
			{
				if ((x >= 300 && y >= 630) && x <= 390 && y <= 650)
				{
					m1.setstate(2);
				}
			}
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			
		}
		glutPostRedisplay();
	}
}

void resize(int width, int height) //To prevent changing the game display size
{
	glutReshapeWindow(800, 700);
}


int main(int argc, char*argv[]) {

	int width = 800, height = 700;

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	glutReshapeFunc(resize);

	if (b1.getplayername() == "")
	{
		b1.setplayername();
	}
	b1.gethighscores();

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	glutMainLoop();
	return 1;
}
#endif
