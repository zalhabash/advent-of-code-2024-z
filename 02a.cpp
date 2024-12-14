#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream input("inputs/02.txt");

  if (!input.is_open()) {
    cout << "Unable to open file." << endl;
  }

  string line;
  int safe_count = 0;

  while (getline(input, line)) {
    stringstream splitting_line(line);

    int previous_level;
    splitting_line >> previous_level;
    int current_level;
    bool is_positive;
    bool is_first = true;
    bool report_is_safe = true;

    while (splitting_line >> current_level) {
      int difference = current_level - previous_level;

      if (is_first) {
        is_positive = difference >= 0;
        is_first = false;
      }

      if ((difference >= 0) == is_positive && abs(difference) >= 1 &&
          abs(difference) <= 3) {
      } else {
        report_is_safe = false;
      }

      previous_level = current_level;
    }
    if (report_is_safe) {
      safe_count += 1;
    }
  }
  cout << "Safe reports: " << safe_count << endl;
}