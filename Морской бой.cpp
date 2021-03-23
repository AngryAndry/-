#include <iostream>
#include <ctime>
#include <string>
using namespace std;
enum Letters {
	A = 1,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J

};
int fillFiled(char** filed);//создание пустого поля
void coutFiled(char** filed, char** filed2);//вывод поля

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "\t\tМОРСКОЙ БОЙ" << endl;
	int const size = 10;
	char** filed = new char* [size];
	for (int i = 0; i < size; i++) {
		filed[i] = new char[size];
	}
	char** filed2 = new char* [size];
	for (int i = 0; i < size; i++) {
		filed2[i] = new char[size];
	}

	fillFiled(filed);
	fillFiled(filed2);
	coutFiled(filed, filed2);
	string move;
	getline(cin, move);
	if (move[0] == 'A' && move[1] == 1 + 48) {
		filed[0][0] = '-';
	}
	coutFiled(filed, filed2);
	for (int i = 0; i < size; i++)
		delete[]filed[i];
	delete[]filed;
	for (int i = 0; i < size; i++)
		delete[]filed2[i];
	delete[]filed2;
}

int fillFiled(char** filed) {
	int const size = 10;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			filed[i][j] = '*';
		}
	}
	return **filed;
}
void coutFiled(char** filed, char** filed2) {
	char x = 65;
	int const size = 10;
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

			cout << filed[i][j] << " ";
		}
		cout << "\t\t\t\t";
		cout << x << " ";
		for (int j = 0; j < size; j++) {
			cout << filed2[i][j] << " ";
		}

		x++;
		cout << endl;
	}

}