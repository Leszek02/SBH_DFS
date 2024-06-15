#include "Graph.h"

bool perfectMatch(const oligonucleotid seq1, const oligonucleotid seq2) {
    int length = seq1.sequence.length();
    int i = 0;
    while (seq1.sequence[i + 1] == seq2.sequence[i]) {
        i++;
        if (i == length - 1)
            return true;
    }
    return false;
}


void Graph::addVertex(const oligonucleotid olig) {
    vertex v;
    v.name = olig.sequence;
    v.posL = olig.posL;
    v.posH = olig.posH;
    v.visited = false;
    vertices[olig.sequence] = v;
}


void Graph::addEdge(const string from, const string to) {
    vertices[from].adj.push_back(&vertices[to]);
}


Graph::Graph (vector<oligonucleotid> oligonucleotides) {
    for (oligonucleotid olig : oligonucleotides) {
        addVertex(olig);
    }
    int length = oligonucleotides.size();
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            if (i != j && perfectMatch(oligonucleotides[i], oligonucleotides[j])) {
                addEdge(oligonucleotides[i].sequence, oligonucleotides[j].sequence);
                count++;
            }
        }
    }
}