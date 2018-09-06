#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Student {
public:
  int id;
  int mark;
  string name;
  Student(int id, string name, int mark)
    : id(id), name(name), mark(mark) {}
  ~Student() = default;
};
bool comp1(Student s0, Student s1) {
  return s0.id < s1.id;
}
bool comp2(Student s0, Student s1) {
  if (s0.name == s1.name) return s0.id < s1.id;
  else return s0.name < s1.name;
}
bool comp3(Student s0, Student s1) {
  if (s0.mark == s1.mark) return s0.id < s1.id;
  else return s0.mark < s1.mark;
}
int main() {
  int n, c;
  vector<Student> students;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++ i) {
    int id, mark;
    string name;
    cin >> id >> name >> mark;
    students.push_back(Student(id, name, mark));
  }
  if (c == 1) sort(students.begin(), students.end(), comp1);
  else if (c == 2) sort(students.begin(), students.end(), comp2);
  else if (c == 3) sort(students.begin(), students.end(), comp3);
  for (auto &i : students)
    printf("%06d %s %d\n", i.id, i.name.c_str(), i.mark);
  return 0;
}
