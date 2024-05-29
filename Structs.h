
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