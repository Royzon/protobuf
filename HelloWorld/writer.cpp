/*************************************************************************
	> File Name: writer.cpp
	> Author: gwq
	> Mail: gwq5210@qq.com 
	> Created Time: 2015年10月09日 星期五 19时18分36秒
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

int main(int argc, char *argv[])
{
	gwq5210::helloworld msg;
	msg.set_id(100);
	msg.set_str("gwq5210");

	fstream output("./data", ios::out | ios::trunc | ios::binary);
	if (!msg.SerializeToOstream(&output)) {
		cerr << "Failed to write msg." << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
