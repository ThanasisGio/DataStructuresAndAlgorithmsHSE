#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <array>

#define ll long long

using namespace std;
using std::vector;
using std::string;

struct Query {

	string s, type;
	int ind;

};

class QueryProcessor {

    int bucket_count;
    vector<list<string>> elems;
    size_t hashFunction(const string& s) const {

        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned ll hash = 0;

	for (int i = static_cast<int>(s.size()) - 1; i >= 0 ; --i) {
	    hash = (( (hash * multiplier + s[i]) % prime) + prime ) % prime;
			}
          return hash % bucket_count;

	}


public:

	explicit QueryProcessor(int bucket_count) {
     
        this->bucket_count = bucket_count;
            list<string> l;
         for(size_t i = 0; i < bucket_count; ++i) {
		this->elems.push_back(l);
		}
	}



	Query read_data() const {

	Query query;
        cin >> query.type;

	 if (query.type == "check")
	    cin >> query.ind;
          else
	     cin >> query.s;
           return query;

	}



	void writeSearchResult(bool was_found) const {

		cout << (was_found ? "yes\n" : "no\n");

	}



	void processQuery(const Query& query) {
             if (query.type == "check") {
                if (query.ind < elems.size()) {
                     auto A = elems[query.ind];
                         for (auto s : A) {
			   cout << s << " ";
				}

				cout << endl;
			}
		}

		else {

			size_t hash_ind = hashFunction(query.s);

			auto it = find(elems[hash_ind].begin(), elems[hash_ind].end(), query.s);

			if (query.type == "find")
				writeSearchResult(it != elems[hash_ind].end());

			else if (query.type == "add") {

				if (it == elems[hash_ind].end())
					elems[hash_ind].push_front(query.s);

			}

			else if (query.type == "del") {

				if (it != elems[hash_ind].end())
					elems[hash_ind].erase(it);
			}

		}


	}

	void processQueries() {

        int n;
        cin >> n;

		vector<Query> queries(n);

		for (int i = 0; i < n; ++i)
			queries[i] = read_data();

		for (int i = 0; i < n; ++i)
            processQuery(queries[i]);

		cout << endl;

    }

};


int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;

}
