#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTriangle(vector<int> input);
vector< vector<int> > parseTriangle(vector<int> input);

int main(void)
{
  int inputArray[] =
  {
    75,
    95, 64,
    17, 47, 82,
    18, 35, 87, 10,
    20,  4, 82, 47, 65,
    19,  1, 23, 75,  3, 34,
    88,  2, 77, 73,  7, 63, 67,
    99, 65,  4, 28,  6, 16, 70, 92,
    41, 41, 26, 56, 83, 40, 80, 70, 33,
    41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
    53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
    70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
    91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
    63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
     4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
  };

  vector<int> input(inputArray, inputArray + sizeof(inputArray) / sizeof(int));

  if (!isTriangle(input))
  {
    cout << "Something is wrong." << endl;
    return -1;
  }
  
  vector<vector<int> > triangle = parseTriangle(input);

  for (int i = triangle.size() - 2; i >= 0; i--)
  {
    for (int j = 0; j < triangle[i].size(); j++)
    {
      triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
  }

  cout << triangle[0][0] << endl;
  
  return 0;
}

bool isTriangle(vector<int> input)
{
  int length = input.size();
  int e = 1;

  while (length > 0)
  {
    length -= e;
    e++;
  }

  if (length == 0) { return  true; }
  
  return false;
}

vector< vector<int> > parseTriangle(vector<int> input)
{
  vector<vector<int> > output;
  int e = 1;

  while (!input.empty())
  {
    vector<int> row(e);
    output.push_back(row);
    for (int i = 0; i < e; i++)
    {
      output[e - 1][i] = input[0];
      input.erase(input.begin());
    }
    e++;
  }

  return output;
}
