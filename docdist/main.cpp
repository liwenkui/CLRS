#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;
vector<string> get_words_from_string(string const&s) {
	vector<string> word_in_line;
	vector<char> character_list;
	for (auto c : s) {
		if (isalnum(c))
			character_list.push_back(c);
		else if (character_list.size() > 0) {
			string word;
			word.insert(word.begin(), character_list.begin(), character_list.end());
			for (auto& cc : word)
				cc = tolower(cc);
			word_in_line.push_back(word);
			character_list = {};
		}
	}
	if (character_list.size() > 0) {
		string word(character_list.begin(), character_list.end());
		for (auto& cc : word)
			cc = tolower(cc);
		word_in_line.push_back(word);
	}
	return word_in_line;
}

vector<string> get_words_from_line_list(vector<string> const& s) {
	vector<string> word_list;
	for (auto line : s) {
		vector<string> word_in_line;
		word_in_line = get_words_from_string(line);
		for (auto c : word_in_line)
			word_list.push_back(c);
	}
	return word_list;
}
vector<pair<string, int>> count_frequency(vector<string> const &s) {
	vector<pair<string, int>> L;
	auto entry = L.begin();
	for (auto new_word : s) {
		for (entry = L.begin(); entry != L.end(); ++entry) {
			if (new_word == entry->first) {
				++entry->second;
				break;
			}
		}
		if (entry == L.end())
			L.push_back({ new_word,1 });
	}
	return L;
}

vector<pair<string, int>> word_frequencies_for_file(string const& file_name) {
	ifstream file;
	file.open(file_name);
	string in;
	vector<string> line_list;
	if (file.fail()) {
		cout << "can not open the file" << endl;
		exit(0);
	}
	while (getline(file, in))
		line_list.push_back(in);
	vector<string> word_list;
	word_list = get_words_from_line_list(line_list);
	vector<pair<string, int>> freq_mapping = count_frequency(word_list);
	return freq_mapping;
}
double inner_product(vector<pair<string, int>> const&L1, vector<pair<string, int>> const&L2) {
	double sum = 0.0;
	for (auto word1 : L1)
		for (auto word2 : L2)
			if (word1.first == word2.first)
				sum += (word1.second*word2.second);
	return sum;
}
double vector_angle(vector<pair<string, int>> const&L1, vector<pair<string, int>> const&L2) {
	double numerator = inner_product(L1, L2);
	double donominator = sqrt(inner_product(L1, L1)*inner_product(L2, L2));
	return acos(numerator / donominator);
}

int main(int arcg, char*argv[]) {
	string filename_1 = argv[1];
	string filename_2 = argv[2];
	cout << "Usage: docdist " << filename_1 << " " << filename_2 << endl;
	vector<pair<string, int>> sorted_word_list_1, sorted_word_list_2;
	sorted_word_list_1 = word_frequencies_for_file(filename_1);
	sorted_word_list_2 = word_frequencies_for_file(filename_2);
	double distance = vector_angle(sorted_word_list_1, sorted_word_list_2);
	distance=distance*180/M_PI;	
	cout << "The distance between the documents is: " << distance << endl;
	return 0;
}
