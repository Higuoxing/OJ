#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

std::map<std::string, std::set<int>> names;   // names
std::map<std::string, std::set<int>> authors; // authors
std::map<std::string, std::set<int>> keys;    // key words
std::map<std::string, std::set<int>> pubs;    // pubs
std::map<std::string, std::set<int>> years;   // years

void print(char op, std::string item,
           std::map<std::string, std::set<int>> &data) {
  printf("%c: %s\n", op, item.c_str());
  auto it = data.find(item);
  if (it == data.end())
    printf("Not Found\n");
  else {
    for (auto &i : data[item])
      printf("%07d\n", i);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int id;
    std::string year, name, author, pub, keys_str;
    std::vector<std::string> tmp_key;
    scanf("%d\n", &id);
    getline(std::cin, name);
    getline(std::cin, author);
    getline(std::cin, keys_str);
    getline(std::cin, pub);
    getline(std::cin, year);
    std::istringstream iss(keys_str);
    tmp_key = std::vector<std::string>(std::istream_iterator<std::string>{iss},
                                       std::istream_iterator<std::string>());
    names[name].insert(id);
    authors[author].insert(id);
    years[year].insert(id);
    pubs[pub].insert(id);
    for (auto &i : tmp_key) {
      keys[i].insert(id);
    }
  }

  int m;
  scanf("%d\n", &m);

  for (int i = 0; i < m; ++i) {
    std::string query;
    getline(std::cin, query);
    std::string item = query.substr(3);
    switch (query[0]) {
    case '1':
      print('1', item, names);
      break;
    case '2':
      print('2', item, authors);
      break;
    case '3':
      print('3', item, keys);
      break;
    case '4':
      print('4', item, pubs);
      break;
    case '5':
      print('5', item, years);
      break;
    }
  }

  return 0;
}

