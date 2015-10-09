/*************************************************************************
	> File Name: reader.cpp
	> Author: gwq
	> Mail: gwq5210@qq.com 
	> Created Time: 2015年10月09日 星期五 19时40分26秒
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

#include "gwq5210.helloworld.pb.h"

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

void ListMsg(const gwq5210::helloworld &msg)
{
	cout << msg.id() << endl;
	cout << msg.str() << endl;
}

int main(int argc, char *argv[])
{
	gwq5210::helloworld msg;
	fstream input("./data", ios::in | ios::binary);
	if (!msg.ParseFromIstream(&input)) {
		cerr << "Failed to parse msg." << endl;
		exit(EXIT_FAILURE);
	}
	ListMsg(msg);
	cout << msg.DebugString() << endl;
	return 0;
}
