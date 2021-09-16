#include<fstream>
#include<queue>
#include<iostream>
using namespace std;
int main() {
	int number;
	cin >> number;
	queue<int>que_original;
	for (int i = 0; i < number; i++) {
		int temp;
		cin >> temp;
		que_original.push(temp);
	}
	queue<int>que;
	queue<int>que_check; 	//check if front in original repeat with que.
	int answer = 1;
	for (int i = 0; i < number; i++) {
		int front;
		front = que_original.front(); que_original.pop();
		bool repeat_flag = false;
		int size = que_check.size();
		for (int j = 0; j < size; j++) {
			int temp;
			temp = que_check.front(); que_check.pop(); 
			if (temp == front) {
				repeat_flag = true;
				break;
			}
		}
		if (repeat_flag) que = que_check;
		que.push(front);

		que_check = que;	//assign here,prepare for next loop
		if (answer < que.size()) answer = que.size();
	}
	cout << answer;
}
