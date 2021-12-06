#pragma once
using namespace std;

class menu
{
private:
	int state = 0;

public:
	void setstate(int);
	int getstate();
	void drawmenu();
	void settings();
	void howtoplay();
	void highscores();
	void playerprofile();
	void levels();
	void levelmodes();
	void soundmusic();
};
