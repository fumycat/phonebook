#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <vcl.h>

using namespace std;

class UAbonentList {
	private:
		multimap<UnicodeString, UnicodeString> mm;

	public:
		vector<UnicodeString> as_str() {
			vector<UnicodeString> r;
			for (multimap<UnicodeString, UnicodeString>::iterator it=mm.begin(); it!=mm.end(); ++it) {
				UnicodeString str = (*it).first + " " + (*it).second;
				r.push_back(str);
			}
            return r;
		}

		void add(UnicodeString name, UnicodeString number) {
			mm.insert(pair<UnicodeString, UnicodeString>(name, number));
		}

		void clr() {
            mm.clear();
        }

		void rem(int index) {
			auto it = mm.begin();
			for (int i = 0; i < index; i++) {
				it++;
			}
            mm.erase(it);
		}

		int find(UnicodeString key) {
			auto f = mm.find(key);
			if (f != mm.end()) {
				return distance(mm.begin(), f);
			} else {
                return -1;
            }
		}

		pair<UnicodeString, UnicodeString> get_at(int index){
			auto it = mm.begin();
            for (int i = 0; i < index; i++) {
				it++;
			}
			return make_pair((*it).first, (*it).second);
		}
};
