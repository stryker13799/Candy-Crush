#include "board.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "util.h"
using namespace std;


board::board()
{
	ifstream file;
	file.open("gamestate.txt");
	if (file.good())
	{
		file >> playername;
		file >> score;
		file >> level;
		file >> lives;
		file >> actualreqscore;
		file >> actualscore;
	}
	file.close();

	grid.resize(row + 1);
	for (int i = 0; i < row; i++)
	{
		grid[i].resize(col + 1);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int num = GetRandInRange(0, 5);
			grid[i][j] = num;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 0 && (i - 1) >= 0 && grid[i - 1][j] == 0 && (i - 2) >= 0 && grid[i - 2][j] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (i - 1) >= 0 && grid[i - 1][j] == 1 && (i - 2) >= 0 && grid[i - 2][j] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (i - 1) >= 0 && grid[i - 1][j] == 2 && (i - 2) >= 0 && grid[i - 2][j] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (i - 1) >= 0 && grid[i - 1][j] == 3 && (i - 2) >= 0 && grid[i - 2][j] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (i - 1) >= 0 && grid[i - 1][j] == 4 && (i - 2) >= 0 && grid[i - 2][j] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
			if (grid[i][j] == 0 && (j - 1) >= 0 && grid[i][j - 1] == 0 && (j - 2) >= 0 && grid[i][j - 2] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (j - 1) >= 0 && grid[i][j - 1] == 1 && (j - 2) >= 0 && grid[i][j - 2] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (j - 1) >= 0 && grid[i][j - 1] == 2 && (j - 2) >= 0 && grid[i][j - 2] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (j - 1) >= 0 && grid[i][j - 1] == 3 && (j - 2) >= 0 && grid[i][j - 2] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (j - 1) >= 0 && grid[i][j - 1] == 4 && (j - 2) >= 0 && grid[i][j - 2] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
		}
	}
}

void board::draw_grid()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 0)
			{
				DrawSquare(100+(i*50), 100 + (j* 50), 40, colors[RED]);
			}
			else if (grid[i][j] == 1)
			{
				DrawRectangle(100 + (i * 50), 110 + (j * 50), 40, 25, colors[GREEN]);
			}
			else if (grid[i][j] == 2)
			{
				DrawCircle(120 + (i * 50), 120 + (j * 50), 20, colors[YELLOW]);
			}
			else if (grid[i][j] == 3)
			{
				Torus2d(110 + (i * 50), 150 + (j * 50), 250, 70, 20, 20, 3, colors[BLUE]);
			}
			else if (grid[i][j] == 4)
			{
				DrawLine(120 + (i * 50), 100 + (j * 50), 120 + (i * 50), 140 + (j * 50), 100, colors[GOLD]);
			}
			else if (grid[i][j] == -1)
			{
				DrawSquare(100 + (i * 50), 100 + (j * 50), 40, colors[GOLD]);
				hint = 1;
			}
		}
	}
}

int board::getscore()
{
	return score;
}

void board::setscore(int scr)
{
	score = scr;
}

int board::gethigh_score()
{
	return high_score;
}

void board::sethigh_score(int scr)
{
	high_score = scr;
}

string board::getplayername()
{
	return playername;
}

void board::setplayername()
{
	cout << "\nPlease enter your name\n";
	string name;
	getline(cin, name);
	playername = name;
}

int board::getlevel()
{
	return level;
}

void board::setlevel(int lvl)
{
	level = lvl;
}

int board::getlives()
{
	return lives;
}

void board::setlives(int lvs)
{
	lives = lvs;
}

string board::convert_score_to_string()
{
	stringstream ss;
	ss << score;
	string scr;
	ss >> scr;
	return scr;
}

string board::convert_required_score_to_string()
{
	stringstream ss;
	ss << required_score;
	string scr;
	ss >> scr;
	return scr;
}

string board::convert_highscore_to_string()
{
	stringstream ss;
	ss << high_score;
	string scr;
	ss >> scr;
	return scr;
}

string board::convert_level_to_string()
{
	stringstream ss;
	ss << level;
	string lvl;
	ss >> lvl;
	return lvl;
}

void board::draw_lives()
{
	if (getlives() == 3)
	{
		DrawCircle(700, 15, 10, colors[RED]);
		DrawCircle(730, 15, 10, colors[RED]);
		DrawCircle(760, 15, 10, colors[RED]);
	}
	else if (getlives() == 2)
	{
		DrawCircle(700, 15, 10, colors[RED]);
		DrawCircle(730, 15, 10, colors[RED]);
	}
	else if (getlives() == 1)
	{
		DrawCircle(700, 15, 10, colors[RED]);
	}
}

bool board::check_for_matches()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i < 8)
			{
				if (grid[i + 1][j] == grid[i][j])
				{
					if (grid[i + 2][j] == grid[i][j])
					{
						if (i < 7)
						{
							if (grid[i + 3][j] == grid[i][j])
							{
								if (i < 6)
								{
									if (grid[i + 4][j] == grid[i][j])
									{
										if (i < 5)
										{
											if (grid[i + 5][j] == grid[i][j])
											{
												if (i < 4)
												{
													if (grid[i + 6][j] == grid[i][j])
													{
														if (i < 3)
														{
															if (grid[i + 7][j] == grid[i][j])
															{
																if (i < 2)
																{
																	if (grid[i + 8][j] == grid[i][j])
																	{
																		if (i < 1)
																		{
																			if (grid[i + 9][j] == grid[i][j])
																			{
																				int scr = getscore();
																				scr += 400;
																				int level_multiplier = getlevel() * 10;
																				setscore(scr + level_multiplier);
																				int acscr = actualscore;
																				acscr += 100;
																				actualscore = acscr + level_multiplier;
																				grid[i][j] = -1;
																				grid[i + 1][j] = -1;
																				grid[i + 2][j] = -1;
																				grid[i + 3][j] = -1;
																				grid[i + 4][j] = -1;
																				grid[i + 5][j] = -1;
																				grid[i + 6][j] = -1;
																				grid[i + 7][j] = -1;
																				grid[i + 8][j] = -1;
																				return true;
																			}
																			else
																			{
																				int scr = getscore();
																				scr += 350;
																				int level_multiplier = getlevel() * 10;
																				setscore(scr + level_multiplier);
																				int acscr = actualscore;
																				acscr += 100;
																				actualscore = acscr + level_multiplier;
																				grid[i][j] = -1;
																				grid[i + 1][j] = -1;
																				grid[i + 2][j] = -1;
																				grid[i + 3][j] = -1;
																				grid[i + 4][j] = -1;
																				grid[i + 5][j] = -1;
																				grid[i + 6][j] = -1;
																				grid[i + 7][j] = -1;
																				return true;
																			}
																		}
																		else
																		{
																			int scr = getscore();
																			scr += 350;
																			int level_multiplier = getlevel() * 10;
																			setscore(scr + level_multiplier);
																			int acscr = actualscore;
																			acscr += 100;
																			actualscore = acscr + level_multiplier;
																			grid[i][j] = -1;
																			grid[i + 1][j] = -1;
																			grid[i + 2][j] = -1;
																			grid[i + 3][j] = -1;
																			grid[i + 4][j] = -1;
																			grid[i + 5][j] = -1;
																			grid[i + 6][j] = -1;
																			grid[i + 7][j] = -1;
																			return true;
																		}
																	}
																	else
																	{
																		int scr = getscore();
																		scr += 300;
																		int level_multiplier = getlevel() * 10;
																		setscore(scr + level_multiplier);
																		int acscr = actualscore;
																		acscr += 100;
																		actualscore = acscr + level_multiplier;
																		grid[i][j] = -1;
																		grid[i + 1][j] = -1;
																		grid[i + 2][j] = -1;
																		grid[i + 3][j] = -1;
																		grid[i + 4][j] = -1;
																		grid[i + 5][j] = -1;
																		grid[i + 6][j] = -1;
																		return true;
																	}
																}
																else
																{
																	int scr = getscore();
																	scr += 300;
																	int level_multiplier = getlevel() * 10;
																	setscore(scr + level_multiplier);
																	int acscr = actualscore;
																	acscr += 100;
																	actualscore = acscr + level_multiplier;
																	grid[i][j] = -1;
																	grid[i + 1][j] = -1;
																	grid[i + 2][j] = -1;
																	grid[i + 3][j] = -1;
																	grid[i + 4][j] = -1;
																	grid[i + 5][j] = -1;
																	grid[i + 6][j] = -1;
																	return true;
																}
															}
														}
														else
														{
															int scr = getscore();
															scr += 250;
															int level_multiplier = getlevel() * 10;
															setscore(scr + level_multiplier);
															int acscr = actualscore;
															acscr += 100;
															actualscore = acscr + level_multiplier;
															grid[i][j] = -1;
															grid[i + 1][j] = -1;
															grid[i + 2][j] = -1;
															grid[i + 3][j] = -1;
															grid[i + 4][j] = -1;
															grid[i + 5][j] = -1;
															return true;
														}
													}
													else
													{
														int scr = getscore();
														scr += 250;
														int level_multiplier = getlevel() * 10;
														setscore(scr + level_multiplier);
														int acscr = actualscore;
														acscr += 100;
														actualscore = acscr + level_multiplier;
														grid[i][j] = -1;
														grid[i + 1][j] = -1;
														grid[i + 2][j] = -1;
														grid[i + 3][j] = -1;
														grid[i + 4][j] = -1;
														grid[i + 5][j] = -1;
														return true;
													}
												}
											}
											else
											{
												int scr = getscore();
												scr += 200;
												int level_multiplier = getlevel() * 10;
												setscore(scr + level_multiplier);
												int acscr = actualscore;
												acscr += 100;
												actualscore = acscr + level_multiplier;
												grid[i][j] = -1;
												grid[i + 1][j] = -1;
												grid[i + 2][j] = -1;
												grid[i + 3][j] = -1;
												grid[i + 4][j] = -1;
												return true;
											}
										}
										else
										{
											int scr = getscore();
											scr += 200;
											int level_multiplier = getlevel() * 10;
											setscore(scr + level_multiplier);
											int acscr = actualscore;
											acscr += 100;
											actualscore = acscr + level_multiplier;
											grid[i][j] = -1;
											grid[i + 1][j] = -1;
											grid[i + 2][j] = -1;
											grid[i + 3][j] = -1;
											grid[i + 4][j] = -1;
											return true;
										}
									}
									else
									{
										int scr = getscore();
										scr += 150;
										int level_multiplier = getlevel() * 10;
										setscore(scr + level_multiplier);
										int acscr = actualscore;
										acscr += 100;
										actualscore = acscr + level_multiplier;
										grid[i][j] = -1;
										grid[i + 1][j] = -1;
										grid[i + 2][j] = -1;
										grid[i + 3][j] = -1;
										return true;
									}
								}
								else
								{
									int scr = getscore();
									scr += 150;
									int level_multiplier = getlevel() * 10;
									setscore(scr + level_multiplier);
									int acscr = actualscore;
									acscr += 100;
									actualscore = acscr + level_multiplier;
									grid[i][j] = -1;
									grid[i + 1][j] = -1;
									grid[i + 2][j] = -1;
									grid[i + 3][j] = -1;
									return true;
								}

							}
							else
							{
								int scr = getscore();
								scr += 100;
								int level_multiplier = getlevel() * 10;
								setscore(scr + level_multiplier);
								int acscr = actualscore;
								acscr += 100;
								actualscore = acscr + level_multiplier;
								grid[i][j] = -1;
								grid[i + 1][j] = -1;
								grid[i + 2][j] = -1;
								return true;
							}
						}
						else
						{
							int scr = getscore();
							scr += 100;
							int level_multiplier = getlevel() * 10;
							setscore(scr + level_multiplier);
							int acscr = actualscore;
							acscr += 100;
							actualscore = acscr + level_multiplier;
							grid[i][j] = -1;
							grid[i + 1][j] = -1;
							grid[i + 2][j] = -1;
							return true;
						}
					}
				}
			}
			

			if (j < 8)
			{
				if (grid[i][j+1] == grid[i][j])
				{
					if (grid[i][j+2] == grid[i][j])
					{
						if (j < 7)
						{
							if (grid[i][j+3] == grid[i][j])
							{
								if (j < 6)
								{
									if (grid[i][j+4] == grid[i][j])
									{
										if (j < 5)
										{
											if (grid[i][j+5] == grid[i][j])
											{
												if (j < 4)
												{
													if (grid[i][j+6] == grid[i][j])
													{
														if (j < 3)
														{
															if (grid[i][j+7] == grid[i][j])
															{
																if (j < 2)
																{
																	if (grid[i][j+8] == grid[i][j])
																	{
																		if (j < 1)
																		{
																			if (grid[i][j+9] == grid[i][j])
																			{
																				int scr = getscore();
																				scr += 400;
																				int level_multiplier = getlevel() * 10;
																				setscore(scr + level_multiplier);
																				int acscr = actualscore;
																				acscr += 100;
																				actualscore = acscr + level_multiplier;
																				grid[i][j] = -1;
																				grid[i][j+1] = -1;
																				grid[i][j+2] = -1;
																				grid[i][j+3] = -1;
																				grid[i][j+4] = -1;
																				grid[i][j+5] = -1;
																				grid[i][j+6] = -1;
																				grid[i][j+7] = -1;
																				grid[i][j+8] = -1;
																				return true;
																			}
																			else
																			{
																				int scr = getscore();
																				scr += 350;
																				int level_multiplier = getlevel() * 10;
																				setscore(scr + level_multiplier);
																				int acscr = actualscore;
																				acscr += 100;
																				actualscore = acscr + level_multiplier;
																				grid[i][j] = -1;
																				grid[i][j + 1] = -1;
																				grid[i][j + 2] = -1;
																				grid[i][j + 3] = -1;
																				grid[i][j + 4] = -1;
																				grid[i][j + 5] = -1;
																				grid[i][j + 6] = -1;
																				grid[i][j + 7] = -1;
																				return true;
																			}
																		}
																		else
																		{
																			int scr = getscore();
																			scr += 350;
																			int level_multiplier = getlevel() * 10;
																			setscore(scr + level_multiplier);
																			int acscr = actualscore;
																			acscr += 100;
																			actualscore = acscr + level_multiplier;
																			grid[i][j] = -1;
																			grid[i][j + 1] = -1;
																			grid[i][j + 2] = -1;
																			grid[i][j + 3] = -1;
																			grid[i][j + 4] = -1;
																			grid[i][j + 5] = -1;
																			grid[i][j + 6] = -1;
																			grid[i][j + 7] = -1;
																			return true;
																		}
																	}
																	else
																	{
																		int scr = getscore();
																		scr += 300;
																		int level_multiplier = getlevel() * 10;
																		setscore(scr + level_multiplier);
																		int acscr = actualscore;
																		acscr += 100;
																		actualscore = acscr + level_multiplier;
																		grid[i][j] = -1;
																		grid[i][j + 1] = -1;
																		grid[i][j + 2] = -1;
																		grid[i][j + 3] = -1;
																		grid[i][j + 4] = -1;
																		grid[i][j + 5] = -1;
																		grid[i][j + 6] = -1;
																		return true;
																	}
																}
																else
																{
																	int scr = getscore();
																	scr += 300;
																	int level_multiplier = getlevel() * 10;
																	setscore(scr + level_multiplier);
																	int acscr = actualscore;
																	acscr += 100;
																	actualscore = acscr + level_multiplier;
																	grid[i][j] = -1;
																	grid[i][j + 1] = -1;
																	grid[i][j + 2] = -1;
																	grid[i][j + 3] = -1;
																	grid[i][j + 4] = -1;
																	grid[i][j + 5] = -1;
																	grid[i][j + 6] = -1;
																	return true;
																}
															}
														}
														else
														{
															int scr = getscore();
															scr += 250;
															int level_multiplier = getlevel() * 10;
															setscore(scr + level_multiplier);
															int acscr = actualscore;
															acscr += 100;
															actualscore = acscr + level_multiplier;
															grid[i][j] = -1;
															grid[i][j + 1] = -1;
															grid[i][j + 2] = -1;
															grid[i][j + 3] = -1;
															grid[i][j + 4] = -1;
															grid[i][j + 5] = -1;
															return true;
														}
													}
													else
													{
														int scr = getscore();
														scr += 250;
														int level_multiplier = getlevel() * 10;
														setscore(scr + level_multiplier);
														int acscr = actualscore;
														acscr += 100;
														actualscore = acscr + level_multiplier;
														grid[i][j] = -1;
														grid[i][j + 1] = -1;
														grid[i][j + 2] = -1;
														grid[i][j + 3] = -1;
														grid[i][j + 4] = -1;
														grid[i][j + 5] = -1;
														return true;
													}
												}
											}
											else
											{
												int scr = getscore();
												scr += 200;
												int level_multiplier = getlevel() * 10;
												setscore(scr + level_multiplier);
												int acscr = actualscore;
												acscr += 100;
												actualscore = acscr + level_multiplier;
												grid[i][j] = -1;
												grid[i][j + 1] = -1;
												grid[i][j + 2] = -1;
												grid[i][j + 3] = -1;
												grid[i][j + 4] = -1;
												return true;
											}
										}
										else
										{
											int scr = getscore();
											scr += 200;
											int level_multiplier = getlevel() * 10;
											setscore(scr + level_multiplier);
											int acscr = actualscore;
											acscr += 100;
											actualscore = acscr + level_multiplier;
											grid[i][j] = -1;
											grid[i][j + 1] = -1;
											grid[i][j + 2] = -1;
											grid[i][j + 3] = -1;
											grid[i][j + 4] = -1;
											return true;
										}
									}
									else
									{
										int scr = getscore();
										scr += 150;
										int level_multiplier = getlevel() * 10;
										setscore(scr + level_multiplier);
										int acscr = actualscore;
										acscr += 100;
										actualscore = acscr + level_multiplier;
										grid[i][j] = -1;
										grid[i][j + 1] = -1;
										grid[i][j + 2] = -1;
										grid[i][j + 3] = -1;
										return true;
									}
								}
								else
								{
									int scr = getscore();
									scr += 150;
									int level_multiplier = getlevel() * 10;
									setscore(scr + level_multiplier);
									int acscr = actualscore;
									acscr += 100;
									actualscore = acscr + level_multiplier;
									grid[i][j] = -1;
									grid[i][j + 1] = -1;
									grid[i][j + 2] = -1;
									grid[i][j + 3] = -1;
									return true;
								}
							}
							else
							{
								int scr = getscore();
								scr += 100;
								int level_multiplier = getlevel() * 10;
								setscore(scr + level_multiplier);
								int acscr = actualscore;
								acscr += 100;
								actualscore = acscr + level_multiplier;
								grid[i][j] = -1;
								grid[i][j + 1] = -1;
								grid[i][j + 2] = -1;
								return true;
							}
						}
						else
						{
							int scr = getscore();
							scr += 100;
							int level_multiplier = getlevel() * 10;
							setscore(scr + level_multiplier);
							int acscr = actualscore;
							acscr += 100;
							actualscore = acscr + level_multiplier;
							grid[i][j] = -1;
							grid[i][j + 1] = -1;
							grid[i][j + 2] = -1;
							return true;
						}
					}
				}
			}

		}
	}

	if (getscore() >= getrequiredscore())
	{
		int current_level = getlevel();
		current_level++;
		setlevel(current_level);
		setrequiredscore();
		if (gettimetrial())
		{
			setactualscore(getrequiredscore() / 2);
			setlives(3);
		}
		else
		{
			actualscore = 0;
		}
		randomizegrid();
		draw_grid();
	}
}

void board::movegemsdown()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == -1)
			{
				for (int k = j; k > 0; k--)
				{
					swap(grid[i][k], grid[i][k - 1]);
				}
			}
		}
	}
}

void board::populate_grid_after_match()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == -1)
			{
				int num = GetRandInRange(0, 5);
				grid[i][j] = num;
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 0 && (i - 1) >= 0 && grid[i - 1][j] == 0 && (i - 2) >= 0 && grid[i - 2][j] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (i - 1) >= 0 && grid[i - 1][j] == 1 && (i - 2) >= 0 && grid[i - 2][j] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (i - 1) >= 0 && grid[i - 1][j] == 2 && (i - 2) >= 0 && grid[i - 2][j] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (i - 1) >= 0 && grid[i - 1][j] == 3 && (i - 2) >= 0 && grid[i - 2][j] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (i - 1) >= 0 && grid[i - 1][j] == 4 && (i - 2) >= 0 && grid[i - 2][j] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
			if (grid[i][j] == 0 && (j - 1) >= 0 && grid[i][j - 1] == 0 && (j - 2) >= 0 && grid[i][j - 2] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (j - 1) >= 0 && grid[i][j - 1] == 1 && (j - 2) >= 0 && grid[i][j - 2] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (j - 1) >= 0 && grid[i][j - 1] == 2 && (j - 2) >= 0 && grid[i][j - 2] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (j - 1) >= 0 && grid[i][j - 1] == 3 && (j - 2) >= 0 && grid[i][j - 2] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (j - 1) >= 0 && grid[i][j - 1] == 4 && (j - 2) >= 0 && grid[i][j - 2] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
		}
	}
}

int board::getrequiredscore()
{
	return required_score;
}

void board::setrequiredscore()
{
	required_score = required_score + (getlevel() * 500);
	actualreqscore = getlevel() * 500;
}

int board::gethigh_score2()
{
	return high_score_2;
}

void board::sethigh_score2(int scr)
{
	high_score_2 = scr;
}

int board::gethigh_score3()
{
	return high_score_3;
}

void board::sethigh_score3(int scr)
{
	high_score_3 = scr;
}

int board::gethigh_score4()
{
	return high_score_4;
}

void board::sethigh_score4(int scr)
{
	high_score_4 = scr;
}

void board::check_if_highscore()
{
	if (score > high_score)
	{
		swap(high_score_3, high_score_4);
		swap(high_score_2, high_score_3);
		swap(high_score, high_score_2);
		high_score = score;

		ofstream file;
		file.open("Highscores.txt");
		if (file.good())
		{
			file << high_score << " " << high_score_2 << " " << high_score_3 << " " << high_score_4;
		}
		else
		{
			cout << "\nOpening file for saving highscores failed\n";
		}
		file.close();
		return;
	}
	if (score > high_score_2)
	{
		swap(high_score_3, high_score_4);
		swap(high_score_2, high_score_3);
		high_score_2 = score;

		ofstream file;
		file.open("Highscores.txt");
		if (file.good())
		{
			file << high_score << " " << high_score_2 << " " << high_score_3 << " " << high_score_4;
		}
		else
		{
			cout << "\nOpening file for saving highscores failed\n";
		}
		file.close();
		return;
	}
	if (score > high_score_3)
	{
		swap(high_score_3, high_score_4);
		high_score_3 = score;

		ofstream file;
		file.open("Highscores.txt");
		if (file.good())
		{
			file << high_score << " " << high_score_2 << " " << high_score_3 << " " << high_score_4;
		}
		else
		{
			cout << "\nOpening file for saving highscores failed\n";
		}
		file.close();
		return;
	}
	if (score > high_score_4)
	{
		high_score_4 = score;

		ofstream file;
		file.open("Highscores.txt");
		if (file.good())
		{
			file << high_score << " " << high_score_2 << " " << high_score_3 << " " << high_score_4;
		}
		else
		{
			cout << "\nOpening file for saving highscores failed\n";
		}
		file.close();
		return;
	}
}

void board::gethighscores()
{
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
}

void board::setprogressbar()
{
	double x= ((double)actualreqscore / (double)700.0);
	progressbar = x;
}

void board::drawprogressbar()
{
	if (progressbar!=0)
	{
		int x = actualscore / progressbar;
		for (int i = 0; i < x; i++)
		{
			DrawSquare(105 + i, 635, 20, colors[TEAL]);
		}
	}
}

void board::randomizegrid()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int num = GetRandInRange(0, 5);
			grid[i][j] = num;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 0 && (i - 1) >= 0 && grid[i - 1][j] == 0 && (i - 2) >= 0 && grid[i - 2][j] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (i - 1) >= 0 && grid[i - 1][j] == 1 && (i - 2) >= 0 && grid[i - 2][j] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (i - 1) >= 0 && grid[i - 1][j] == 2 && (i - 2) >= 0 && grid[i - 2][j] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (i - 1) >= 0 && grid[i - 1][j] == 3 && (i - 2) >= 0 && grid[i - 2][j] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (i - 1) >= 0 && grid[i - 1][j] == 4 && (i - 2) >= 0 && grid[i - 2][j] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
			if (grid[i][j] == 0 && (j - 1) >= 0 && grid[i][j - 1] == 0 && (j - 2) >= 0 && grid[i][j - 2] == 0)
			{
				int num = GetRandInRange(1, 5);
				grid[i][j] = num;
			}
			if (grid[i][j] == 1 && (j - 1) >= 0 && grid[i][j - 1] == 1 && (j - 2) >= 0 && grid[i][j - 2] == 1)
			{
				int num = GetRandInRange(0, 5);
				while (num == 1)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 2 && (j - 1) >= 0 && grid[i][j - 1] == 2 && (j - 2) >= 0 && grid[i][j - 2] == 2)
			{
				int num = GetRandInRange(0, 5);
				while (num == 2)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 3 && (j - 1) >= 0 && grid[i][j - 1] == 3 && (j - 2) >= 0 && grid[i][j - 2] == 3)
			{
				int num = GetRandInRange(0, 5);
				while (num == 3)
				{
					num = GetRandInRange(0, 5);
				}
				grid[i][j] = num;
			}
			if (grid[i][j] == 4 && (j - 1) >= 0 && grid[i][j - 1] == 4 && (j - 2) >= 0 && grid[i][j - 2] == 4)
			{
				int num = GetRandInRange(0, 4);
				grid[i][j] = num;
			}
		}
	}
}

void board::setactualscore(int scr)
{
	actualscore = scr;
}

void board::setactualreqscore(int scr)
{
	actualreqscore=scr;
}

int board::getrow()
{
	return row;
}

int board::getcol()
{
	return col;
}

bool board::gethint()
{
	return hint;
}

void board::sethint(bool hnt)
{
	hint = hnt;
}

bool board::getpaused()
{
	return paused;
}

void board::setpaused(bool state)
{
	paused = state;
}

void board::playerprofile()
{
	ifstream file;
	file.open("profile.txt");
	int score = 0;
	if (file.good())
	{
		file >> score;
	}
	file.close();

	if (getlevel() > score)
	{
		ofstream file;
		file.open("profile.txt");
		if (file.good())
		{
			file << getlevel() << endl;
			file << getplayername();
		}
		file.close();
	}
}

void board::gridtogrid2()
{
	grid2.resize(row + 1);
	for (int i = 0; i < row; i++)
	{
		grid[i].resize(col + 1);
	}

	grid2 = grid;
}

void board::grid2togrid()
{
	grid = grid2;
}

bool board::gettimetrial()
{
	return timetrial;
}

void board::settimetrial(bool state)
{
	timetrial = state;
}

void board::decrementprogressbar()
{
	actualscore--;
}

void board::decrementlives()
{
	lives--;
}

int board::getactualscore()
{
	return actualscore;
}

void board::gamestate()
{
	ofstream file;
	file.open("gamestate.txt");
	if (file.good())
	{
		file << playername << endl;
		file << score << endl;
		file << level << endl;
		file << lives << endl;
		file << actualreqscore << endl;
		file << actualscore << endl;
	}
	file.close();
}