#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;
using std::vector;
using std::string;

struct Query {

	string type, name;
	int number;

};

vector<Query> read_data() {

	int N;
	cin >> N;

	vector<Query> queries(N);

	for (int i = 0; i < N; ++i) {

		cin >> queries[i].type;

		if (queries[i].type == "add")
			cin >> queries[i].number >> queries[i].name;

		else
			cin >> queries[i].number;

	}

	return queries;

}


void write_responses(const vector<string>& result) {

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}

}


vector<string> process_queries(vector<Query> queries) {

	vector<string> result;

	const int contact_size = 10000000;
	vector<string> contacts(contact_size);

	for(size_t i = 0; i < queries.size(); ++i) {

		if(queries[i].type == "add") {
			contacts[queries[i].number] = queries[i].name;
		}

		else if(queries[i].type == "del") {
			contacts[queries[i].number] = "";
		}

		else {

			if (contacts[queries[i].number] == "")
				result.push_back("not found");

			else
				result.push_back(contacts[queries[i].number]);
		}


	}

	return result;

}


int main() {

	write_responses(process_queries(read_data()));

	return 0;

}
