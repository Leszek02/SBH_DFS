#include "FileLoader.h"

FileLoader::FileLoader(string xml_path) {
	fstream file;
	file.open(xml_path, ios::in);
	if (file.is_open()) {
		string line, found;
		int endPos;
		while (getline(file, line) && line.empty()) {};

		int pos = line.find("length=");
		if (pos != string::npos) {
			pos += 8;
			endPos = line.find('"', pos);
			string lengthStr = line.substr(pos, endPos - pos);
			length = std::stoi(lengthStr);
		}

		pos = line.find("start=");
		if (pos != string::npos) {
			pos += 7;
			endPos = line.find('"', pos);
			start = line.substr(pos, endPos - pos);
		}

		getline(file, line);
		while (getline(file, line)) {
			if (line.find("cell") == string::npos) continue;
			oligonucleotid olig;
			pos = line.find("posL=");
			if (pos != string::npos) {
				pos += 6;
				endPos = line.find('"', pos);
				found = line.substr(pos, endPos - pos);
				olig.posL = std::stoi(found);
			}

			pos = line.find("posH=");
			if (pos != string::npos) {
				pos += 6;
				endPos = line.find('"', pos);
				found = line.substr(pos, endPos - pos);
				olig.posH = std::stoi(found);
			}

			pos = line.find(">");
			if (pos != string::npos) {
				pos += 1;
				endPos = line.find('<', pos);
				olig.sequence = line.substr(pos, endPos - pos);
			}
			seq.push_back(olig);
		}
	}
	else {
		cerr << "There was a problem with opening a file" << endl;
	}
}
