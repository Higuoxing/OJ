#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
  string number;
  int lnumber;
  int lrank;
  int frank;
  int mark;
  Student(string number, int lnumber, int mark)
    : number(number), lnumber(lnumber), mark(mark) {}
  friend bool operator > (Student s1, Student s2) { 
    if (s1.mark == s2.mark && s1.lnumber != s2.lnumber)
      return s1.lnumber < s2.lnumber;
    else if (s1.mark == s2.mark && s1.lnumber == s2.lnumber)
      return s1.number < s2.number;
    return s1.mark > s2.mark;
  }
  friend bool operator < (Student s1, Student s2) {
    if (s1.mark == s2.mark && s1.lnumber != s2.lnumber)
      return s1.lnumber > s2.lnumber;
    else if (s1.mark == s2.mark && s1.lnumber == s2.lnumber)
      return s1.number > s2.number;
    return s1.mark < s2.mark;
  }
  friend bool operator == (Student s1, Student s2) { return s1.mark == s2.mark; }
  ~Student() = default;
};

bool comp(Student s1, Student s2) {
  return s1 > s2;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<Student>> students(n);
  vector<Student> fstudents;
  for (int i = 0; i < n; ++ i) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; ++ j) {
      string stnum;
      int mark;
      cin >> stnum >> mark;
      students[i].push_back(Student(stnum, i+1, mark));
    }
    sort(students[i].begin(), students[i].end(), comp);
    students[i][0].lrank = 1;
    fstudents.push_back(students[i][0]);
    for (int k = 1; k < students[i].size(); ++ k) {
      if (students[i][k].mark == students[i][k-1].mark)
        students[i][k].lrank = students[i][k-1].lrank;
      else
        students[i][k].lrank = k + 1;
      fstudents.push_back(students[i][k]);
    }
  }
  sort(fstudents.begin(), fstudents.end(), comp);
  fstudents[0].frank = 1;
  for (int k = 1; k < fstudents.size(); ++ k) {
    if (fstudents[k].mark == fstudents[k-1].mark)
      fstudents[k].frank = fstudents[k-1].frank;
    else 
      fstudents[k].frank = k+1;
  }
  printf("%lu\n", fstudents.size());
  for (int i = 0; i < fstudents.size(); ++ i) {
    auto k = fstudents[i];
    printf("%s %d %d %d\n", k.number.c_str(), k.frank, k.lnumber, k.lrank);
  }
  return 0;
}
