all: add_person list_people

add_person: addressbook add_person.o AddressBook.pb.o
	g++ -o $@ add_person.o AddressBook.pb.o -lpthread -lprotobuf -pthread
list_people: addressbook list_people.o AddressBook.pb.o
	g++ -o $@ list_people.o AddressBook.pb.o -lpthread -lprotobuf -pthread
addressbook: AddressBook.proto
	protoc -I=. --cpp_out=. ./AddressBook.proto
AddressBook.pb.o:
	g++ -c AddressBook.pb.cc
clean:
	rm -rf AddressBook.pb.o AddressBook.pb.cc AddressBook.pb.h list_people add_person list_people.o add_person.o
