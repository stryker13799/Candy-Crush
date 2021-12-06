#pragma once
#include <string>
#include <vector>
using namespace std;

class board
{
private:
	const int max_xcoord = 700;
	const int max_ycoord = 500;
	const int row = 10;
	const int col = 10;
	int score = 0;
	int high_score = 0;
	int high_score_2 = 0;
	int high_score_3 = 0;
	int high_score_4 = 0;
	int level = 1;
	bool timetrial = 0;
	int timeleft = 0;
	int lives = 3;
	int required_score = level * 500;
	double progressbar = 0.0;
	string playername;
	int actualscore = 0;
	int actualreqscore = level * 500;
	bool hint = 0;
	bool paused = 0;

public:
	board();
	vector<vector<int>>grid;
	vector<vector<int>>grid2;
	void grid2togrid();
	void gridtogrid2();
	void draw_grid();
	int getscore();
	void setscore(int);
	int gethigh_score();
	void sethigh_score(int);
	int gethigh_score2();
	void sethigh_score2(int);
	int gethigh_score3();
	void sethigh_score3(int);
	int gethigh_score4();
	void sethigh_score4(int);
	string getplayername();
	void setplayername();
	int getlevel();
	void setlevel(int);
	int getlives();
	void setlives(int);
	string convert_score_to_string();
	string convert_required_score_to_string();
	string convert_level_to_string();
	string convert_highscore_to_string();
	void draw_lives();
	bool check_for_matches();
	void populate_grid_after_match();
	int getrequiredscore();
	void setrequiredscore();
	void check_if_highscore();
	void gethighscores();
	void setprogressbar();
	void drawprogressbar();
	void randomizegrid();
	void setactualscore(int);
	void setactualreqscore(int);
	int getrow();
	int getcol();
	bool gethint();
	void sethint(bool);
	bool getpaused();
	void setpaused(bool);
	void movegemsdown();
	void playerprofile();
	bool gettimetrial();
	void settimetrial(bool);
	void decrementprogressbar();
	void decrementlives();
	int getactualscore();
	void gamestate();
};