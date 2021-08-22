#include <iostream>
#include <fstream>

using namespace std;

//Assume picture dimension is 10 letters X 25 letters
void printArray(char c[10][25]) {
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 25; b++) {
			cout << c[a][b];
		}
		cout << "\n";
	}
}

void changeColor(char c[10][25], char oldChar, char newChar, int x, int y) {
	if (x < 0 || x>24 || y < 0 || y>9) {
		return;
	}
	if (c[y][x] != oldChar) {
		return;
	}

	c[y][x] = newChar;

	changeColor(c, oldChar, newChar, x, y - 1);
	changeColor(c, oldChar, newChar, x + 1, y);
	changeColor(c, oldChar, newChar, x, y + 1);
	changeColor(c, oldChar, newChar, x - 1, y);
}

int main() {
	char array[10][25];

	ifstream input("C:\\Users\\fyxy\\Desktop\\input.txt");

	if (input.is_open()) {
		while (!input.eof()) {
			for (int a = 0; a < 10; a++) {
				for (int b = 0; b < 25; b++) {
					input.get(array[a][b]);
				}
				input.get();
			}
		}
	}
	else {
		cout << "Image Not opened!";
		cin.get();
		return 0;
	}

	cout << "Starting image\n";
	cout << "------------------------\n\n";
	printArray(array);


	int x, y;
	cout << "X coordinate of the initial pixel: ";
	cin >> x;
	cout << "Y coordinate of the initial pixel: ";
	cin >> y;

	changeColor(array, array[x][y], '-', x, y);

	cout << "After applying flood fill algorithm\n";
	cout << "------------------------\n\n";
	printArray(array);
	return 0;
}