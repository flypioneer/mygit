#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int num;												//ÈáÐÔÌõŒþ(ÓÐÌØÊâÒªÇóµÄ»€Ê¿ºÅ)
int day;												//ÈáÐÔÌõŒþ(ÓÐÌØÊâÒªÇóµÄÈÕÆÚ)
int turn;												//ÈáÐÔÌõŒþ(ÓÐÌØÊâÒªÇóµÄ°àŽÎ)
int answer;												//ÏìÓŠÌØÊâÒªÇó
int point;												//¶šÒåœ»²æµã
int nightwork = 0;										//Í³ŒÆÒ¹°àÊý
int nightwork1 = 0;										//Í³ŒÆÒ¹°àÊý
#define nurse 16										//¶šÒå»€Ê¿ÊýÁ¿
int old_nurse;											//ÀÏ»€Ê¿ÊýÁ¿
int N = 2;												//ÉèÖÃËæ»úÊýµÄ·¶Î§(ÓÃÓÚËæ»úÊÇ·ñÉÏ°àµÄ»ùÒòÐòÁÐ)
int nurse_table[nurse][93];								//¶šÒå»€Ê¿±í1
int nurse_table1[nurse][93];							//¶šÒå»€Ê¿±í2
int total_fitness[nurse];								//Ž¢Žæ±í1ÊÊÓŠ¶È
int main_fitness;										//Ž¢Žæ±í1×ÜÊÊÓŠ¶È
int total_fitness1[nurse];								//Ž¢Žæ±í2ÊÊÓŠ¶È
int main_fitness1;										//Ž¢Žæ±í2×ÜÊÊÓŠ¶È
void initializePopulation()								//³õÊŒ»¯ÖÖÈº
{
	srand(time(0));
	int position_1;
	int position_2;
	int position_3;
	int position_4;
	for (int j = 0; j < 93; j +=3)						//Ê¹ÀÏ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Ôç°àÓÐÁœÃûÀÏ»€Ê¿)	
	{
		position_1 = rand() % old_nurse;
		nurse_table[position_1][j] = 1;		
		position_2 = rand() % old_nurse;
		while (position_1 == position_2)
		{
			position_2 = rand() % old_nurse;
		}
		nurse_table[position_2][j] = 1;			
		
		position_1 = rand() % old_nurse;
		nurse_table1[position_1][j] = 1;
		position_2 = rand() % old_nurse;
		while (position_1 == position_2)
		{
			position_2 = rand() % old_nurse;
		}
		nurse_table1[position_2][j] = 1;
	}

	for (int j = 1; j < 93; j += 3)						//Ê¹ÀÏ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Íí°àÓÐÒ»ÃûÀÏ»€Ê¿)	
	{
		position_1 = rand() % old_nurse;
		nurse_table[position_1][j] = 1;

		position_1 = rand() % old_nurse;
		nurse_table1[position_1][j] = 1;
	}

	for (int j = 2; j < 93; j += 3)						//Ê¹ÀÏ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Ò¹°àÓÐÒ»ÃûÀÏ»€Ê¿)	
	{
		position_1 = rand() % old_nurse;
		nurse_table[position_1][j] = 1;

		position_1 = rand() % old_nurse;
		nurse_table1[position_1][j] = 1;
	}

	for (int j = 0; j < 93; j += 3)						//Ê¹ÐÂ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Ôç°àÓÐËÄÃûÐÂ»€Ê¿)	
	{
		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table[position_2][j] = 1;
		position_3 = old_nurse + rand() % (nurse - old_nurse);
		while (position_3 == position_1 || position_3 == position_2)
		{
			position_3 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table[position_3][j] = 1;
		position_4 = old_nurse + rand() % (nurse - old_nurse);
		while (position_4 == position_1 || position_4 == position_2 || position_4 == position_3)
		{
			position_4 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table[position_4][j] = 1;

		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table1[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table1[position_2][j] = 1;
		position_3 = old_nurse + rand() % (nurse - old_nurse);
		while (position_3 == position_1 || position_3 == position_2)
		{
			position_3 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table1[position_3][j] = 1;
		position_4 = old_nurse + rand() % (nurse - old_nurse);
		while (position_4 == position_1 || position_4 == position_2 || position_4 == position_3)
		{
			position_4 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table1[position_4][j] = 1;
	}

	for (int j = 1; j < 93; j += 3)						//Ê¹ÐÂ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Íí°àÓÐÁœÃûÐÂ»€Ê¿)	
	{
		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table[position_2][j] = 1;

		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table1[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table1[position_2][j] = 1;
	}

	for (int j = 2; j < 93; j += 3)						//Ê¹ÐÂ»€Ê¿Âú×ãÓ²ÐÔÅÅ°à(Ò¹°àÓÐÁœÃûÐÂ»€Ê¿)	
	{
		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table[position_2][j] = 1;

		position_1 = old_nurse + rand() % (nurse - old_nurse);
		nurse_table1[position_1][j] = 1;
		position_2 = old_nurse + rand() % (nurse - old_nurse);
		while (position_1 == position_2)
		{
			position_2 = old_nurse + rand() % (nurse - old_nurse);
		}
		nurse_table1[position_2][j] = 1;
	}
}
void countFitness()										//ÊÊÓŠ¶ÈŒÆËã
{
	double avg_nightwork = 0;
	double avg_nightwork1 = 0;
	for (int i = 0; i < nurse; i++)						//ŒÆËã±í1ÆœŸùÒ¹°àÊý
	{		
		for (int j = 2; j < 93; j = j + 3)				
		{
			 if(nurse_table[i][j] == 1)
			{
				nightwork++;
			}
		}
	}
	avg_nightwork = (double)nightwork / nurse;

	for (int i = 0; i < nurse; i++)						//ŒÆËã±í2ÆœŸùÒ¹°àÊý
	{
		for (int j = 2; j < 93; j = j + 3)
		{
			if (nurse_table1[i][j] == 1)
			{
				nightwork1++;
			}
		}
	}
	avg_nightwork1 = (double)nightwork1 / nurse;

	for (int i = 0; i < nurse; i++)
	{
		bool threework= false;
		bool freework = false;
		bool busywork = false;
		bool threework1 = false;
		bool freework1 = false;
		bool busywork1 = false;
		int fitness = 100;
		int fitness1 = 100;
		int flag_threework = 0;
		int flag_busywork = 0;
		int flag_freework = 0;
		int flag_threework1 = 0;
		int flag_busywork1 = 0;
		int flag_freework1 = 0;
		nightwork = 0;
		nightwork1 = 0;

		for (int j = 2; j < 93; j = j + 3)				//ÈáÐÔÌõŒþ£šÔœœÓœüÆœŸùÒ¹°àÊýÔœºÃ£©
		{
			if (nurse_table[i][j] == 1)
			{
				nightwork++;
			}

			if (nurse_table1[i][j] == 1)
			{
				nightwork1++;
			}
		}

		if (abs(avg_nightwork - nightwork)>2)
		{
			fitness -= 10;
		}
		if (abs(avg_nightwork1 - nightwork1)>2)
		{
			fitness1 -= 10;
		}
		for (int j = 0; j < 93; j++)						
		{				

			if (nurse_table[i][j] == 1)					//±ÜÃâÈýÁ¬°à
			{
				flag_threework++;
				if (flag_threework>3)
				{
					threework = true;
				}
			}
			else
			{
				flag_threework = 0;
			}


			if (nurse_table1[i][j] == 1)					
			{
				flag_threework1++;
				if (flag_threework1>3)
				{
					threework1 = true;
				}
			}
			else
			{
				flag_threework1 = 0;
			}

			if (nurse_table[i][j] == 0)					//±ÜÃâÁ¬ÐøÐÝÏ¢5ÌìÒÔÉÏ
			{
				flag_freework++;
				if (flag_freework > 20)
				{
					freework = true;
				}
			}
			else
			{
				flag_freework = 0;
			}

			if (nurse_table1[i][j] == 0)		
			{
				flag_freework1++;
				if (flag_freework1 > 20)
				{
					freework1 = true;
				}
			}
			else
			{
				flag_freework1 = 0;
			}
			
			for (int k = 0; k < 29; k = k + 3)			//±ÜÃâÁ¬Ðø¹€×÷5ÌìÒÔÉÏ
			{
				if (nurse_table[i][k] + nurse_table[i][k + 1] + nurse_table[i][k + 2]>0)
				{
					flag_busywork++;
				}
			}
			if (flag_busywork >6)
			{
				busywork = true;
			}

			for (int k = 0; k < 29; k = k + 3)			
			{
				if (nurse_table1[i][k] + nurse_table1[i][k + 1] + nurse_table1[i][k + 2]>0)
				{
					flag_busywork1++;
				}
			}
			if (flag_busywork1 >6)
			{
				busywork1 = true;
			}
		}
		if (threework)
		{
			fitness -= 10;
		}
		if (freework)
		{
			fitness -= 20;
		}
		if (busywork)
		{
			fitness -= 20;
		}

		if (threework)
		{
			fitness1 -= 10;
		}
		if (freework)
		{
			fitness1 -= 20;
		}
		if (busywork)
		{
			fitness1 -= 20;
		}

		if (nurse_table[num - 1][day + turn - 2] == 1)	//Î¥·ŽÌØÊâÒªÇó»€Ê¿¿Û·Ö
		{
			fitness -= 10;
		}

		if (nurse_table1[num - 1][day + turn - 2] == 1)	
		{
			fitness1 -= 10;
		}
		total_fitness[i] = fitness;
		total_fitness1[i] = fitness1;
	}
}
void selectPopulation()									//Ñ¡Ôñ
{
	srand(time(0));
	point = rand() % 31 + 1;
}
void populationCrossover()								//œ»²æ
{
	int temp;
	for (int i = (point - 1) * 3; i <(point - 1) * 3 + 3; i++)					//œ»²æ
	{
		for (int j = 0; j < nurse; j++)
		{
			temp = nurse_table[j][i];
			nurse_table[j][i] = nurse_table1[j][i];
			nurse_table1[j][i] = temp;
		}
	}
}
void alterPopulation()									//±äÒì
{
	srand(time(0));
	int alter;
	int alter_old;
	int alter_new;
	for (int i = 0; i < nurse; i++)						//¶Ô±í1œøÐÐ±äÒì
	{
		for (int j = 0; j < 93; j++)
		{
			alter = rand() % 100 + 1;
			if (alter == 1)
			{
				if (nurse_table[i][j] == 1)
				{
					nurse_table[i][j] = 0;
					if (j < old_nurse)					//Ê¹Ã¿ŽÎ±äÒì¶Œ±£Ö€Ó²ÐÔÌõŒþµÃµœÂú×ã(Õæ->ŒÙ)
					{
						alter_old = rand() % old_nurse;
						while (alter_old == i&&nurse_table[alter_old][j] != 1)
						{
							alter_old = rand() % old_nurse;
						}
						nurse_table[alter_old][j] = 1;
					}
					else
					{
						alter_new = old_nurse + rand() % (nurse - old_nurse);
						while (alter_new == i&&nurse_table[alter_new][j] != 1)
						{
							alter_new = rand() % old_nurse;
						}
						nurse_table[alter_new][j] = 1;
					}
				}
				else
				{
					nurse_table[i][j] = 1;
					if (j < old_nurse)				//Ê¹Ã¿ŽÎ±äÒì¶Œ±£Ö€Ó²ÐÔÌõŒþµÃµœÂú×ã(ŒÙ->Õæ)
					{
						alter_old = rand() % old_nurse;
						while (alter_old == i&&nurse_table[alter_old][j] != 0)
						{
							alter_old = rand() % old_nurse;
						}
						nurse_table[alter_old][j] = 0;
					}
					else
					{
						alter_new = old_nurse + rand() % (nurse - old_nurse);
						while (alter_new == i&&nurse_table[alter_new][j] != 0)
						{
							alter_new = rand() % old_nurse;
						}
						nurse_table[alter_new][j] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < nurse; i++)						//¶Ô±í2œøÐÐ±äÒì
	{
		for (int j = 0; j < 93; j++)
		{
			alter = rand() % 100 + 1;
			if (alter == 1)
			{
				if (nurse_table1[i][j] == 1)
				{
					nurse_table1[i][j] = 0;
					if (j < old_nurse)					//Ê¹Ã¿ŽÎ±äÒì¶Œ±£Ö€Ó²ÐÔÌõŒþµÃµœÂú×ã(Õæ->ŒÙ)
					{
						alter_old = rand() % old_nurse;
						while (alter_old == i&&nurse_table1[alter_old][j] != 1)
						{
							alter_old = rand() % old_nurse;
						}
						nurse_table1[alter_old][j] = 1;
					}
					else
					{
						alter_new = old_nurse + rand() % (nurse - old_nurse);
						while (alter_new == i&&nurse_table1[alter_new][j] != 1)
						{
							alter_new = rand() % old_nurse;
						}
						nurse_table1[alter_new][j] = 1;
					}
				}
				else
				{
					nurse_table1[i][j] = 1;
					if (j < old_nurse)				//Ê¹Ã¿ŽÎ±äÒì¶Œ±£Ö€Ó²ÐÔÌõŒþµÃµœÂú×ã(ŒÙ->Õæ)
					{
						alter_old = rand() % old_nurse;
						while (alter_old == i&&nurse_table1[alter_old][j] != 0)
						{
							alter_old = rand() % old_nurse;
						}
						nurse_table1[alter_old][j] = 0;
					}
					else
					{
						alter_new = old_nurse + rand() % (nurse - old_nurse);
						while (alter_new == i&&nurse_table1[alter_new][j] != 0)
						{
							alter_new = rand() % old_nurse;
						}
						nurse_table1[alter_new][j] = 0;
					}
				}
			}
		}
	}
}
void display()											//Êä³ö×îÖÕµÄ×îÓÅÅÅ°à±í
{
	int sum=0;
	int sum1=0;
	for (int i = 0; i < nurse; i++)
	{
		sum += total_fitness[i];
	}
	cout << "±í1ÊÊÓŠ¶È×ÜºÍÎª:" << sum << endl;

	for (int i = 0; i < nurse; i++)
	{
		sum1 += total_fitness1[i];
	}
	cout << "±í2ÊÊÓŠ¶È×ÜºÍÎª:" << sum1 << endl;
	if (sum>sum1)
	{
		cout << "×îÓÅÅÅ°à±íÎª±í1" << endl;
		for (int i = 0; i < nurse; i++)						
		{
			for (int j = 0; j < 93; j++)
			{
				cout << nurse_table[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}
	if (sum<sum1)
	{
		cout << "×îÓÅÅÅ°à±íÎª±í2" << endl;
		for (int i = 0; i < nurse; i++)					
		{
			for (int j = 0; j < 93; j++)
			{
				cout << nurse_table1[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}
	if (sum==sum1)
	{
		cout << "×îÓÅÅÅ°à±íÎª±í1ºÍ±í2" << endl;
		for (int i = 0; i < nurse; i++)					
		{
			for (int j = 0; j < 93; j++)
			{
				cout << nurse_table[i][j];
				cout << " ";
			}
			cout << endl;
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		for (int i = 0; i < nurse; i++)						
		{
			for (int j = 0; j < 93; j++)
			{
				cout << nurse_table1[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}

}
void main()
{
	cout << "ÇëÊäÈëÀÏ»€Ê¿ÊýÁ¿:";
	cin >> old_nurse;
	cout << "ÊÇ·ñŽæÔÚÓÐÌØÊâÒªÇóµÄ»€Ê¿,ÊäÈë1Îªyes,ÆäËûÔòÎª·ñ" << endl;
	cin >> answer;
	if(answer == 1)
	{
		cout << "ÇëÊäÈëÓÐÌØÊâÒªÇóµÄ»€Ê¿ºÅ,žñÊœÎª1,2....n" << endl;
		cin >> num;
		cout << "ÇëÊäÈëÓÐÌØÊâÒªÇóµÄÈÕÆÚ,žñÊœÎª1£¬2....31" << endl;
		cin >> day;
		cout << "ÇëÊäÈëÓÐÌØÊâÒªÇóµÄ°àŽÎ,1ÎªÔç°à£¬2ÎªÍí°à£¬3ÎªÒ¹°à" << endl;
		cin >> turn;
	}

	initializePopulation();
	for (int i = 0; i < 1000; i++)
	{
		countFitness();
		selectPopulation();
		populationCrossover();
		alterPopulation();
	}
	countFitness();
	display();
}