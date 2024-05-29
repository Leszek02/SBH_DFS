#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Headers.h"

class Graph {
public:
    map<string, vertex> vertices;
    Graph(vector<oligonucleotid> oligonucleotides);
    void addVertex(const oligonucleotid olig);
    void addEdge(const string from, const string to);
};

#endif