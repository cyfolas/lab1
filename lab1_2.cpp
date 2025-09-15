#include <iostream>
#include <Windows.h>
using namespace std;
enum MilitaryStatus {
    nonliable,
    liable,
};

struct Person {

	string surname;
	int age;
	MilitaryStatus ms;

};

int main()
{
	setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int SIZE = 3;
    Person people[SIZE];

    cout << "Заполнение массива структур:" << endl;
    cout << "============================" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "\nЧеловек #" << i + 1 << ":" << endl;

        
        cout << "Введите фамилию: ";
        cin >> people[i].surname;

        
        cout << "Введите возраст: ";
        cin >> people[i].age;

    
        cout << "Военнообязанный? (1 - да, 0 - нет): ";
        int temp;
        cin >> temp;
        people[i].ms = MilitaryStatus(temp);
    }
    int youngest_age_1 = 1000;
    string youngest_surname_1;
    for (Person person : people)
    {
        if (person.ms == liable && person.age < youngest_age_1)
        {
            youngest_age_1 = person.age;
            youngest_surname_1 = person.surname;

        }
    }
    cout << "Фамилия младшего по возрасту среди военнообязанных: " << youngest_surname_1 << endl;
    int oldest_age_0 = 0, oldest_age_1 = 0;
    string oldest_surname_0, oldest_surname_1;

    for (Person person : people)
    {
        if (person.ms == liable && person.age > oldest_age_1)
        {
            oldest_age_1 = person.age;
            oldest_surname_1 = person.surname;

        }
        if (person.ms == nonliable && person.age > oldest_age_0)
        {
            oldest_age_0 = person.age;
            oldest_surname_0 = person.surname;

        }
    }
    cout << "Фамилия старшего по возрасту среди военнообязанных: " << oldest_surname_1 << endl;
    cout << "Фамилия старшего по возрасту среди не военнообязанных: " << oldest_surname_0;
}

