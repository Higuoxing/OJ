#include <iostream>
#include <string>

int main() {
  std::string str;
  std::string output = "";
  std::cin >> str;

  int sum = 0;
  for (int i = 0; i < str.length(); ++ i) {
    sum += (int)(str[i] - '0');
  }

  while (sum != 0) {
    switch (sum % 10) {
      case 1:
        output = "yi " + output;
        break;
      case 2:
        output = "er " + output;
        break;
      case 3:
        output = "san " + output;
        break;
      case 4:
        output = "si " + output;
        break;
      case 5:
        output = "wu " + output;
        break;
      case 6:
        output = "liu " + output;
        break;
      case 7:
        output = "qi " + output;
        break;
      case 8:
        output = "ba " + output;
        break;
      case 9:
        output = "jiu " + output;
        break;
      case 0:
        output = "ling " + output;
        break;
    }
    sum /= 10;
  }

  for (int i = 0; i < output.length()-1; ++ i) {
    std::cout << output[i];
  }

  return 0;
}
