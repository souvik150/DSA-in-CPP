#include "bits/stdc++.h"

using namespace std;

class Student
{
public:
  string name;
  int age;
  int roll;
  float cgpa;
  Student(string name, int age, int roll, float cgpa)
  {
    this->name = name;
    this->age = age;
    this->roll = roll;
    this->cgpa = cgpa;
  }
};

void getDetailsofStudent(Student s)
{
  cout << "Name: " << s.name << endl;
  cout << "Age: " << s.age << endl;
  cout << "Roll: " << s.roll << endl;
  cout << "CGPA: " << s.cgpa << endl;
}

void sortArrayOfStudents(Student s[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (s[i].cgpa < s[j].cgpa)
      {
        Student temp = s[i];
        s[i] = s[j];
        s[j] = temp;
      }
    }
  }
}

void binSearchStudents(Student s[], int n, int roll)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (s[mid].roll == roll)
    {
      getDetailsofStudent(s[mid]);
      return;
    }
    else if (s[mid].roll > roll)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  cout << "Student not found" << endl;
}

int main()
{
  Student std[5] = {
      Student("A", 20, 5, 8.5),
      Student("B", 21, 4, 8.6),
      Student("C", 22, 3, 8.7),
      Student("D", 23, 2, 8.8),
      Student("E", 24, 1, 8.9)};

  for (int i = 0; i < 5; i++)
  {
    getDetailsofStudent(std[i]);
    cout << endl;
  }

  sortArrayOfStudents(std, 5);

  for (int i = 0; i < 5; i++)
  {
    getDetailsofStudent(std[i]);
    cout << endl;
  }

  binSearchStudents(std, 5, 3);
}