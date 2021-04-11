#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include "colorwin.hpp"
using namespace std;
using namespace colorwin;
bool decision=true;
bool complexity = true;
int i_old;
int j_old;
int fillFiled(char arr[10][10]);//создание пустого поля
void coutFiled(char filed [10][10], char filed2[10][10]);//вывод поля игрока и поле противника
void coutFiled(char filed[10][10]);
void PvsP();//режим игрок против игрока
void PvE();//режим игрок против компьютера
int arrangement(char arr[10][10],char OParr[10][10], char arr2[10][10], char OParr2[10][10]);
int arrangement(char arr[10][10],char OParr[10][10], char arr2[10][10]);
int shot(char arr[10][10]);
void game(char PLarr[10][10], char OParr[10][10], char PLarr2[10][10], char OParr2[10][10]);
void game(char PLarr[10][10], char OParr[10][10], char comp[10][10]);
bool check_shot(char arr[10][10], int i, int j);
bool check_shot2(char arr[10][10], int i, int j);
int killed(char arr[10][10],int i , int j);
int killed2(char arr[10][10],int i , int j);

int four_decker(char arr[10][10]);//создание четырехпалубника
int four_decker_for_Rand(char arr[10][10]);
int three_decker(char arr[10][10]);
int three_decker_for_Rand(char arr[10][10]);
int double_decker(char arr[10][10]);
int double_decker_for_Rand(char arr[10][10]);
int single_decker(char arr[10][10]);
int single_decker_for_Rand(char arr[10][10]);
bool check(char arr[10][10], int i, int j);
bool winnerOrno(char arr[10][10]);
void next_move();
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "\t\tМОРСКОЙ БОЙ" << endl;
	int mode = 0;
	do {
		cout << "Выберете режим:\n0 - Player VS Player\n1 - Player VS Computer " << endl;
		
		cin >> mode;

		if (mode == 0) {
			PvsP();
		}
		else if (mode == 1) {
			PvE();
		}
	} while (mode > 1);
	//GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, 0);

	return 0;
}
bool check_shot(char arr[10][10], int i ,int j) {
	int a = 0;

if (i == 0) {
		if (arr[i + 1][j] == '$') {
			i_old = i + 1;
			j_old = j;
			return 1;
		}
		if (j == 0) {
			if (arr[i][j + 1] == '$') {
				i_old = i;
				j_old = j+1;
				return 1;
			}

		}
		if (j == 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i ;
				j_old = j-1;
				return 1;
			}
			else if (arr[i][j - 1] == 'X') {
				a = j - 1;
				return check_shot(arr, i, a);
			}
		}


		if (j > 0 && j < 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i ;
				j_old = j-1;				
				return 1;
			}
			else if (arr[i][j - 1] == 'X') {
				a = j - 1;
				return check_shot(arr, i, a);
			}
		}
	}
else if (i == 9) {
		if (arr[i - 1][j] == '$') {
			i_old = i - 1;
			j_old = j;
			return 1;			
		}
		if (j == 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j-1;
				return 1;
			}
			else if (arr[i][j - 1] == 'X') {
				a = j - 1;
				return check_shot(arr, i, a);
			}
		}
		else if (arr[i - 1][j] == 'X') {
			a = i - 1;
			return check_shot(arr, a, j);
		}
		if (j > 0 && j < 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j-1;
				return 1;
			}
			else if (arr[i][j - 1] == 'X') {
				a = j - 1;
				return check_shot(arr, i, a);
			}
		}
	}
else if (j == 0) {
		if (arr[i ][j + 1] == '$') {
			i_old = i ;
			j_old = j+1;
			return 1;
		} 
		if (i == 9) {
			if (arr[i - 1][j] == '$') {
				i_old = i - 1;
				j_old = j;
				return 1;
			}
			else if (arr[i - 1][j] == 'X') {
				a = i - 1;
				return check_shot(arr, a, j);
			}
		}
		if (i == 0) {
			if (arr[i+ 1][j] == '$') {
				i_old = i + 1;
				j_old = j;
				return 1;
			}
		}
		if (i > 0 && i < 9) {
			if (arr[i-1][j] == '$') {
				i_old = i - 1;
				j_old = j;
				return 1;
			}
			else if (arr[i-1][j] == 'X') {
				a = i - 1;
				return check_shot(arr, a, j);
			}
		}

	}
	else if (j == 9) {
		if (arr[i ][j - 1] == '$') {
			i_old = i;
			j_old = j-1;
			return 1;
		}
		if (i == 0) {
			if (arr[i + 1][j] == '$') {
				i_old = i + 1;
				j_old = j;
				return 1;
			}

		}
		else if (arr[i][j - 1] == 'X') {
			a = j - 1;
			return check_shot(arr, i, a);
		}
		if (i > 0 && i < 9) {
			if (arr[i - 1][j] == '$') {
				i_old = i - 1;
				j_old = j;
				return 1;
			}
			else if (arr[i - 1][j] == 'X') {
				a = i - 1;
				return check_shot(arr,  a,j);
			}
		}
	}
	else if (arr[i+1][j]== '$'|| arr[i - 1][j] == '$' || arr[i ][j - 1] == '$' || arr[i][j + 1] == '$') {		 
			if (arr[i + 1][j] == '$') {
				i_old = i + 1;
				j_old = j;
			}
			else if (arr[i - 1][j] == '$') {
				i_old = i - 1;
				j_old = j;
			}
			else if (arr[i][j + 1] == '$') {
				i_old = i;
				j_old = j + 1;
			}
			else if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j - 1;
			}
			return 1;		
	}

	else if (arr[i - 1][j] == 'X') {
		a = i - 1;
		return check_shot(arr, a, j);
	}

	else if (arr[i][j-1] == 'X') {
		a = j - 1;
		return check_shot(arr, i,a);
	}
	
	return 0;
}
bool check_shot2(char arr[10][10], int i, int j) {
	int a = 0;
	if (i == 0) {
		if (arr[i + 1][j] == '$') {
			i_old = i + 1;
			j_old = j;
			return 1;
		}
		if (j == 0) {
			if (arr[i][j + 1] == '$') {
				i_old = i ;
				j_old = j+1;
				return 1;
			}
			else if (arr[i][j + 1] == 'X') {
						a = j + 1;
						return check_shot2(arr, i, a);
						
					}
		}
		if (j == 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j-1;
				return 1;
			}

		}

		else if (arr[i + 1][j] == 'X') {
				a = i + 1;
				return check_shot2(arr, a, j);
			}
		if (j > 0 && j < 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j - 1;
				return 1;
			}
			if (arr[i ][j+1] == '$') {
				i_old = i;
				j_old = j + 1;
				return 1;
			}
			else if (arr[i][j +1] == 'X') {
				a = j + 1;
				return check_shot2(arr, i, a);
			}
		}
	}
	else if (i == 9) {
		if (arr[i - 1][j] == '$') {
			i_old = i-1;
			j_old = j ;
			return 1;
		}
		if (j == 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j - 1;
				return 1;
			}

		}
		if (j == 0) {
			if (arr[i][j + 1] == '$') {
				i_old = i;
				j_old = j + 1;
				return 1;
			}

		}

		if (j > 0 && j < 9) {
			if (arr[i][j - 1] == '$') {
				i_old = i;
				j_old = j - 1;
				return 1;
			}
			if (arr[i][j +1] == '$') {
				i_old = i;
				j_old = j + 1;
				return 1;
			}
			else if (arr[i][j+ 1] == 'X') {
				a = j+ 1;
				return check_shot2(arr, i, a);
			}
		}
	}
	else if (j == 0) {
		if (arr[i][j + 1] == '$') {
			i_old = i;
			j_old = j + 1;
			return 1;
		}
		if (i == 9) {
			if (arr[i - 1][j] == '$') {
				i_old = i;
				j_old = j + 1;
				return 1;
			}
			
		}
		if (i == 0) {
			if (arr[i + 1][j] == '$') {
				i_old = i+1;
				j_old = j ;
				return 1;
			}
			else if (arr[i + 1][j] == 'X') {
				a = i + 1;
				return check_shot2(arr, i, a);
			}
		}
		else if (arr[i][j + 1] == 'X') {
			a = j + 1;
			return check_shot2(arr, i, a);
		}
		if (i > 0 && i < 9) {
			if (arr[i - 1][j] == '$') {
				i_old = i-1;
				j_old = j;
				return 1;
			}
			if (arr[i + 1][j] == '$') {
				i_old = i+1;
				j_old = j;
				return 1;
			}
			else if (arr[i + 1][j] == 'X') {
				a = i + 1;
				return check_shot2(arr, a, j);
			}
		}

	}
	else if (j == 9) {
		if (arr[i][j - 1] == '$') {
			i_old = i;
			j_old = j - 1;
			return 1;
		}
		if (i == 0) {
			if (arr[i + 1][j] == '$') {
				i_old = i+1;
				j_old = j ;
				return 1;
			}
			else if (arr[i + 1][j] == 'X') {
				a = i + 1;
				return check_shot2(arr, a, i);
			}
		}

		if (i > 0 && i < 9) {
			if (arr[i - 1][j] == '$') {
				i_old = i-1;
				j_old = j;
				return 1;
			}
			if (arr[i + 1][j] == '$') {
				i_old = i+1;
				j_old = j;
				return 1;
			}
			else if (arr[i - 1][j] == 'X') {
				a = i - 1;
				return check_shot2(arr, a, j);
			}
		}
	}
	else if (arr[i + 1][j] == '$' || arr[i - 1][j] == '$' || arr[i][j - 1] == '$' || arr[i][j + 1] == '$') {
		if (arr[i + 1][j] == '$') {
			i_old = i + 1;
			j_old = j;
		}
		else if (arr[i - 1][j] == '$') {
			i_old = i - 1;
			j_old = j;
		}
		else if (arr[i][j + 1] == '$') {
			i_old = i;
			j_old = j+ 1;
		}
		else if (arr[i][j - 1] == '$') {
			i_old = i ;
			j_old = j-1;
		}
		return 1;
	}
	else if (arr[i + 1][j] == 'X') {
		a = i + 1;
		return check_shot2(arr, a, j);
	}
	else if (arr[i][j+1] == 'X') {
		a = j + 1;
		return check_shot2(arr, i,a);
	}
	return 0;
}

int fillFiled(char arr[10][10]) {
	int const size = 10;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = '-';
		}
	}
	return **arr;
}
void next_move() {
	string a;
	cout << "Для передачи хода нажмите ENTER" << endl;
	getline(cin, a);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nДля начала хода нажмите ENTER" << endl;
	getline(cin, a);
}
void coutFiled(char filed[10][10], char filed2[10][10]) {
	char x = 65;
	int const size = 10;
	cout << "\n      Ваше поле:" << "\t\t\t\t    " << "Поле противника:" << endl<<endl;
	cout << "  ";
	for (int i = 1; i <= size; i++) {
		cout << i << " ";
	}

	cout << "\t\t\t\t";
	cout << "  ";
	for (int i = 1; i <= size; i++) {
		cout << i << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << x << " ";
		for (int j = 0; j < size; j++) {
			if (filed[i][j] == 'X') {
				cout<< color(red) << filed[i][j] << " ";
			}
			else if (filed[i][j] == '$') {
				cout << color(green) << filed[i][j] << " ";
			}
			else
			cout << filed[i][j] << " ";
		}
		cout << "\t\t\t\t";
		cout << x << " ";
		for (int j = 0; j < size; j++) {
			if (filed2[i][j] == 'X') {
				cout << color(red) << filed2[i][j] << " ";
			}
			else if (filed2[i][j] == '$') {
				cout << color(green) << filed2[i][j] << " ";
			}
			else
			cout << filed2[i][j] << " ";
		}

		x++;
		cout << endl;
	}

}
void coutFiled(char arr[10][10]) {
	char x = 65;
	int const size = 10;
	cout << "  ";
	for (int i = 1; i <= size; i++) {
		cout << i << " ";
	}

 
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << x << " ";
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 'X') {
				cout << color(red) << arr[i][j] << " ";
			}
			else if (arr[i][j] == '$') {
				cout << color(green) << arr[i][j] << " ";
			}
			else
			cout << arr[i][j] << " ";
		}
		x++;
		cout << endl;
	}

}
int arrangement(char arr[10][10], char OParr[10][10], char arr2[10][10], char OParr2[10][10]){
	cout << "\tВведите координаты,для выстрела:" << endl;
	cout << color(dark_gray) << "\t\"exit\" - закончить игру:" << endl;
	cout << color(dark_gray) << "\t\"new\" начать новую игру" << endl;

	string move;
	
	getline(cin, move);
	if (move == "exit") {
		exit(0);
	}
	else if(move == "new") {
		main();
	}
	if (move.length() < 2) {
		arrangement(arr, OParr, arr2, OParr2);
		return **arr, ** OParr2;
	}
	int j = 0;
	int i = (char)move[0]-65;
if (move.length()>2) {
		 j = (char)move[1] - 49 + 9;
	}
	else
	 j =(char) move[1]-49;
if (arr[i][j] == '-') {
	arr[i][j] = '*';
	
	cout << "\tПРОМАХ!!!" << endl;
}
	else if (arr[i][j] == '*'|| arr[i][j] == 'X') {
		cout << "Вы уже стреляли сюда ,повторите." << endl;
		arrangement(arr,OParr,arr2,OParr2);
		return **arr, **OParr2;
	
	}
	else if(arr[i][j] == '$'){
		arr[i][j] = 'X';
		OParr2[i][j] = arr[i][j];
		bool win = true;
		cout << "\tПОПОДАНИЕ!!!" << endl;
		if (!check_shot(arr, i, j))	{
			if (!check_shot2(arr, i, j)) {
				printf("\t\x1B[31mУбит!!!\033[0m\n");
				killed(arr,  i, j);
				killed2(arr,  i, j);

			}
		}
		if (check_shot(arr, i, j) || check_shot2(arr, i, j)) {
			cout << color(yellow) << "\tРанение" << endl;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] == '*') {
					OParr2[i][j] = arr[i][j];
				}
			}
		}
		win = winnerOrno(arr);
		if (win == false) {
			return **arr, ** OParr2;
		}
		cout << "\tДополнительный ход" << endl;
		coutFiled(arr2, OParr2);
		arrangement(arr, OParr, arr2, OParr2);
		return **arr, **OParr2;

	}
	OParr2[i][j]= arr[i][j];
	
	return **arr, **OParr2;

}
int arrangement(char arr[10][10], char OParr2[10][10], char arr2[10][10]) {
	cout << color(dark_gray) << "\t\"exit\" закончить игру:" << endl;
	cout << color(dark_gray) << "\t\"new\" начать новую игру" << endl;

	cout << "\nВведите координаты,для выстрела:" << endl;
	string move;

	getline(cin, move);
	if (move == "exit") {
		exit(0);
	}
	else if (move == "new") {
		main();
	}
	if (move.length() < 2) {
		arrangement(arr,  OParr2,arr2 );
		return **arr, ** OParr2;
	}
	int j = 0;
	int i = (char)move[0] - 65;
	if (move.length() > 2) {
		j = (char)move[1] - 49 + 9;
	}
	else
		j = (char)move[1] - 49;
	if (arr[i][j] == '-') {
		arr[i][j] = '*';

		cout << "\tПРОМАХ!!!" << endl;
	}
	else if (arr[i][j] == '*' || arr[i][j] == 'X') {
		cout << "\tВы уже стреляли сюда ,повторите." << endl;
		arrangement(arr, OParr2, arr2);
		return **arr, ** OParr2;

	}
	else if (arr[i][j] == '$') {
		arr[i][j] = 'X';
		OParr2[i][j] = arr[i][j];
		bool win = true;
		cout << "\tПОПОДАНИЕ!!!" << endl;
		if (!check_shot(arr, i, j)) {
			if (!check_shot2(arr, i, j)) {
				printf("\t\x1B[31mУбит!!!\033[0m\n");
			
				killed(arr,  i, j);
				killed2(arr,  i, j);

			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] == '*') {
					OParr2[i][j] = arr[i][j];
				}
			}
		}
		if (check_shot(arr, i, j) || check_shot2(arr, i, j)) {
			cout << color(yellow) << "\tРанение" << endl;
		}
		win = winnerOrno(arr);
		if (win == false) {
			return **arr, ** OParr2;
		}
		cout << "\tДополнительный ход" << endl;
		coutFiled(arr2, OParr2);
		arrangement(arr, OParr2, arr2);
		return **arr, ** OParr2;

	}
	OParr2[i][j] = arr[i][j];

	return **arr, ** OParr2;

}

int four_decker_for_Rand(char arr[10][10]) {
	int i = rand() % 10;
	int j = rand() %10;
	int i2 = 0;
	int j2 = 0;
	int counter = 0;
	bool x = rand() % 2; //по горизонтали или вертикали 
	if (x == true) {
		if (j >= 5) {
			
			while (counter < 4) {
				arr[i][j - counter] = '$';
				counter++;
			}
		}
		else if (j <= 4) {
			
			while (counter < 4) {
				arr[i][j + counter] = '$';
				counter++;
			}
		}
	}
	else if (x == false) {
		if (i >= 5) {

			while (counter < 4) {
				arr[i - counter][j] = '$';
				counter++;
			}
		}
		else if (i <= 4) {

			while (counter < 4) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
	}



	return **arr;
}
int three_decker_for_Rand(char arr[10][10]) {
	int i = rand() % 8;
	int j = rand() % 8;
	int i2 = 0;
	int j2 = 0;
	bool a = true;
	bool x = rand() % 2;
	int counter = 0;
	a = check(arr, i, j);
	if (a == false) {
		three_decker_for_Rand(arr);
		return **arr;
	}	
	if (x == true) {
		i2 = i + 2;
		j2 = j;
	}
	else if (x == false) {
		j2 = j + 2;
		i2 = i;
	}
	a = check(arr, i2, j2);
	if (a == false) {

		three_decker_for_Rand(arr);
		return **arr;
	}
	if (i == i2 && i < 10 && i >= 0) {
		if (j2 > j && j2-j == 2&&j2<7) {
			while (counter < 3) {
				arr[i][j + counter] = '$';
				counter++;
			}

		}
		else {			
			three_decker_for_Rand(arr);
			return **arr;
		}
	}
	else if (j == j2 ) {		
		 if (i2 > i) {
			while (counter < 3) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
		else {
			
			three_decker_for_Rand(arr);
			return **arr;
		}
	}
	else {
	
		three_decker_for_Rand(arr);
		return **arr;
	}
	return **arr;
}
int double_decker_for_Rand(char arr[10][10]) {
	int i = rand() % 9;
	int j = rand() % 9;
	int i2 = 0;
	int j2 = 0;
	bool a = true;
	bool x = rand() % 2;
	int counter = 0;
	a = check(arr, i, j);
	if (a == false) {
		double_decker_for_Rand(arr);
		return **arr;
	}
	if (x == true) {
		i2 = i + 1;
		j2 = j;
	}
	else if (x == false) {
		j2 = j + 1;
		i2 = i;
	}
	a = check(arr, i2, j2);
	if (a == false) {

		double_decker_for_Rand(arr);
		return **arr;
	}
	if (i == i2 && i < 10 && i >= 0) {
		if (j2 > j) {
			while (counter < 2) {
				arr[i][j + counter] = '$';
				counter++;
			}
		}
		else {

			double_decker_for_Rand(arr);
			return **arr;
		}
	}
		
	
	else if (j == j2) {
		 if (i2 > i) {
			while (counter < 2) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
		else {

			double_decker_for_Rand(arr);
			return **arr;
		}
	}
	else {

		double_decker_for_Rand(arr);
		return **arr;
	}
	return **arr;
}
int single_decker_for_Rand(char arr[10][10]) {
	int i = rand() % 10;
	int j = rand() % 10;
	bool a = true;
	a = check(arr, i, j);
	if (a == false) {
		
		single_decker_for_Rand(arr);
		return **arr;
	}
	else {
		
		arr[i][j] = '$';
	}
	return **arr;
}


int four_decker(char arr[10][10]) {
	int  counter = 0;
	cout << "Введите начальную координату четырех палубного корабля:" << endl;
	string coordinates;
	
	getline(cin, coordinates);
	
	int j = 0;
	int i = (char)coordinates[0] - 65;
	if (coordinates.length() >2) {
		j = (char)coordinates[1] - 49 + 9;
	}
	else
		j = (char)coordinates[1] - 49;
	cout << "Введите конечную координату четырех палубного корабля:" << endl;
	string coordinatesEnd;
	
	getline(cin, coordinatesEnd);
	int j2 = 0;
	int i2 = (char)coordinatesEnd[0] - 65;
	if (coordinatesEnd.length() > 2) {
		j2 = (char)coordinatesEnd[1] - 49 + 9;
	}
	else
		j2 = (char)coordinatesEnd[1] - 49;

	
	if (i == i2 && i < 10 && i>=0) {
		if (j > j2&&j-j2==3) {
			while (counter < 4) {
				arr[i][j2 + counter] = '$';
				counter++;
			}

		}
		else if (j2 > j&&j2-j==3) {
			while (counter < 4) {
				arr[i][j + counter] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			four_decker(arr);
			return **arr;
		}
	}
	else if (j == j2 && j < 10 && j >= 0) {
		if (i > i2&&i-i2==3) {
			while (counter < 4) {
				arr[i2 + counter][j] = '$';
				counter++;
			}

		}
		else if (i2 > i&&i2-i==3) {
			while (counter < 4) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			four_decker(arr);
			return **arr;
		}
	}
	else {
		cout << "Неверная установка координат ,повторите" << endl;
		four_decker(arr);
		return **arr;
	}
	
	return **arr;
}
int three_decker(char arr[10][10]) {
	int  counter = 0;
	cout << "Введите начальную координату трех палубного корабля:" << endl;
	string coordinates;

	getline(cin, coordinates);

	int j = 0;
	int i = (char)coordinates[0] - 65;
	if (coordinates.length() > 2) {
		j = (char)coordinates[1] - 49 + 9;
	}
	else
		j = (char)coordinates[1] - 49;
	bool a = true;
		a= check(arr, i, j);
	if (a == false) {
		cout << "Координата слишком близка к соседниму кораблю ,повторите ввод:" << endl;
		three_decker(arr);
		return **arr;
	}
	cout << "Введите конечную координату трех палубного корабля:" << endl;
	string coordinatesEnd;

	getline(cin, coordinatesEnd);
	int j2 = 0;
	int i2 = (char)coordinatesEnd[0] - 65;
	if (coordinatesEnd.length() > 2) {
		j2 = (char)coordinatesEnd[1] - 49 + 9;
	}
	else
		j2 = (char)coordinatesEnd[1] - 49;
	a = check(arr, i2, j2);
	if (a == false) {
		cout << "Координата слишком близка к соседниму кораблю ,повторите ввод:" << endl;
		three_decker(arr);
		return **arr;
	}

	if (i == i2 && i < 10 && i >= 0) {
		if (j > j2 && j - j2 == 2) {
			while (counter < 3) {
				arr[i][j2 + counter] = '$';
				counter++;
			}

		}
		else if (j2 > j && j2 - j == 2) {
			while (counter < 3) {
				arr[i][j + counter] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			three_decker(arr);
			return **arr;
		}
	}
	else if (j == j2 && j < 10 && j >= 0) {
		if (i > i2 && i - i2 == 2) {
			while (counter < 3) {
				arr[i2 + counter][j] = '$';
				counter++;
			}

		}
		else if (i2 > i && i2 - i == 2) {
			while (counter < 3) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			three_decker(arr);
			return **arr;
		}
	}
	else {
		cout << "Неверная установка координат ,повторите" << endl;
		three_decker(arr);
		return **arr;
	}
	
	return **arr;
}
int double_decker(char arr[10][10]) {
	int  counter = 0;
	cout << "Введите начальную координату двух палубного корабля:" << endl;
	string coordinates;

	getline(cin, coordinates);

	int j = 0;
	int i = (char)coordinates[0] - 65;
	if (coordinates.length() > 2) {
		j = (char)coordinates[1] - 49 + 9;
	}
	else
		j = (char)coordinates[1] - 49;
	bool a = true;
	a = check(arr, i, j);
	if (a == false) {
		cout << "Координата слишком близка к соседниму кораблю ,повторите ввод." << endl;
		double_decker(arr);
		return **arr;
	}
	cout << "Введите конечную координату двух палубного корабля:" << endl;
	string coordinatesEnd;

	getline(cin, coordinatesEnd);
	int j2 = 0;
	int i2 = (char)coordinatesEnd[0] - 65;
	if (coordinatesEnd.length() > 2) {
		j2 = (char)coordinatesEnd[1] - 49 + 9;
	}
	else
		j2 = (char)coordinatesEnd[1] - 49;
	a = check(arr, i2, j2);
	if (a == false) {
		cout << "Координата слишком близка к соседниму кораблю ,повторите ввод." << endl;
		double_decker(arr);
		return **arr;
	}

	if (i == i2 && i < 10 && i >= 0) {
		if (j > j2 && j - j2 == 1) {
			while (counter < 2) {
				arr[i][j2 + counter] = '$';
				counter++;
			}

		}
		else if (j2 > j && j2 - j == 1) {
			while (counter < 2) {
				arr[i][j + counter] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			double_decker(arr);
			return **arr;
		}
	}
	else if (j == j2 && j < 10 && j >= 0) {
		if (i > i2 && i - i2 == 1) {
			while (counter < 2) {
				arr[i2 + counter][j] = '$';
				counter++;
			}

		}
		else if (i2 > i && i2 - i == 1) {
			while (counter < 2) {
				arr[i + counter][j] = '$';
				counter++;
			}
		}
		else {
			cout << "Неверная установка координат ,повторите" << endl;
			double_decker(arr);
			return **arr;
		}
	}
	else {
		cout << "Неверная установка координат ,повторите" << endl;
		double_decker(arr);
		return **arr;
	}

	return **arr;
}
int single_decker(char arr[10][10]) {
	int  counter = 0;
	cout << "Введите  координату однопалубного корабля:" << endl;
	string coordinates;

	getline(cin, coordinates);

	int j = 0;
	int i = (char)coordinates[0] - 65;
	if (coordinates.length() > 2) {
		j = (char)coordinates[1] - 49 + 9;
	}
	else
		j = (char)coordinates[1] - 49;
	bool a = true;
	a = check(arr, i, j);
	if (a == false) {
		cout << "Координата слишком близка к соседниму кораблю ,повторите ввод." << endl;
		single_decker(arr);
		return **arr;
	}
	if (i >= 0 && i < 10 && j >= 0 && j < 10) {
		arr[i][j] = '$';
	}
	else {
		cout << "Неверная установка координаты ,повторите" << endl;
		single_decker(arr);
		return **arr;
	}
	
	return **arr;
}

bool check(char arr[10][10], int i, int j) {
	if (i > 0&&j>0&&i<9&&j<9) {
		if (arr[i - 1][j - 1] == '$' || arr[i - 1][j] == '$' || arr[i - 1][j + 1] == '$'
			|| arr[i][j - 1] == '$' || arr[i][j + 1] == '$' || arr[i][j] == '$'
			|| arr[i + 1][j + 1] == '$' || arr[i + 1][j] == '$' || arr[i + 1][j - 1]=='$') {
			return 0;
		}

	}
	else if (i == 0 && j == 0) {
		if (arr[i][j + 1] == '$' || arr[i][j] == '$'
			|| arr[i + 1][j + 1] == '$' || arr[i + 1][j] == '$') {
			return 0;
		}
	}
	else if (i > 0 && j == 0&&i<9) {
		if (arr[i - 1][j] == '$' || arr[i - 1][j + 1] == '$'
			|| arr[i][j + 1] == '$' || arr[i][j] == '$'
			|| arr[i + 1][j + 1] == '$' || arr[i + 1][j] == '$') {
			return 0;
		}
		}
	else if (i == 0 && j > 0 && j < 9) {
		if( 
			 arr[i][j - 1] == '$' || arr[i][j + 1] == '$' || arr[i][j] == '$'
			|| arr[i + 1][j + 1] == '$' || arr[i + 1][j] == '$' || arr[i + 1][j - 1]=='$') {
			return 0;
	}
	}
	else if (i == 9 && j == 9) {
		if (arr[i - 1][j - 1] == '$' || arr[i - 1][j] == '$'
			|| arr[i][j - 1] == '$' || arr[i][j] == '$'
			) {
			return 0;
		}
	}
	else if (i == 9 && j < 9 && j>0) {
		if (arr[i - 1][j - 1] == '$' || arr[i - 1][j] == '$' || arr[i - 1][j + 1] == '$'
			|| arr[i][j - 1] == '$' || arr[i][j + 1] == '$' || arr[i][j] == '$'
			) {
			return 0;
		}
	}
	else if (i < 9 && i>0 && j == 9) {
		if (arr[i - 1][j - 1] == '$' || arr[i - 1][j] == '$'
			|| arr[i][j - 1] == '$' || arr[i][j] == '$'
			|| arr[i + 1][j - 1] =='$'|| arr[i + 1][j]=='$') {
			return 0;
		}
	}
	else if (i == 9 && j == 0) {
		if (  arr[i - 1][j] == '$' || arr[i - 1][j + 1] == '$'
			 || arr[i][j + 1] == '$' || arr[i][j] == '$'
			 ) {
			return 0;
		}
	}
	else if (i == 0 && j == 9) {
		if ( arr[i][j - 1] == '$' ||  arr[i][j] == '$'
			 || arr[i + 1][j] == '$' || arr[i + 1][j - 1]=='$') {
			return 0;
		}
	}
	return true;
}
int killed(char arr[10][10], int i, int j) {
	int a = 0;
	if (i == 0 || i == 9 || j == 0 || j == 9) {
		if (i == 0) {
			if (j >= 0 && j < 9) {
				if (arr[i][j + 1] == '-') {
					arr[i][j + 1] = '*';
				}
				if (arr[i + 1][j] == '-') {
					arr[i + 1][j] = '*';
				}
				if (arr[i + 1][j + 1] == '-') {
					arr[i + 1][j + 1] = '*';
				}
				if (arr[i][j + 1] == 'X') {
					j++;
					killed(arr,  i, j);
					return 0;
				}
				if (arr[i + 1][j] == 'X') {
					i++;
					killed(arr,  i, j);
					return 0;
				}

			}
			if (j == 9) {

				if (arr[i + 1][j] == '-') {
					arr[i + 1][j] = '*';
				}

				if (arr[i + 1][j] == 'X') {
					i++;
					killed(arr,  i, j);
					return 0;
				}

			}
			
		}
		if (i == 9) {
			if (j >= 0 && j < 9) {
				if (arr[i][j + 1] == '-') {
					arr[i][j + 1] = '*';
				}
				if (arr[i - 1][j + 1] == '-') {
					arr[i - 1][j + 1] = '*';
				}
				if (arr[i][j + 1] == 'X') {
					j++;
					killed(arr,  i, j);
					return 0;
				}
			}

			

		}
		if (j == 0) {
			if (i >= 0 && i < 9) {
				if (arr[i][j + 1] == '-') {
					arr[i][j + 1] = '*';
				}
				if (arr[i + 1][j] == '-') {
					arr[i + 1][j] = '*';
				}
				if (arr[i + 1][j + 1] == '-') {
					arr[i + 1][j + 1] = '*';
				}
				if (arr[i + 1][j] == 'X') {
					i++;
					killed(arr, i, j);
					return 0;
				}
				if (arr[i][j + 1] == 'X') {
					j++;
					killed(arr,  i, j);
					return 0;
				}

			}
			if (i == 9) {
				if (arr[i][j + 1] == '-') {
					arr[i][j + 1] = '*';
				}
				if (arr[i][j + 1] == 'X') {
					j++;
					killed(arr,  i, j);
					return 0;
				}
			}

		}
		if (j == 9) {
			if (i >= 0 && i < 9) {
				if (arr[i + 1][j] == '-') {
					arr[i + 1][j] = '*';
				}

				if (arr[i + 1][j] == 'X') {
					i++;
					killed(arr,  i, j);
					return 0;
				}
			}
			if (i >= 0 && i < 9) {
				if (arr[i + 1][j - 1] == '-') {
					arr[i + 1][j - 1] = '*';
				}
			}
		}
	}
	else
	{

		if (arr[i][j + 1] == '-') {
			arr[i][j + 1] = '*';
		}
		if (arr[i + 1][j] == '-') {
			arr[i + 1][j] = '*';
		}
		if (arr[i + 1][j + 1] == '-') {
			arr[i + 1][j + 1] = '*';
		}
		if (arr[i - 1][j + 1] == '-') {
			arr[i - 1][j + 1] = '*';
		}
		if (arr[i + 1][j - 1] == '-') {
			arr[i + 1][j - 1] = '*';
		}

		if (arr[i][j + 1] == 'X') {
			j++;
			killed(arr,  i, j);
			return 0;
		}
		if (arr[i + 1][j] == 'X') {
			i++;
			killed(arr,  i, j);
			return 0;

		}
	}
	return **arr;
}
int killed2(char arr[10][10],  int i, int j) {
	int a = 0;
	if (i == 0 || i == 9 || j == 0 || j == 9) {
		if (i == 0) {
			if (j > 0 && j <= 9) {
				if (arr[i][j - 1] == '-') {
					arr[i][j - 1] = '*';
				}

				if (arr[i + 1][j - 1] == '-') {
					arr[i + 1][j - 1] = '*';
				}
				if (arr[i][j - 1] == 'X') {
					j--;
					killed2(arr,  i, j);
					return 0;
				}


			}


		}
		if (i == 9) {
			if (j > 0 && j <= 9) {
				if (arr[i - 1][j] == '-') {
					arr[i - 1][j] = '*';
				}
				if (arr[i - 1][j - 1] == '-') {
					arr[i - 1][j - 1] = '*';
				}
				if (arr[i][j - 1] == '-') {
					arr[i][j - 1] = '*';
				}
				if (arr[i - 1][j] == 'X') {
					i--;
					killed2(arr,  i, j);
					return 0;
				}
				if (arr[i][j - 1] == 'X') {
					j--;
					killed2(arr, i, j);
					return 0;
				}
			}
			if (j == 0) {
				if (arr[i - 1][j] == '-') {
					arr[i - 1][j] = '*';
				}
				if (arr[i - 1][j] == 'X') {
					i--;
					killed2(arr,  i, j);
					return 0;
				}
			}

		}
		if (j == 0) {
			if (i > 0 && i <= 9) {
				if (arr[i - 1][j] == '-') {
					arr[i - 1][j] = '*';
				}

				if (arr[i - 1][j + 1] == '-') {
					arr[i - 1][j + 1] = '*';
				}

				if (arr[i - 1][j] == 'X') {
					i--;
					killed2(arr,  i, j);
					return 0;
				}

			}
		}
		if (j == 9) {
			if (i > 0 && i <= 9) {
				if (arr[i - 1][j] == '-') {
					arr[i - 1][j] = '*';
				}
				if (arr[i - 1][j - 1] == '-') {
					arr[i - 1][j - 1] = '*';
				}
				if (arr[i][j - 1] == '-') {
					arr[i][j - 1] = '*';
				}
				if (arr[i][j - 1] == '-') {
					arr[i][j - 1] = '*';
				}
				if (arr[i - 1][j] == 'X') {
					i--;
					killed2(arr,  i, j);
					return 0;
				}

				if (arr[i][j - 1] == 'X') {
					j--;
					killed2(arr,  i, j);
					return 0;
				}
			}
			if (i >= 0 && i < 9) {
				if (arr[i+1][j - 1] == '-') {
					arr[i+1][j - 1] = '*';
				}
			}
			if (i == 0) {


				if (arr[i][j - 1] == '-') {
					arr[i][j - 1] = '*';
				}
				if (arr[i][j - 1] == 'X') {
					j--;
					killed2(arr,  i, j);
					return 0;
				}

			}
		}
	}
	else {
		if (arr[i][j - 1] == '-') {
			arr[i][j - 1] = '*';
		}
		if (arr[i - 1][j] == '-') {
			arr[i - 1][j] = '*';
		}
		if (arr[i - 1][j - 1] == '-') {
			arr[i - 1][j - 1] = '*';
		}
		if (arr[i - 1][j + 1] == '-') {
			arr[i - 1][j + 1] = '*';
		}
		if (arr[i + 1][j - 1] == '-') {
			arr[i + 1][j - 1] = '*';
		}

		if (arr[i][j - 1] == 'X') {
			j--;
			killed2(arr, i, j);
			return 0;
		}
		if (arr[i - 1][j] == 'X') {
			i--;
			killed2(arr,  i, j);
			return 0;
		}
	}
	return **arr;
}
bool winnerOrno(char arr[10][10]) {
	int counter = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 'X') {
				counter++;
			}
		}
	}
	if (counter == 20) {
		return false;

		
	}
	return true;
}

void PvsP() {
	int const size = 10;
	char player1Filed[size][size];
	char player2Filed[size][size];
	char opponent1Filed[size][size];
	char opponent2Filed[size][size];
	int counter = 0;
	string a;
	fillFiled(player1Filed);
	fillFiled(player2Filed);
	fillFiled(opponent1Filed);
	fillFiled(opponent2Filed);
cout << "Расстановка кораблей " << endl;
		cout << "Player1:" << endl;
		coutFiled(player1Filed);
		cout << "Как расстановить корабли:\n0 - вручную\n1 - случайным образом" << endl;
		int b = 0;
		cin >> b;
		cin.ignore();
		if (b == 1) {
			four_decker_for_Rand(player1Filed);
			three_decker_for_Rand(player1Filed);
			three_decker_for_Rand(player1Filed);
			
			while (counter < 3) {
				double_decker_for_Rand(player1Filed);
				
				counter++;
			}
			counter = 0;
			
			while (counter < 4) {
				single_decker_for_Rand(player1Filed);
				counter++;
			}
			coutFiled(player1Filed);
			counter = 0;


		}
		else if (b == 0) {



			four_decker(player1Filed);
			coutFiled(player1Filed);
			three_decker(player1Filed);
			coutFiled(player1Filed);
			three_decker(player1Filed);
			coutFiled(player1Filed);
			while (counter < 3) {
				double_decker(player1Filed);
				coutFiled(player1Filed);
				counter++;
			}
			counter = 0;
			while (counter < 4) {
				single_decker(player1Filed);
				coutFiled(player1Filed);
				counter++;
			}
			
		}
		else {
			PvsP();
		}
		cout << "Нажимите ENTER для передачи расстановки второму игрока";

		getline(cin, a);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		cout << "Player 2 Нажимите ENTER для расстановки ";

		getline(cin, a);
	
		coutFiled(player2Filed);
		cout << "Как расстановить корабли:\n0 - вручную\n1 - случайным образом" << endl;
		b = 0;
		cin >> b;
		cin.ignore();
		if (b == 1) {
			four_decker_for_Rand(player2Filed);
			three_decker_for_Rand(player2Filed);
			three_decker_for_Rand(player2Filed);

			while (counter < 3) {
				double_decker_for_Rand(player2Filed);

				counter++;
			}
			counter = 0;
			
			while (counter < 4) {
				single_decker_for_Rand(player2Filed);
				counter++;
			}
			coutFiled(player2Filed);
			game(player1Filed, opponent1Filed, player2Filed, opponent2Filed);
		}
		else if (b == 0) {

			four_decker(player2Filed);
			coutFiled(player2Filed);
			three_decker(player2Filed);
			coutFiled(player2Filed);
			three_decker(player2Filed);
			coutFiled(player2Filed);
			counter = 0;
			while (counter < 3) {
				double_decker(player2Filed);
				coutFiled(player2Filed);
				counter++;
			}
			counter = 0;
			while (counter < 4) {
				single_decker(player2Filed);
				coutFiled(player2Filed);
				counter++;
			}
			game(player1Filed, opponent1Filed, player2Filed, opponent2Filed);
		}
		else (PvsP());
		
}
void PvE() {
	cout << "Выберите сложность:\n0 - легко\n1 - тяжело" << endl;
	cin >> complexity;

	int const size = 10;
	char player1Filed[size][size];
	char compFiled[size][size];
	char opponent1Filed[size][size];
	
	//
	int counter = 0;

	string a;

	fillFiled(player1Filed);
	fillFiled(compFiled);
	fillFiled(opponent1Filed);
	
	cout << "Расстановка кораблей " << endl;
	cout << "Player:" << endl;
	coutFiled(player1Filed);
	cout << "Как расстановить корабли:\n0 - вручную\n1 - случайным образом" << endl;
	int b = 0;
	cin >> b;
	cin.ignore();
	if (b == 1) {
		four_decker_for_Rand(player1Filed);
		three_decker_for_Rand(player1Filed);
		three_decker_for_Rand(player1Filed);

		while (counter < 3) {
			double_decker_for_Rand(player1Filed);

			counter++;
		}
		counter = 0;

		while (counter < 4) {
			single_decker_for_Rand(player1Filed);
			counter++;
		}
		coutFiled(player1Filed);
		counter = 0;


	}
	else if (b == 0) {



		four_decker(player1Filed);
		coutFiled(player1Filed);
		three_decker(player1Filed);
		coutFiled(player1Filed);
		three_decker(player1Filed);
		coutFiled(player1Filed);
		while (counter < 3) {
			double_decker(player1Filed);
			coutFiled(player1Filed);
			counter++;
		}
		counter = 0;
		while (counter < 4) {
			single_decker(player1Filed);
			coutFiled(player1Filed);
			counter++;
		}

	}
	else {
		PvE();
	}
	four_decker_for_Rand(compFiled);
	three_decker_for_Rand(compFiled);
	three_decker_for_Rand(compFiled);

	while (counter < 3) {
		double_decker_for_Rand(compFiled);

		counter++;
	}
	counter = 0;

	while (counter < 4) {
		single_decker_for_Rand(compFiled);
		counter++;
	}
	
	game(player1Filed,opponent1Filed,compFiled );
}
void game(char PLarr[10][10], char OParr[10][10], char PLarr2[10][10], char OParr2[10][10]) {
	string s;



	bool win = true;
	cout << "Для начала игры нажните Enter" << endl;
	getline(cin, s);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer1 для начала хода нажмите ENTER" << endl;
	getline(cin, s);
	while (win) {
		cout << "Player1:" << endl;
		coutFiled(PLarr, OParr);
		arrangement(PLarr2,OParr2,PLarr,OParr);
		coutFiled(PLarr, OParr);
		
		win=winnerOrno(PLarr2);
		if (win == false) {
			cout << "ПОБЕДА Первого игрока!!!" << endl;
			cout << "Начать знаново ?\n0 - нет\n1 - да" << endl;
			int a = 0;
			cin >> a;
			if (a == 1) {
				main();
			}
		}
		next_move();
		cout << "Player2:" << endl;
		coutFiled(PLarr2, OParr2);
		arrangement(PLarr,OParr,PLarr2,OParr2);
		coutFiled(PLarr2, OParr2);
		win = winnerOrno(PLarr);
		if (win == false) {
			cout << "ПОБЕДА Второго игрока игрока!!!" << endl;
			cout << "Начать заново ?\n0 - нет\n1 - да" << endl;
			int a = 0;
			cin >> a;
			if (a == 1) {
				main();
			}
		}
		next_move();

	}
}
int shot(char arr[10][10]) {
	int i =0;
	int j = 0;
	if (decision||!complexity) {
		i = rand() % 10;
		j = rand() % 10;
	}
	else
	{
		i = i_old;
		j = j_old;
	}
	if (arr[i][j] == '-') {
		cout << "Выстрел компьютера" << endl;
		Sleep(2000);
		cout << char(i+65) <<j+1<< endl;
		arr[i][j] = '*';
		coutFiled(arr);
		cout << "Промах!!!" << endl;
		Sleep(2000);
		decision = true;
		
		
	}
	else if (arr[i][j] == '*'|| arr[i][j] == 'X') {
		decision = true;
		shot(arr);
		return 0;
	}
	else if (arr[i][j] == '$') {
		cout << "Выстрел компьютера" << endl;
		Sleep(2000);
		cout << "Попадание!!!" << endl;
		cout << char(i + 65) << j + 1 << endl;
		arr[i][j] = 'X';
		if (!check_shot(arr, i, j)) {
			if (!check_shot2(arr, i, j)) {
				printf("\x1B[31mУбит!!!\033[0m\n");
					killed(arr, i, j);
					killed2(arr, i, j);
					decision = true;
			}
		}
		else  {
			decision = false;
		}
		coutFiled(arr);
		
		Sleep(2000);
		cout << "Дополнительный ход" << endl;	
		shot(arr);
		
		return 0;
	}
	return 0;
}

void game(char PLarr[10][10], char OParr[10][10], char comp[10][10]) {
	string s;
	bool win = true;
	cout << "Для начала игры нажните Enter" << endl;
	getline(cin, s);
	
	while (win) {
		cout << "Player:" << endl;
		coutFiled(PLarr, OParr);
		arrangement(comp, OParr, PLarr);


		win = winnerOrno(comp);
		if (win == false) {
			cout << "ПОБЕДА  игрока!!!" << endl;
			cout << "Начать знаново ?\n0 - нет\n1 - да" << endl;
			int a = 0;
			cin >> a;
			if (a == 1) {
				main();
			}
		}
		decision = false;
		shot(PLarr);
		win = winnerOrno(PLarr);
		if (win == false) {
			cout << "ПОБЕДА компьютера игрока игрока!!!" << endl;
			cout << "Начать заново ?\n0 - нет\n1 - да" << endl;
			int a = 0;
			cin >> a;
			if (a == 1) {
				main();
			}
		}
	}
}
