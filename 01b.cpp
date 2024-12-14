#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ifstream input("inputs/01.txt");

  if (!input.is_open()) {
    cout << "Unable to open file." << endl;
  }

  int left_list_item = 0;
  int right_list_item = 0;

  vector<int> left_list;

  map<int, int> count_of_right_values;

  while (input >> left_list_item >> right_list_item) {
    left_list.push_back(left_list_item);

    count_of_right_values[right_list_item] += 1;
  }

  int similarity_score = 0;

  for (auto item : left_list) {
    similarity_score += count_of_right_values[item] * item;
  }

  cout << "Similarity score: " << similarity_score << endl;
}