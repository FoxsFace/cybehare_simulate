#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Hare.h"
#include "Shotgun.h"
#include "HackerOptics.h"
#include "MilitaryOptics.h"
#include "SniperOptics.h"
#include "Body_Default.h"
#include "Paws_Default.h"

using namespace std;

void FillNamelist(string namelist[], const int SIZE)
{
	ifstream fin;
	fin.exceptions(ios_base::failbit | ios_base::badbit);
	try
	{
		fin.open("namelist.txt");
		for (int i = 0; i < SIZE; i++) { getline(fin, namelist[i]); }
		fin.close();
	}
	catch (const ifstream::failure& ex)
	{
		cout << "Error!" << endl;
		cout << ex.code() << endl;
		cout << ex.what() << endl;
		cout << "The error caused the program to be disabled" << endl;
		system("pause>null");
		exit(EXIT_FAILURE);
	}
}

void Shop(Hare* castomer) 
{
	
	float list[2][4];

	list[0][0] = 1;
	list[1][0] = castomer->GetReflexes();
	list[0][1] = 2;
	list[1][1] = castomer->GetAccuraty();
	list[0][2] = 3;
	list[1][2] = castomer->GetDurability();
	list[0][3] = 4;
	list[1][3] = castomer->GetFlexibility();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3-i; j++)
		{
			if (list[1][j] > list[1][j + 1])
			{
				float Value_Buffer;
				float Index_Buffer;
				Index_Buffer = list[0][j];
				list[0][j] = list[0][j + 1];
				list[0][j + 1] = Index_Buffer;
				Value_Buffer = list[1][j];
				list[1][j] = list[1][j+1];
				list[1][j+1] = Value_Buffer;
			}
		}
	} 

	if ((list[0][0]==1&&list[0][1]==2)||(list[0][0] == 2 && list[0][1] == 1))
	{
		SniperOptics *SO = new SniperOptics;
		castomer->equip(SO);
	}
	else
	{
		if ((list[0][0] == 1 && list[0][1] == 3) || (list[0][0] == 3 && list[0][1] == 1))
		{
			Body_Default* B = new Body_Default;
			castomer->equip(B);
		}
		else
		{
			if ((list[0][0] == 1 && list[0][1] == 4) || (list[0][0] == 4 && list[0][1] == 1))
			{
				Paws_Default* P = new Paws_Default;
				castomer->equip(P);
			}
			else
			{
				if ((list[0][0] == 2 && list[0][1] == 3) || (list[0][0] == 3 && list[0][1] == 2))
				{
					MilitaryOptics* MO = new MilitaryOptics;
					castomer->equip(MO);
				}
				else
				{
					if ((list[0][0] == 2 && list[0][1] == 4) || (list[0][0] == 4 && list[0][1] == 2))
					{
						HackerOptics* HO = new HackerOptics;
						castomer->equip(HO);
					}
					else
					{
						if ((list[0][0] == 3 && list[0][1] == 4) || (list[0][0] == 4 && list[0][1] == 3))
						{
							Paws_Default* P = new Paws_Default;
							castomer->equip(P);
						}
					}
				}
			}
		}
	}
	
	Shotgun* Sh = new Shotgun;
	Sh->equip(castomer);
}

void pause()
{
	cout << endl;
	system("pause");
	system("cls");
}

void list_of_fighters(vector<Hare> Hares)
{
	std::cout << "\nList of the fighters:" << std::endl;
	for (int i = 0; i < Hares.size(); i++)	
		cout << Hares[i].GetName() << endl; 
}

void select_n_fight(vector<Hare> Hares)
{
	int round_caunter = 1;
	while (Hares.size()>1)
	{
		cout << "\tRound " << round_caunter << endl;
		list_of_fighters(Hares);
		pause();
		int caunter = 1;
		random_shuffle(Hares.begin(), Hares.end());
		for (int i = Hares.size() - 1; i >= 0; i--)
		{
			if (i != 0)
			{
				cout << "\tbattle #" << caunter << endl;
				cout << "\t" << Hares[i].GetName() << " VS " << Hares[i - 1].GetName() << endl;
				cout << "_____________________________________________________________";
				Hares[i].info();
				Hares[i - 1].info();
				cout << "_____________________________________________________________";
				cout << "\nLets a battle begin!" << endl;
				system("pause");
				thread th(&Hare::Figth, &Hares[i], &Hares[i], &Hares[i - 1]);
				Hares[i - 1].Figth(&Hares[i - 1], &Hares[i]);
				if (Hares[i].GetStatus() != 0)
				{
					cout << "\t" << Hares[i].GetName() << " win!" << endl;
					*(Hares.begin() + (i - 1)) = *(Hares.begin() + i);
					Hares.erase(Hares.begin() + i);
					i--;
					Hares[i].recover();
				}
				else
				{
					if (Hares[i - 1].GetStatus() != 0)
					{
						cout << "\t" << Hares[i - 1].GetName() << " win!" << endl;
						Hares.erase(Hares.begin() + i);
						i--;
						Hares[i].recover();
					}
					else
					{
						cout << "\tBoth lost!" << endl;
						Hares.erase(Hares.begin() + i);
						i--;
						Hares.erase(Hares.begin() + i);
					}
				}
				th.join();
				caunter++;
				pause();
			}
		}
		round_caunter++;
	}
	switch (Hares.size())
	{
	case 0:
		cout << "\tNobody win!" << endl;
		break;
	case 1:
		cout << "\t" << Hares[0].GetName() << " is winner!";
		break;
	}
	pause();
}

void main()
{
	srand(time(NULL));
	
	const int namelist_size = 100;
	string namelist[namelist_size];
	FillNamelist(namelist, namelist_size);
	srand(time(NULL));

	vector<Hare> Hares;

	for (int i = 0; i < 10; i++)
	{
		Hare* hare = new Hare(namelist[rand() % 100]);
		Hares.push_back(*hare);
		Shop(&Hares[i]);
	}

	select_n_fight(Hares);
}