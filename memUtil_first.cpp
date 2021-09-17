#include<fstream>
#include<queue>
#include<iostream>
#include<algorithm>
#define RANGE 1000001
using namespace std;
int main(){
	ifstream infile("problem.txt");
	int number;
	infile >> number;
	int temp;
	queue<int>que_original;
	for(int i = 0;i < number;i++){
		infile >> temp;
		que_original.push(temp);
	}

	bool f[RANGE] = { false };	//all set to be false
	int answer = 1;
	queue<int>que_dynamic;
	int cnt = 0;
	int temp2;
	for(int i = 0;i < number;i++){
		temp = que_original.front(); que_original.pop();
		if(!f[temp]) f[temp] = true;
		else{
			while( (temp2 = que_dynamic.front()) != temp ){
				que_dynamic.pop();
				f[temp2] = false;
			}
			que_dynamic.pop();	//this step: pop the repeated number.
		}
		que_dynamic.push(temp);
		answer = max( answer ,(int)que_dynamic.size());

	}
	cout << answer;

}
