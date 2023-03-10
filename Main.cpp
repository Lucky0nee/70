#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
	explicit Student() {
		this->name = Names[rand() % 4] + " " + LastNames[rand() % 4];
		this->averageScore = (rand() % 12 + 1) - (rand() % 100) / static_cast<float>(100);
	}

	void printInfo() {
		cout << "Name: " << this->name << "\n";
		cout << "AverageScore: " << this->averageScore << "\n";
	}

	float getAverageScore(){
		return this->averageScore;
	}

	string getName() {
		return this->name;
	}
protected:
	string name;
	string address;

	float averageScore;
	vector<string> Names{ "Sasha", "Ivan", "Anya", "Danya" };
	vector<string> LastNames{ "Barash", "Tarkhanov", "Kobelev", "Saburov" };
};

int findStudent(int FirstIndex, int LastIndex, std::vector<Student> vec) {
	int highScore = 1, id = 0;

	for (int i = FirstIndex; i < LastIndex; i++) {
		vec[i].printInfo();
		std::cout << "\n";
	}

	for (int i = 0; i < LastIndex; i++) {
		if (vec[i].getAverageScore() > highScore) {
			highScore = vec[i].getAverageScore();
			id = i;
		}
	}

	return id;
}

int main() {
	srand(time(NULL));
	std::vector <Student> vec(3);
	int FirstIndex = 0, LastIndex = vec.size();

	auto lambda = [](int FirstIndex, int LastIndex, std::vector <Student> vec) -> int {
		float highScore = 1, id = 0;

		for (int i = FirstIndex; i < LastIndex; i++) {
			vec[i].printInfo();
			std::cout << "\n";
		}

		for (int i = 0; i < LastIndex; i++) {
			if (vec[i].getAverageScore() > highScore) {
				highScore = vec[i].getAverageScore();
				id = i;
			}
		}
		return id;
	};

	std::cout << "Iм’я знайденого студента: " << vec[lambda(FirstIndex, LastIndex, vec)].getName();

	return 0;
}

/*
Створіть клас Студенти, який зберігатиме ім’я, прізвище і середній бал студента. Створіть масив (вектор) студентів і функцію для
пошуку студента з найбільшим балом.
В головній функції виведіть на екран ім’я знайденого студента.
*/
