#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	//读取输入，获得输入总数，并生成包含所有输入数据的队列
	ifstream infile("用例输入 (1).txt");
	int number;
	infile >> number;
	queue<int>que_original;
	for (int i = 0; i < number; i++) {
		int temp;
		infile >> temp;
		que_original.push(temp);
	}
	//
	
	//对相接的不重复数队进行操作，获得最大长度。
	queue<int>que_backup;	//当vec_dynamic重新生成时使用
	queue<int>que_dynamic; 	//dynamic que,change in the changing situation.
	vector<int>vec_dynamic;	//dynamic vec,change in the changing situation.
	
	int answer = 1;
		//对每个数进行检索
	for (int i = 0; i < number; i++) {
		
		//repeat check
		int front;
		front = que_original.front(); que_original.pop();
		bool repeat_flag = binary_search(vec_dynamic.begin(),vec_dynamic.end(),front);
		//

		//que,que_dynamic,vec_dynamic,generate dynamically.
		if(repeat_flag){
			while(front != que_dynamic.front()){
				que_dynamic.pop();
			}
			que_dynamic.push(front);
			//重新生成vec_dynamic
			que_backup = que_dynamic;
			vec_dynamic.clear();
			while(que_dynamic.size()){
				int temp = que_dynamic.front();que_dynamic.pop();
				vec_dynamic.push_back(temp);
			}
			sort(vec_dynamic.begin(),vec_dynamic.end());
			que_dynamic = que_backup;
		}
		else{
			que_dynamic.push(front); vec_dynamic.push_back(front);
			sort(vec_dynamic.begin(),vec_dynamic.end());
		}
		//
		if (answer < que_dynamic.size()) answer = que_dynamic.size();
		//
	}
		//
	//
	
	//结果整理输出
	cout << answer -1;
	//
}
