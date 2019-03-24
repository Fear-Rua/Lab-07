#include <iostream>
#include <string>

using namespace std;

int main()
{
    char input = 'z';
    int capacity = 2, ary_size = 0;
    string* student_name = new string[capacity];

    while( input != 'q' && input != 'Q')
    {
        cout << "Array size: " << ary_size << ", " << "Capacity: " << capacity << endl
             << "Menu\n"
             << "A) Add student\nD) Delete student\nL) List all student/s\nQ) Quit\n"
             << "\nPlease input the letter corresponding with one of the options above: ";

        cin  >> input;
        cin.ignore();

        switch(input)
        {
            case 'a':
            case 'A':
                {
                    if(ary_size == capacity)
                    {
                        capacity = capacity * 2;
                        string* add_student = new string[capacity];
                        for(int i = 0; i < (capacity / 2); i++)
                            add_student[i] = student_name[i];
                        delete [] student_name;
                        string* student_name = new string[capacity];
                        for(int i = 0; i < capacity; i++)
                            student_name[i] = add_student[i];
                        delete [] add_student;
                    }
                        cout << "\nPlease input new student's name: ";
                        getline(cin, student_name[ary_size]);
                        ary_size++;

                        break;
                }
            case 'q':
            case 'Q':
                break;
        }

        for(int i = 0; i < ary_size; i++)
                cout << student_name[i] << "\n";
    }

    delete student_name;
}
