#include "D:\B.C.K\Dropbox\H\ustd\ustd v4.5.9.h"

#define SHOW_TITLE gotoxy(100 - strlen("Copyrightⓒ 2016 Name10. All Rights Reserved."), 32 - 1); _D_SKY; cout << "Copyrightⓒ 2016 Name10. All Rights Reserved."; _GREEN; gotoxy(0, 0); cout << "War of Legends [v2.2.0 Release]" << endl << endl;


#define USER_INFO_REFRESH \
gotoxy(0, 2);\
_YELLOW;\
cout << "Lv." << level;\
_RED;\
cout << "  ARMY " << army;\
_GREEN;\
cout << "  COIN " << coin;\
_SKY;\
cout << "  DIAMOND " << diamond;\
_VIOLET;\
cout << "  EXP " << _exp << endl << endl;
//SKY; printf("[%s] Lv.%d ""ARMY %d ""COIN %d" "EXP %d\n\n", nickname, level, army, coin, _exp);


#define MENU \
_GREEN;\
gotoxy(0, 0);\
SHOW_TITLE;\
gotoxy(72 - nickname.size() - strlen("님, 환영합니다!") + strlen("자동 코인 생산 중...") + 1, 0);\
_GRAY;\
cout << "[" << nickname << "]님, 환영합니다!";\
USER_INFO_REFRESH;\
_D_GREEN;\
printf("<1> 공격 <2> 병사 고용 <3> 코인 생산 <4> 다이아몬드 채굴 <5> 스토어 <ESC> 종료\n\n");\
_GRAY;\
printf("Enter your choice : ");


#define XYSET_GOODBYE gotoxy(50 - strlen("G O O D   B Y E") / 2 - 1, 16);
#define XYSET_LEVELUP  gotoxy(50 - (strlen(level_tmp) + strlen("축하합니다! Lv.이 되셨습니다!")) / 2, 15);

void Attack();
void MakeArmy();
void MakeMoney();
void MakeDiamond();
void Store();

void delay_type(string s, double t);

int army = 3000;
int coin = 5000;
int diamond = 0;
int _exp = 0;
int level = 1;
char choice = NULL;
string nickname;

int atk = 1000;  // 공격력
int def = 1000;  // 방어력

void main()
{
	ConsoleSize(100, 32);
input_nickname:
	SHOW_TITLE;

	Cursor(true);
	gotoxy(0, 2);
	_GRAY;
	printf("닉네임 : ");
	_SKY;
	cin >> nickname;

	if (nickname.size() > 20)
	{
		gotoxy(8, 4);
		_RED;
		cout << "닉네임은 최대 20byte입니다.";
		Delay(1);

		cls();

		goto input_nickname;
	}

	if (nickname == "Admin")
	{
		gotoxy(0, 4);
		_SKY;
		cout << "환영합니다, 관리자님!";
		army = 3000000;
		coin = 5000000;
		diamond = 1000;
		_exp = 1000;
		level = 50;
		Delay(1.5);
	}

choosemode:

	cls();

	MENU;

	Cursor(false);
	gotoxy(75, 2);
	_D_SKY;
	cout << "자동 코인 생산 중...";

	buf_clear();

	Delay(0.3);

	gotoxy(75, 2);
	_SKY;
	cout << "자동 코인 생산 중...";

	gotoxy(20, 6);
	Cursor(true);

	// 자동 코인 생산
	clock_t start_time, end_time, auto_coin;
	start_time = clock();
	while (!kbhit());
	end_time = clock();
	auto_coin = end_time - start_time;
	coin += (auto_coin / 100) + ((auto_coin / 200) * (level / 5));  // 기본 1초당 10코인, 레벨 5 당 +5코인

	// 메뉴 입력
	_GREEN;
	choice = getche();

	putch('\n');
	putch('\n');

	Cursor(false);
	USER_INFO_REFRESH;

	gotoxy(75, 2);
	_SKY;
	cout << "자동 코인 생산 완료 ";
	Delay(0.4);

	gotoxy(75, 2);
	_SKY;
	for (int i = 1; i <= 5; i++)
	{
		putch('\t');  // Clear
	}

	Cursor(false);

	switch (choice)
	{
	case '1':
		Attack();
		break;
	case '2':
		MakeArmy();
		break;
	case '3':
		MakeMoney();
		break;
	case '4':
		MakeDiamond();
		break;
	case '5':
		Store();
		break;
	case ESC:
		gotoxy(strlen("Enter your choice : "), 6);
		_GREEN;
		cout << "ESC";
		Delay(0.7);

		gotoxy(50 - strlen("게임을 종료하시겠습니까? (Y/N)  ") / 2, 16 - 3);
		_SKY;
		cout << "게임을 종료하시겠습니까? (Y/N) ";
		_GREEN;
		choice = getche();
		Delay(0.5);
		switch (choice)
		{
		case 'Y':
		case 'y':
			XYSET_GOODBYE;
			_D_RED;
			cout << "G O O D   B Y E" << endl;
			Delay(1);
			
			XYSET_GOODBYE;
			_RED;
			cout << "G O O D   B Y E" << endl;
			Delay(1);

			XYSET_GOODBYE;
			_GREEN;
			cout << "G O O D   B Y E" << endl;
			Delay(1.5);

			_RESET;
			return;
		case 'N':
		case 'n':
			break;
		default:
			break;
		}
	default:
		break;
	}

	const int exp_max = (level / 5) * 100 + 1000;
	if (_exp >= exp_max)
	{
		level++;
		_exp %= exp_max;
		char level_tmp[5];
		sprintf(level_tmp, "%d", level); // itoa(level, level_tmp, 10);
		cls();
		SHOW_TITLE;
		XYSET_LEVELUP;
		_SKY;
		printf("\a축하합니다! \aLv.%d%s 되셨습니다!", level, (level % 10 == 1 || level % 10 == 3 || level % 10 == 6 || level % 10 == 7 || level % 10 == 8) ? "이" : "가");  // 조사(~이, ~가) 처리
		Delay(2);
	}
	if (coin < 0)
	{
		coin = 0;
	}
	if (army < 0)
	{
		army = 0;
	}
	goto choosemode;
}
void Attack()
{
	int fightarmy;
	int enemy;
	int enemy_level;

	if (level <= 2)
	{
		randomize();
		enemy_level = urand(100, 200) / 100;
	}
	else
	{
		int level_error = (level / 10 + 2);  // 나와 컴퓨터의 레벨 오차
		randomixe();
		enemy_level = urand((level - level_error) * 1000, (level + level_error) * 1000) / 1000;
	}

	int enemy_mid = (enemy_level / 5) * 1000 + 3000;
	int enemy_min = enemy_mid * 3 / 5;
	int enemy_max = enemy_mid * 7 / 5;

	randomixe();
	enemy = urand(enemy_min, enemy_max);

	int enemy_MAX = (enemy_level - 1) * 100 + 5000;
	if (enemy > enemy_MAX)
	{
		enemy = enemy_MAX;
	}

input_fightarmy:
	gotoxy(0, 8);
	for (int i = 1; i <= 20; i++)
	{
		putch('\t');  // Clear
	}

	Cursor(true);
	gotoxy(0, 8);
	_GRAY;
	printf("출전할 병력 : ");

	gotoxy(25, 8);
	_RED;
	cout << "0을 입력하면 메인 화면으로 돌아갑니다.";

	Delay(0.3);

	gotoxy(25, 8);
	_D_RED;
	cout << "0을 입력하면 메인 화면으로 돌아갑니다.";

	gotoxy(0, 8);
	_GRAY;
	printf("출전할 병력 : ");

	_GREEN;
	buf_clear();  // Buffer Clear
	scanf("%d", &fightarmy);

	gotoxy(25, 8);
	for (int i = 1; i <= 10; i++)
	{
		putch('\t');  // Clear
	}

	int fight_army_max = (level - 1) * 100 + 5000;
	if (fight_army_max > 10000)
	{
		fight_army_max = 10000;
	}
	if (army < fight_army_max)
	{
		fight_army_max = army;
	}

	if (fightarmy > army)
	{
		gotoxy(25, 8);
		_RED;
		cout << "출전 병력이 현재 병력보다 많습니다.";
		Delay(1);
		goto input_fightarmy;
	}
	if (fightarmy > fight_army_max)
	{
		gotoxy(25, 8);
		_RED;

		cout << "최대 출전 병력은 " << fight_army_max << "입니다.";
		Delay(1);
		goto input_fightarmy;
	}
	if (fightarmy == 0)
	{
		return;
	}
	if (fightarmy < 1)
	{
		gotoxy(25, 8);
		_RED;
		cout << "최소 출전 병력은 1입니다.";
		Delay(1);
		goto input_fightarmy;
	}


	Cursor(false);

	army -= fightarmy;

	const int first_fightarmy = fightarmy;
	const int first_enemy = enemy;

	_YELLOW;
	gotoxy(43, 14);
	printf("Lv.%2d  ", level);
	_VIOLET;
	printf("  Lv.%2d", enemy_level);

	_GOLD;
	gotoxy(48 - nickname.size(), 16);
	printf("%s ", nickname.c_str());
	gotoxy(49, 16);
	_SKY;
	printf("VS ");
	_GREEN;
	printf("Computer");

	gotoxy(43, 18);
	_SKY;
	printf("%5d  ", fightarmy);
	printf(" %5d", enemy);
	
	int enemy_atk = urand((atk * 7 / 8), (atk * 9 / 8));  // 적의 공격력 (내 공격력의 87.5% - 112.5%)
	int enemy_def = urand((def * 7 / 8), (def * 9 / 8));  // 적의 방어력 (내 방어력의 87.5% - 112.5%)

	gotoxy(50 - strlen("ATK 100.0") - 1, 20);
	_RED;
	printf("ATK %3.0lf%%    ", atk / static_cast<double>(10));
	_D_RED;
	printf("%3.0lf%%", enemy_atk / static_cast<double>(10));

	gotoxy(50 - strlen("DEF 100.0") - 1, 21);
	_GREEN;
	printf("DEF %3.0lf%%    ", def / static_cast<double>(10));
	_D_GREEN;
	printf("%3.0lf%%", enemy_def / static_cast<double>(10));

	Delay(0.7);

	double fightarmy_damage_mid = ( ((enemy_level - 1) * 10 + 100) * enemy_atk / 1000 ) * ( 1 / (def / static_cast<double>(1000)) );  // 내가 받는 데미지 (적이 가하는 데미지) 의 기준치
	int fightarmy_damage_min = static_cast<int>(fightarmy_damage_mid * 1 / 2);  // 내가 받는 데미지의 최소 (기준치의  50%)
	int fightarmy_damage_max = static_cast<int>(fightarmy_damage_mid * 3 / 2);  // 내가 받는 데미지의 최대 (기준치의 150%)

	double enemy_damage_mid = ( ((level - 1) * 10 + 100) * atk / 1000 ) * ( 1 / (enemy_def / static_cast<double>(1000)) );  // 적이 받는 데미지 (내가 가하는 데미지) 의 기준치
	int enemy_damage_min = static_cast<int>(enemy_damage_mid * 1 / 2);  // 적이 받는 데미지의 최소 (기준치의  50%)
	int enemy_damage_max = static_cast<int>(enemy_damage_mid * 3 / 2);  // 적이 받는 데미지의 최대 (기준치의 150%)

	int fightarmy_damage;
	int enemy_damage;

	do
	{
		Cursor(false);

		if (fightarmy < 500)
		{
			_RED;
		}
		else
		{
			_SKY;
		}

		gotoxy(43, 18);
		printf("%5d  ", fightarmy);

		if (enemy < 500)
		{
			_RED;
		}
		else
		{
			_SKY;
		}

		printf(" %5d", enemy);

		randomize();
		fightarmy_damage = urand(fightarmy_damage_min, fightarmy_damage_max) * (enemy / first_enemy);
		enemy_damage = urand(enemy_damage_min, enemy_damage_max) * (fightarmy / first_fightarmy);

		if (fightarmy < (fightarmy / 3))  // 병력이 최초 병력의 1/3 미만일 경우
		{
			enemy_damage = urand(enemy_damage_min, enemy_damage_max) / 3;  // 내가 가하는 데미지를 병력이 최초 병력의 1/3일 경우로 고정
		}
		if (enemy < (enemy / 3))  // 적의 병력이 적의 최초 병력의 1/3 미만일 경우
		{
			fightarmy_damage = urand(fightarmy_damage_min, fightarmy_damage_max) / 3;  // 적이 가하는 데미지를 적의 병력이 적의 최초 병력의 1/3일 경우로 고정
		}

		fightarmy -= fightarmy_damage;
		enemy -= enemy_damage;

		Delay(0.2);

	} while (fightarmy > 0 && enemy > 0);

	if (fightarmy < 0)
	{
		fightarmy = 0;
	}
	if (enemy < 0)
	{
		enemy = 0;
	}


	if (fightarmy < 500)
	{
		_RED;
	}
	else
	{
		_SKY;
	}

	gotoxy(43, 18);
	printf("%5d  ", fightarmy);

	if (enemy < 500)
	{
		_RED;
	}
	else
	{
		_SKY;
	}

	printf(" %5d", enemy);
	Delay(0.7);

	gotoxy(50 - (strlen("이겼습니다!") / 2), 12);
	if (fightarmy > enemy)
	{
		_GREEN;
	}
	else if (fightarmy < enemy)
	{
		_RED;
	}
	else
	{
		_SKY;
	}
	printf("%s", fightarmy > enemy ? "\a\a이겼습니다!" : (fightarmy < enemy ? "\a 졌습니다! " : "\a\a\a비겼습니다!"));
	Delay(1.5);
	_exp += first_fightarmy < 1750 ? 5 : (fightarmy > enemy ? 200 : (fightarmy < enemy ? 25 : 500));

	/* if(fightarmy > enemy)
	{
	_GREEN);
	gotoxy(35,13);
	printf("이겼습니다!");
	_exp += 200;
	} else if(fightarmy < enemy)
	{
	_RED);
	gotoxy(35,13);
	printf("졌습니다!");
	_exp += 50;
	} else
	{
	_SKY);
	gotoxy(35,13);
	printf("비겼습니다!");
	_exp += 100;
	}
	*/

}
void MakeArmy()
{
	Cursor(false);

	if (coin < 500)
	{
		gotoxy(0, 8);
		_RED;
		printf("\a\a돈이 부족합니다.");
		Delay(1);
		return;
	}

	gotoxy(30, 8);
	_RED;
	cout << "ESC를 입력하면 병사 고용을 취소합니다.";

	Delay(0.03);

	gotoxy(30, 8);
	_D_RED;
	cout << "ESC를 입력하면 병사 고용을 취소합니다.";

	register int delay_time = 300 - (level * 5);
	if (delay_time < 150)
	{
		delay_time = 150;
	}

	for (delay_time; delay_time > 0; delay_time--)
	{
		if (kbhit())
		{
			int tmp = getch();
			if (tmp == ESC)
			{
				return;
			}
		}

		_D_SKY;
		gotoxy(0, 8);
		printf("병사 고용 중...... ");
		_GREEN;
		printf("%.2f", delay_time / (double)100);
		Delay(0.01);
	}

	_D_SKY;
	gotoxy(0, 8);
	printf("병사 고용 완료");
	for (int i = 1; i <= 15; i++)
	{
		putch('\t');  // Clear
	}
	Delay(1.5);

	int army_mid = (level / 5) * 100 + 1000;
	int army_min = army_mid * 3 / 4;
	int army_max = army_mid * 5 / 4;
	
	randomize();
	army += urand(army_min, army_max);

	coin -= 1000;
	_exp += 50;

}
void MakeMoney()
{
	Cursor(false);

	int coin_mid = (level / 5) * 100 + 1000;
	int coin_min = coin_mid * 3 / 4;
	int coin_max = coin_mid * 5 / 4;

	gotoxy(30, 8);
	_RED;
	cout << "ESC를 입력하면 코인 생산을 취소합니다.";

	Delay(0.03);

	gotoxy(30, 8);
	_D_RED;
	cout << "ESC를 입력하면 코인 생산을 취소합니다.";

	register int delay_time = 300 - (level * 5);
	if (delay_time < 150)
	{
		delay_time = 150;
	}

	for (delay_time; delay_time > 0; delay_time--)
	{
		if (kbhit())
		{
			int tmp = getch();
			if (tmp == ESC)
			{
				return;
			}
		}

		_D_SKY;
		gotoxy(0, 8);
		printf("코인 생산 중...... ");
		_GREEN;
		printf("%.2f", delay_time / (double)100);
		Delay(0.01);
	}

	_D_SKY;
	gotoxy(0, 8);
	printf("코인 생산 완료");
	for (int i = 1; i <= 15; i++)
	{
		putch('\t');  // Clear
	}
	randomize();
	Delay(1.5);
	coin += urand(coin_min, coin_max);
	_exp += 50;

}
void MakeDiamond()
{
	Cursor(false);

	int diamond_max = (level / 5) + 1;
	int diamond_min = 1;
	int make_diamond_success_probability;  // 다이아몬드 채굴 성공 확률 (%)
	bool make_diamond_success = false;  // 다이아몬드 성공 여부

	if (coin < 1000)
	{
		gotoxy(0, 8);
		_RED;
		printf("\a\a돈이 부족합니다.");
		Delay(1);
		return;
	}

	gotoxy(30, 8);
	_RED;
	cout << "ESC를 입력하면 다이아몬드 채굴을 취소합니다.";

	Delay(0.03);

	gotoxy(30, 8);
	_D_RED;
	cout << "ESC를 입력하면 다이아몬드 채굴을 취소합니다.";

	register int delay_time = 300 - (level * 5);
	if (delay_time < 150)
	{
		delay_time = 150;
	}

	for (delay_time; delay_time > 0; delay_time--)
	{
		if (kbhit())
		{
			int tmp = getch();
			if (tmp == ESC)
			{
				return;
			}
		}

		_D_SKY;
		gotoxy(0, 8);
		printf("다이아몬드 채굴 중...... ");
		_GREEN;
		printf("%.2f", delay_time / (double)100);
		Delay(0.01);
	}

	make_diamond_success_probability = (level / 5) * 10;  // 다이아몬드 채굴 성공 확률 결정
	if (make_diamond_success_probability > 100)
	{
		make_diamond_success_probability = 100;
	}

	randomize();
	make_diamond_success = (urand(1, 100) <= make_diamond_success_probability);  // 다이아몬드 채굴 성공 여부 결정 (중요)

	if (make_diamond_success == true)  // 다이아몬드 채굴 성공
	{
		_SKY;
		gotoxy(0, 8);
		printf("다이아몬드 채굴 완료");
		for (int i = 1; i <= 15; i++)
		{
			putch('\t');  // Clear
		}
		Delay(1.5);
		randomize();
		diamond += urand(diamond_min, diamond_max);
		_exp += 75;
	}
	else  // 다이아몬드 채굴 실패
	{
		_D_RED;
		gotoxy(0, 8);
		printf("\a다이아몬드 채굴 실패!");
		for (int i = 1; i <= 15; i++)
		{
			putch('\t');  // Clear
		}
		Delay(1.5);
		_exp += 5;
	}

	coin -= 1000;

}
void Store()
{
	char tmp;
	bool first_visit = true;
	while (true)
	{
		Cursor(false);
		cls();
		Cursor(false);

		MENU;
		gotoxy(strlen("Enter your choice : "), 6);
		_GREEN;
		cout << "5";

		gotoxy(0, 8);
		_SKY;
		if (first_visit == true)
		{
			delay_type("------------------------------------------- STORE 스토어 -------------------------------------------", 0.015);
		}
		else
		{
			cout << "------------------------------------------- STORE 스토어 -------------------------------------------";
		}

		gotoxy(100 - strlen("ATK 100.0%  DEF 100.0%  DIAMOND 1000") - 5, 10);
		_RED;
		printf("ATK %3.1lf%%", atk / static_cast<double>(10));
		_GREEN;
		printf("  DEF %3.1lf%%", def / static_cast<double>(10));
		_SKY;
		printf("  DIAMOND %4d", diamond);

		gotoxy(0, 11);
		_GRAY;
		cout << endl << "Menu: " << endl;

		_RED;
		cout << "\t<1> 공격력 +1.5% : DIAMOND 3" << endl << endl;
		_GREEN;
		cout << "\t<2> 방어력 +1.5% : DIAMOND 3" << endl << endl;
		_VIOLET;
		cout << "\t<Q> 스토어 나가기" << endl << endl;

		Cursor(true);
		_GRAY;
		gotoxy(0, 19);
		cout << "Enter your choice : ";

		_YELLOW;
		char choice = getche();

		switch (choice)
		{
		case '1':
			gotoxy(0, 21);
			_D_SKY;
			cout << "구매하시겠습니까? (Y/N) ";
			_GREEN;
			tmp = getche();
			Delay(0.5);

			switch (tmp)
			{
			case 'Y':
			case 'y':
				if (diamond < 3)
				{
					gotoxy(0, 23);
					_RED;
					cout << "\a\a구매 실패! 다이아몬드가 부족합니다.";
					Delay(1);
					break;
				}

				diamond -= 3;
				atk += 15;

				gotoxy(0, 23);
				_D_SKY;
				cout << "구매 성공! 공격력이 1.5%p 상승했습니다.";
				Delay(0.2);

				gotoxy(0, 23);
				_SKY;
				cout << "구매 성공! 공격력이 1.5%p 상승했습니다.";
				Delay(1);

				break;
			case 'N':
			case 'n':
			default:
				break;
			}
			break;
		case '2':
			gotoxy(0, 21);
			_SKY;
			cout << "구매하시겠습니까? (Y/N) ";
			_GREEN;
			tmp = getche();
			Delay(0.5);

			switch (tmp)
			{
			case 'Y':
			case 'y':
				if (diamond < 3)
				{
					gotoxy(0, 23);
					_RED;
					cout << "\a\a구매 실패! 다이아몬드가 부족합니다.";
					Delay(1);
					break;
				}

				diamond -= 3;
				def += 15;

				gotoxy(0, 23);
				_D_SKY;
				cout << "구매 성공! 방어력이 1.5%p 상승했습니다.";
				Delay(0.2);

				gotoxy(0, 23);
				_SKY;
				cout << "구매 성공! 방어력이 1.5%p 상승했습니다.";
				Delay(1);
				break;
			case 'N':
			case 'n':
			default:
				break;
			}
			break;
		case 'Q':
		case 'q':
			Delay(0.5);
			return;
		default:
			continue;
		}

		first_visit = false;
	}

	Delay(1);
}

void delay_type(string s, double t)
{
	for (int i = 0; i < s.size(); i++)
	{
		printf("%c", s.at(i));
		Delay(t);
	}
}