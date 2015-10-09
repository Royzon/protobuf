/*************************************************************************
	> File Name: list_people.cpp
	> Author: gwq
	> Mail: gwq5210@qq.com 
	> Created Time: 2015年10月09日 星期五 21时18分53秒
 ************************************************************************/

#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "AddressBook.pb.h"

#define INF (INT_MAX / 10)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back
#define sz(a) ((int)(a).size())

using namespace std;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef long long ll;

const double esp = 1e-5;

void ListPeople(const Demo::AddressBook &address_book)
{
	for (int i = 0; i < address_book.person_size(); ++i) {
		const Demo::Person &person = address_book.person(i);
		cout << "Person ID: " << person.id() << endl;
		cout << "Person name: " << person.name() << endl;
		if (person.has_email()) {
			cout << "Person email: " << person.email() << endl;
		}
		for (int j = 0; j < person.phone_size(); ++j) {
			const Demo::Person::PhoneNumber &phone_number = person.phone(j);
			switch (phone_number.type()) {
				case Demo::Person::MOBILE: 
					cout << "Moblie phone #:";
					break;
				case Demo::Person::HOME: 
					cout << "Home phone #:";
					break;
				case Demo::Person::WORK: 
					cout << "Work phone #:";
					break;
			}
			cout << phone_number.number() << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <address_book_file>" << endl;
		exit(EXIT_FAILURE);
	}

	Demo::AddressBook address_book;
	fstream input(argv[1], ios::in | ios::binary);
	if (!address_book.ParseFromIstream(&input)) {
		cerr << "Failed to parse address book." << endl;
		exit(EXIT_FAILURE);
	}

	ListPeople(address_book);

	//cout << address_book.DebugString() << endl;;

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}
