#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int mark1=0, mark2=0, mark3=0;
    double mark=0;
};

void Average(Student& student) {
    student.mark = (student.mark1 + student.mark2 + student.mark3) / 3.0;
}

bool comp(const Student& student_1, const Student& student_2) {
    return student_1.mark > student_2.mark;
}

int main() {
    int n;
    std::cout << "Enter the number of students" << std::endl;
    std::cin >> n;
    std::vector<Student> students;
    Student tmp;
    std::cout << "On every line enter the name of student and three marks from 0 to 10 in a row through space" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp.name >> tmp.mark1 >> tmp.mark2 >> tmp.mark3;
        if (tmp.mark1 < 0 || tmp.mark1 > 10 || tmp.mark2 < 0 || tmp.mark2 > 10 || tmp.mark3 < 0 || tmp.mark3 > 10) {
            std::cout << "Invalid value. The marks must be from 0 to 10." << std::endl;
            return 0;
        }
        Average(tmp);
        students.push_back(tmp);
    }
    std::sort(students.begin(), students.begin() + n, comp);
    std::cout << "The best students by average mark:" << std::endl;
    int i = 0;
    if (n < 3)
        for (i = 0; i < n; ++i)
            std::cout << students[i].name << '\n';
    else {
        for (i = 0; i < 3; ++i)
            std::cout << students[i].name << '\n';
        while (i < n && students[i].mark == students[2].mark) {
            std::cout << students[i].name << '\n';
            i++;
        }
    }
    return 0;
}

