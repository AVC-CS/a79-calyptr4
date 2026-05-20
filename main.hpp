#ifndef MAIN_HPP
#define MAIN_HPP

// Vector intro: makeVector, insertVector, deleteVector

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void makeVector(vector<int> &);
void insertVector(vector<int> &, int);
int deleteVector(vector<int> &, int);
int randnum(void);
int getInput(void);
void printVector(vector<int>);

void makeVector(vector<int> &number)
{
    for(int i = 0; i < number.size(); i++)
        number[i] = randnum() % 20;
    sort(number.begin(), number.end());
    // TODO: fill the vector with random integers in [0, 20), then sort it.
}

void insertVector(vector<int> &number, int usernum)
{
    vector<int>::iterator iter;
    for (iter = number.begin(); iter != number.end(); iter++)
    if (usernum < *iter)
    break;
    number.insert(iter, usernum);
    // TODO: insert usernum into the sorted vector while keeping it sorted.
}

int deleteVector(vector<int> &number, int usernum)
{
    int count = 0;
    auto iter = number.begin();
    while (iter != number.end()){
        if (*iter == usernum){
            iter = number.erase(iter);
            count++;
        }
        else
            ++iter;
    }
    if (count == 0){
        return -1;
    } else return usernum;
    // TODO: erase EVERY occurrence of usernum from the vector.
}

int getInput(void)
{
    int num;
    cout << "Enter your input\n";
    cin >> num;
    return num;
}

int randnum(void)
{
    return rand() % 100;
}

void printVector(vector<int> number)
{
    for (auto iter = number.begin(); iter != number.end(); iter++)
        cout << setw(5) << *iter;
    cout << endl;
}

#endif
