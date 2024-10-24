#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
using namespace std::filesystem;

vector<path> allUserPaths{};

int main()
{
	filesystem::path directorypath = "employees";

	if (exists(directorypath)) {

		for (auto entry : directory_iterator(directorypath)) {
			if (entry.is_regular_file()) {
				//cout << entry.path().filename() << endl;
				allUserPaths.push_back(entry.path());
			}
		}

		for (auto i : allUserPaths) {
			//cout << i << endl;

		}

		ifstream infile(allUserPaths.front());

		if (infile.is_open()) {
			string theline;

			while (getline(infile, theline)) {
				cout << theline << endl;
			}

			infile.close();
		}

	}






}

