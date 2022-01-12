#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int num;												//脠谩脨脭脤玫艗镁(脫脨脤脴脢芒脪陋脟贸碌脛禄鈧娐柯好)
int day;												//脠谩脨脭脤玫艗镁(脫脨脤脴脢芒脪陋脟贸碌脛脠脮脝脷)
int turn;												//脠谩脨脭脤玫艗镁(脫脨脤脴脢芒脪陋脟贸碌脛掳脿沤脦)
int answer;												//脧矛脫艩脤脴脢芒脪陋脟贸
int point;												//露拧脪氓艙禄虏忙碌茫
int nightwork = 0;										//脥鲁艗脝脪鹿掳脿脢媒
int nightwork1 = 0;										//脥鲁艗脝脪鹿掳脿脢媒
#define nurse 16										//露拧脪氓禄鈧娐棵娒矫伮
int old_nurse;											//脌脧禄鈧娐棵娒矫伮
int N = 2;												//脡猫脰脙脣忙禄煤脢媒碌脛路露脦搂(脫脙脫脷脣忙禄煤脢脟路帽脡脧掳脿碌脛禄霉脪貌脨貌脕脨)
int nurse_table[nurse][93];								//露拧脪氓禄鈧娐柯泵1
int nurse_table1[nurse][93];							//露拧脪氓禄鈧娐柯泵2
int total_fitness[nurse];								//沤垄沤忙卤铆1脢脢脫艩露脠
int main_fitness;										//沤垄沤忙卤铆1脳脺脢脢脫艩露脠
int total_fitness1[nurse];								//沤垄沤忙卤铆2脢脢脫艩露脠
int main_fitness1;										//沤垄沤忙卤铆2脳脺脢脢脫艩露脠
void initializePopulation()								//鲁玫脢艗禄炉脰脰脠潞
{
	srand(time(0));
	int position_1;
	int position_2;
	int position_3;
	int position_4;
	for (int j = 0; j < 93; j +=3)						//脢鹿脌脧禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脭莽掳脿脫脨脕艙脙没脌脧禄鈧娐)	
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

	for (int j = 1; j < 93; j += 3)						//脢鹿脌脧禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脥铆掳脿脫脨脪禄脙没脌脧禄鈧娐)	
	{
		position_1 = rand() % old_nurse;
		nurse_table[position_1][j] = 1;

		position_1 = rand() % old_nurse;
		nurse_table1[position_1][j] = 1;
	}

	for (int j = 2; j < 93; j += 3)						//脢鹿脌脧禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脪鹿掳脿脫脨脪禄脙没脌脧禄鈧娐)	
	{
		position_1 = rand() % old_nurse;
		nurse_table[position_1][j] = 1;

		position_1 = rand() % old_nurse;
		nurse_table1[position_1][j] = 1;
	}

	for (int j = 0; j < 93; j += 3)						//脢鹿脨脗禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脭莽掳脿脫脨脣脛脙没脨脗禄鈧娐)	
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

	for (int j = 1; j < 93; j += 3)						//脢鹿脨脗禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脥铆掳脿脫脨脕艙脙没脨脗禄鈧娐)	
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

	for (int j = 2; j < 93; j += 3)						//脢鹿脨脗禄鈧娐棵偯好椕Ｃ撀裁惷斆吤吢懊(脪鹿掳脿脫脨脕艙脙没脨脗禄鈧娐)	
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
void countFitness()										//脢脢脫艩露脠艗脝脣茫
{
	double avg_nightwork = 0;
	double avg_nightwork1 = 0;
	for (int i = 0; i < nurse; i++)						//艗脝脣茫卤铆1脝艙鸥霉脪鹿掳脿脢媒
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

	for (int i = 0; i < nurse; i++)						//艗脝脣茫卤铆2脝艙鸥霉脪鹿掳脿脢媒
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

		for (int j = 2; j < 93; j = j + 3)				//脠谩脨脭脤玫艗镁拢拧脭艙艙脫艙眉脝艙鸥霉脪鹿掳脿脢媒脭艙潞脙拢漏
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

			if (nurse_table[i][j] == 1)					//卤脺脙芒脠媒脕卢掳脿
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

			if (nurse_table[i][j] == 0)					//卤脺脙芒脕卢脨酶脨脻脧垄5脤矛脪脭脡脧
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
			
			for (int k = 0; k < 29; k = k + 3)			//卤脺脙芒脕卢脨酶鹿鈧椕5脤矛脪脭脡脧
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

		if (nurse_table[num - 1][day + turn - 2] == 1)	//脦楼路沤脤脴脢芒脪陋脟贸禄鈧娐柯棵浡访
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
void selectPopulation()									//脩隆脭帽
{
	srand(time(0));
	point = rand() % 31 + 1;
}
void populationCrossover()								//艙禄虏忙
{
	int temp;
	for (int i = (point - 1) * 3; i <(point - 1) * 3 + 3; i++)					//艙禄虏忙
	{
		for (int j = 0; j < nurse; j++)
		{
			temp = nurse_table[j][i];
			nurse_table[j][i] = nurse_table1[j][i];
			nurse_table1[j][i] = temp;
		}
	}
}
void alterPopulation()									//卤盲脪矛
{
	srand(time(0));
	int alter;
	int alter_old;
	int alter_new;
	for (int i = 0; i < nurse; i++)						//露脭卤铆1艙酶脨脨卤盲脪矛
	{
		for (int j = 0; j < 93; j++)
		{
			alter = rand() % 100 + 1;
			if (alter == 1)
			{
				if (nurse_table[i][j] == 1)
				{
					nurse_table[i][j] = 0;
					if (j < old_nurse)					//脢鹿脙驴沤脦卤盲脪矛露艗卤拢脰鈧撀裁惷斆屆蹬捗韭得兟蹬撁偯好椕(脮忙->艗脵)
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
					if (j < old_nurse)				//脢鹿脙驴沤脦卤盲脪矛露艗卤拢脰鈧撀裁惷斆屆蹬捗韭得兟蹬撁偯好椕(艗脵->脮忙)
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
	for (int i = 0; i < nurse; i++)						//露脭卤铆2艙酶脨脨卤盲脪矛
	{
		for (int j = 0; j < 93; j++)
		{
			alter = rand() % 100 + 1;
			if (alter == 1)
			{
				if (nurse_table1[i][j] == 1)
				{
					nurse_table1[i][j] = 0;
					if (j < old_nurse)					//脢鹿脙驴沤脦卤盲脪矛露艗卤拢脰鈧撀裁惷斆屆蹬捗韭得兟蹬撁偯好椕(脮忙->艗脵)
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
					if (j < old_nurse)				//脢鹿脙驴沤脦卤盲脪矛露艗卤拢脰鈧撀裁惷斆屆蹬捗韭得兟蹬撁偯好椕(艗脵->脮忙)
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
void display()											//脢盲鲁枚脳卯脰脮碌脛脳卯脫脜脜脜掳脿卤铆
{
	int sum=0;
	int sum1=0;
	for (int i = 0; i < nurse; i++)
	{
		sum += total_fitness[i];
	}
	cout << "卤铆1脢脢脫艩露脠脳脺潞脥脦陋:" << sum << endl;

	for (int i = 0; i < nurse; i++)
	{
		sum1 += total_fitness1[i];
	}
	cout << "卤铆2脢脢脫艩露脠脳脺潞脥脦陋:" << sum1 << endl;
	if (sum>sum1)
	{
		cout << "脳卯脫脜脜脜掳脿卤铆脦陋卤铆1" << endl;
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
		cout << "脳卯脫脜脜脜掳脿卤铆脦陋卤铆2" << endl;
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
		cout << "脳卯脫脜脜脜掳脿卤铆脦陋卤铆1潞脥卤铆2" << endl;
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
	cout << "脟毛脢盲脠毛脌脧禄鈧娐棵娒矫伮:";
	cin >> old_nurse;
	cout << "脢脟路帽沤忙脭脷脫脨脤脴脢芒脪陋脟贸碌脛禄鈧娐,脢盲脠毛1脦陋yes,脝盲脣没脭貌脦陋路帽" << endl;
	cin >> answer;
	if(answer == 1)
	{
		cout << "脟毛脢盲脠毛脫脨脤脴脢芒脪陋脟贸碌脛禄鈧娐柯好,啪帽脢艙脦陋1,2....n" << endl;
		cin >> num;
		cout << "脟毛脢盲脠毛脫脨脤脴脢芒脪陋脟贸碌脛脠脮脝脷,啪帽脢艙脦陋1拢卢2....31" << endl;
		cin >> day;
		cout << "脟毛脢盲脠毛脫脨脤脴脢芒脪陋脟贸碌脛掳脿沤脦,1脦陋脭莽掳脿拢卢2脦陋脥铆掳脿拢卢3脦陋脪鹿掳脿" << endl;
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