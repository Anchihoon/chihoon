#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    char sex;
    string home;
    string major;
    float grade;
    int height;
    int weight;
};

int main() {
    ifstream file;
    file.open("list.txt");
    if (file.fail()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int line_count = 0;
    string line;
    while (getline(file, line)) {
        line_count++;
    }
    file.clear();
    file.seekg(0);

    Student* students = new Student[line_count];
    string name;
    char sex;
    string home;
    string major;
    float grade;
    int height;
    int weight;
    for (int i = 0; i < line_count; i++) {
        file >> name >> sex >> home >> major >> grade >> height >> weight;
        students[i].name = name;
        students[i].sex = sex;
        students[i].home = home;
        students[i].major = major;
        students[i].grade = grade;
        students[i].height = height;
        students[i].weight = weight;
    }

    for (int i = 0; i < line_count; i++) {
        cout << students[i].name << " " << students[i].sex << " " << students[i].home << " " << students[i].major << " " << students[i].grade << " " << students[i].height << " " << students[i].weight << endl;
    }

    delete[] students;

    file.close();

    return 0;
}