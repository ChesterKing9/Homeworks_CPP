#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int marks[4];
};

double getAverageMarks(const Student& student) {
    double sum = 0;
    for (int mark : student.marks) {
        sum += mark;
    }
    return sum / 4.0;
}

const Student* getBestStudent(const std::vector<Student>& students) {
    if (students.empty()) return nullptr;

    const Student* bestStudent = &students[0];
    double highestAverage = getAverageMarks(students[0]);

    for (const auto& student : students) {
        double avg = getAverageMarks(student);
        if (avg > highestAverage) {
            highestAverage = avg;
            bestStudent = &student;
        }
    }

    return bestStudent;
}

int countStudentsAboveThreshold(const std::vector<Student>& students, double threshold) {
    int count = 0;
    for (const auto& student : students) {
        if (getAverageMarks(student) > threshold) {
            count++;
        }
    }
    return count;
}

void getBestStudents(const std::vector<Student>& inStudents, std::vector<Student>& outStudents, unsigned percent) {
    if (percent == 0 || inStudents.empty()) return;

    unsigned n = (inStudents.size() * percent) / 100;
    n = std::min(n, static_cast<unsigned>(inStudents.size()));

    outStudents = inStudents;
    std::sort(outStudents.begin(), outStudents.end(), [](const Student& a, const Student& b) {
        return getAverageMarks(a) > getAverageMarks(b);
        });

    outStudents.resize(n);
}

void sortStudentsByAverage(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return getAverageMarks(a) > getAverageMarks(b);
        });
}

int main() {
    std::vector<Student> students = {
        {"Ivan", {90, 85, 88, 92}},
        {"Maria", {78, 80, 75, 85}},
        {"Petro", {95, 90, 93, 97}},
        {"Olena", {60, 65, 70, 75}}
    };

    std::cout << "Average marks of " << students[0].name << ": " << getAverageMarks(students[0]) << "\n";

    const Student* bestStudent = getBestStudent(students);
    if (bestStudent) {
        std::cout << "Best student: " << bestStudent->name << "\n";
    }

    int count = countStudentsAboveThreshold(students, 80);
    std::cout << "Students with average marks > 80: " << count << "\n";

    std::vector<Student> topStudents;
    getBestStudents(students, topStudents, 50);
    std::cout << "Top 50% students:\n";
    for (const auto& student : topStudents) {
        std::cout << student.name << " - " << getAverageMarks(student) << "\n";
    }

    sortStudentsByAverage(students);
    std::cout << "Students sorted by average marks:\n";
    for (const auto& student : students) {
        std::cout << student.name << " - " << getAverageMarks(student) << "\n";
    }

    return 0;
}
