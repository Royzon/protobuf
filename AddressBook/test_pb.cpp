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

void PromptForAddress(Demo::Person *person)
{
	cout << "Enter person ID number: ";
	int id;
	cin >> id;
	person->set_id(id);
	cin.ignore(256, '\n');

	cout << "Enter person name: ";
	getline(cin, *person->mutable_name());

	cout << "Enter email address (blank for none): ";
	string email;
	getline(cin, email);
	if (!email.empty()) {
		person->set_email(email);
	}

	while (true) {
		cout << "Enter a phone number (or leave blank to finish): ";
		string number;
		getline(cin, number);
		if (number.empty()) {
			break;
		}

		Demo::Person::PhoneNumber *phone_number = person->add_phone();
		phone_number->set_number(number);

		cout << "Is this a mobile, home, or work phone? ";
		string type;
		getline(cin, type);
		if (type == "mobile") {
			phone_number->set_type(Demo::Person::MOBILE);
		} else if (type == "home") {
			phone_number->set_type(Demo::Person::HOME);
		} else if (type == "work") {
			phone_number->set_type(Demo::Person::WORK);
		} else {
			cout << "Unknown phone type. Using default." << endl;
		}
	}
}

void PrintUsage(const char *pName)
{
    cerr << "Usage: " << pName << " [list|add] <address_book_file>" << endl;
}

int main(int argc, char *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	if (argc != 3) {
        PrintUsage(argv[0]);
		exit(EXIT_FAILURE);
	}

    const char *pAct = argv[1];
    const char *pFile = argv[2];

	Demo::AddressBook address_book;

    if (strcmp(pAct, "list") == 0) {
        fstream input(pFile, ios::in | ios::binary);
        if (!address_book.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            exit(EXIT_FAILURE);
        }

        //cout << address_book.DebugString() << endl;;
        ListPeople(address_book);
    } else if (strcmp(pAct, "add") == 0) {
        fstream input(pFile, ios::in | ios::binary);
        if (!input) {
            cout << pFile << ": File not found. Creating a new file." << endl;
        } else if (!address_book.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            exit(EXIT_FAILURE);
        }

        PromptForAddress(address_book.add_person());

        fstream output(pFile, ios::out | ios::trunc | ios::binary);
        if (!address_book.SerializeToOstream(&output)) {
            cerr << "Failed to write address book." << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        PrintUsage(argv[0]);
        return 0;
    }

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}
