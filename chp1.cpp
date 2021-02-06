#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void oneone(string s){
	map<char, int> chars;
	for(char c: s){
		if(chars.find(c) == chars.end()){
			chars[c] = 1;
		}else{
			cout << "Repeated character!\n";
			return;
		}
	}
	cout << "All unique characters\n";
	return;
}

void onetwo(string s1, string s2){
	map<char, int> chars1;
	map<char, int> chars2;
	for(char c: s1){
		if(chars1.find(c) == chars1.end()){
			chars1[c] = 1;
		}else{
			chars1[c]++;
		}
	}
	for(char c: s2){
		if(chars2.find(c) == chars2.end()){
			chars2[c] = 1;
		}else{
			chars2[c]++;
		}
	}
	auto it = chars1.begin();
	while(it != chars1.end()){
		if(chars1[it->first] != chars2[it->first]){
			cout << "Not a permutation!\n";
			return;
		}
		it++;
	}

	cout << "Permutation!\n";
	return;
}

void onethree(string s){
	int pos = 0;
	if(s[0] == ' '){
		for(int i = 0; i < s.size(); ++i){
			if (s[i] == ' '){
				pos++;
			}else{break;}
		}
		s = s.erase(0,pos);
	}
	pos = 0;
	if(s[s.size()-1] == ' '){
		for(int i = s.size()-1; i > -1; --i){
			if(s[i] == ' '){
				pos++;
			}else{break;}
		}
		s = s.erase(s.size()-pos,pos);

	}
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == ' '){
			s.erase(i,1);
			s.insert(i, "%20");
		}
	}
	cout << s << "\n";
}

void onefour(string s){
	int amt = 0;
	map<char, int>chars;
	for (char c:s){
		if(c != ' '){
			amt++;
			if(chars.find(c) == chars.end()){
				chars[c] = 1;
			}else{
				chars[c]++;
			}
		}
	}
	bool even = amt%2 == 0;
	int num_odd = 0;
	auto it = chars.begin();
	while(it != chars.end()){
		char c = it->first;
		if(even && chars[c]%2 != 0){
			cout << "Not a palindrome!\n";
			return;
		}
		else if(!even && chars[c]%2 != 0){
			if(num_odd == 0){num_odd++;}
			else{
				cout << "Not a palindrome!\n";
				return;
			}
		}
		it++;
	}
	cout << "Palindrome!\n";
}

void onefive(string s1, string s2){
	if(s1 == s2){
		cout << "Same string!\n";
		return;
	}
	else if(abs((int)s1.size()-(int)s2.size()) > 1){
		cout << "Cannot edit!\n";
		return;
	}
	else if(s1.size()==s2.size()){
		auto it1 = s1.begin();
		auto it2 = s2.begin();
		int diff = 0;
		while(it1 != s1.end()){
			if(*it1 != *it2) diff++;
			it1++;it2++;
		}
		if (diff > 1){
			cout << "Cannot edit!\n";
			return;
		}
	}
	else{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		int diff = 0;
		auto it1 = s1.begin();
		auto it2 = s2.end();
		if (s1.size() < s2.size()){
			while(it1 != s1.end()){
				if(*it1 != *it2){
					if(diff < 1){
						diff++;
						it1--;
					}
					else{
						cout << "Cannot edit!\n";
						return;
					}
				}
				it1++;it2++;
			}
		}
		else{
			while(it2 != s2.end()){
				if(*it1 != *it2){
					if(diff < 1){
						diff++;
						it2--;
					}
					else{
						cout << "Cannot edit!\n";
						return;
					}
				}
				it1++;it2++;
			}
		} 
	}
	cout << "Can make the same!\n";
}

void onesix(string s){
	char curr_char = s[0];
	int curr_amt = 0;
	string comp = "";
	auto it = s.begin();

	string temp = s;
	sort(temp.begin(), temp.end());
	bool unique = true;
	for(int i = 0; i < temp.size()-1; ++i){
		if (s[i] == s[i+1]){
			unique = false;
			break;
		}
	}
	if(unique){
		cout << s << endl;
		return;
	}
	while(it != s.end()){
		if(*it != curr_char){
			cout << curr_char << curr_amt;
			comp += curr_char;
			comp += (char)curr_amt;
			curr_char = *it;
			curr_amt = 1;
		}else{curr_amt++;}
		it++;
	}
	cout << curr_char << curr_amt << endl;
}

void oneseven(vector<vector<char>> matrix){
	vector<vector<char>> rotated = matrix;
	int N = matrix.size();
	
	for(int i = 0; i < N; ++i){
		int row = 0;
		for(int j = N-1; j > -1; --j){
			rotated[i][j] = matrix[row][i];
			row++;
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << rotated[i][j];
		}cout << endl;
	}
}

void oneeight(vector<vector<int>> matrix){
	set<int> rows;
	set<int> cols;
	int M = matrix.size();
	int N = matrix[0].size();

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(matrix[i][j] == 0){
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	auto it = rows.begin();
	while(it != rows.end()){
		for(int j = 0; j < N; ++j){
			matrix[*it][j] = 0;
		}
		it++;
	}
	it = cols.begin();
	while(it != cols.end()){
		for(int j = 0; j < M; ++j){
			matrix[j][*it] = 0;
		}
		it++;
	}		


	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			cout << matrix[i][j];
		}cout << endl;
	}

}

void onenine(string s1, string s2){

	

	cout << "Rotation!\n";
}

int main(){

	// oneone("manic");
	// onetwo("abc", "cba");
	// onethree("      ree kid     ");
	// onefour("c arec ra");
	// onefive("pale", "bake");
	// onesix("aaccccbabbbbbccc");
	// oneseven({{'a','b','c'}, {'d','e','f'}, {'g','h','i'}});
	// oneeight({{ 1, 2, 3, 9}, { 4, 0, 5, 6 }, { 7, 8, 9, 4 }});
	onenine("waterbottle", "erbottlewat");

	return 0;
}
