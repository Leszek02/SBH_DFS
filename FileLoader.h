#pragma once
#ifndef FILELOAD_H
#define FILELOAD_H

#include "Headers.h"

class FileLoader
{
public:
	vector<oligonucleotid> seq;
	int length;
	string start;

	FileLoader(string xml_path);
};

#endif