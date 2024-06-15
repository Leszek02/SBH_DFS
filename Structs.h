#pragma once

#ifndef STRUCTS_H
#define STRUCTS_H
struct vertex {
    string name;
    int posL;
    int posH;
    vector<vertex*> adj;
    bool visited = false;
};

struct oligonucleotid {
    string sequence;
    int posL;
    int posH;
};

#endif