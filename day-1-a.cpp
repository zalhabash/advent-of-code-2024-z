#include <algorithm>
#include <fstream>
#include <iostream>
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

  if (left_list.size() != right_list.size()) {
    cout << "Error: left and right lists are not the same size." << endl;
  }

  sort(left_list.begin(), left_list.end());
  sort(right_list.begin(), right_list.end());

  int distance = 0;

  for (size_t i = 0; i < left_list.size(); i++) {
    distance += abs(left_list[i] - right_list[i]);
  }

  cout << "distance: " << distance << endl;
  return 0;
}