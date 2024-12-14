#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ifstream input("inputs/day-1-a.txt");

  if (!input.is_open()) {
    cout << "Unable to open file." << endl;
  }

  int left_list_item = 0;
  int right_list_item = 0;

  vector<int> left_list;
  vector<int> right_list;

  while (input >> left_list_item >> right_list_item) {
    left_list.push_back(left_list_item);
    right_list.push_back(right_list_item);
  }

  set<int> unique_left_elements(left_list.begin(), left_list.end());

  int similarity_score = 0;

  for (auto item : unique_left_elements) {
    similarity_score += item * count(left_list.begin(), left_list.end(), item) *
                        count(right_list.begin(), right_list.end(), item);
  }

  cout << "Similarity score: " << similarity_score << endl;
}