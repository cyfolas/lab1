using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


enum MilitaryStatus
{
    liable,
    nonliable
}

struct Person
{
    public string surname;
    public int age;
    public MilitaryStatus ms;
}

class Program
{
    static void Main()
    {
        const int SIZE = 3;
        Person[] people = new Person[SIZE];

        Console.WriteLine("Заполнение массива структур:");
        Console.WriteLine("============================");

        for (int i = 0; i < SIZE; i++)
        {
            Console.WriteLine("\nЧеловек #" + (i + 1) + ":");

            Console.Write("Введите фамилию: ");
            people[i].surname = Console.ReadLine();

            Console.Write("Введите возраст: ");
            people[i].age = Convert.ToInt32(Console.ReadLine());

            Console.Write("Военнообязанный? (1 - да, 0 - нет): ");
            int temp = Convert.ToInt32(Console.ReadLine());
            people[i].ms = (MilitaryStatus)temp;
        }

        int youngest_age_1 = 1000;
        string youngest_surname_1 = "";
        foreach (Person person in people)
        {
            if (person.ms == MilitaryStatus.liable && person.age < youngest_age_1)
            {
                youngest_age_1 = person.age;
                youngest_surname_1 = person.surname;
            }
        }
        Console.WriteLine("Фамилия младшего по возрасту среди военнообязанных: " + youngest_surname_1);

        int oldest_age_0 = 0;
        int oldest_age_1 = 0;
        string oldest_surname_0 = "";
        string oldest_surname_1 = "";

        foreach (Person person in people)
        {
            if (person.ms == MilitaryStatus.liable && person.age > oldest_age_1)
            {
                oldest_age_1 = person.age;
                oldest_surname_1 = person.surname;
            }
            if (person.ms == MilitaryStatus.nonliable && person.age > oldest_age_0)
            {
                oldest_age_0 = person.age;
                oldest_surname_0 = person.surname;
            }
        }
        Console.WriteLine("Фамилия старшего по возрасту среди военнообязанных: " + oldest_surname_1);
        Console.WriteLine("Фамилия старшего по возрасту среди не военнообязанных: " + oldest_surname_0);
    }

}
