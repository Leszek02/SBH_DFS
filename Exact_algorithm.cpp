#include "Headers.h"

#define FILEPATH "data/data5.xml"

void traverseGraph(Graph& p, string& curSeq, string seq, int length, int curPos, vector<string>& ans) {
    if (static_cast<int>(curSeq.length()) == length) {
        ans.push_back(curSeq);
        return;
    }
    vertex* curVertex = &p.vertices[seq];
    curVertex->visited = true;
    for (vertex* oligonucleotide : curVertex->adj) {
        if (oligonucleotide->visited == false && oligonucleotide->posL <= curPos && oligonucleotide->posH >= curPos) {
            curSeq.push_back(oligonucleotide->name[oligonucleotide->name.size() - 1]);
            curPos++;
            traverseGraph(p, curSeq, oligonucleotide->name, length, curPos, ans);
            curPos--;
            curSeq.pop_back();
        }
    }
    curVertex->visited = false;
    return;
}

int main()
{
    vector<oligonucleotid> oligonucleotids;
    FileLoader xml(FILEPATH); //read data from xml file
    Graph p = Graph(xml.seq); //generate graph
    vector<string> solution;

    traverseGraph(p, xml.start, xml.start, xml.length, 1, solution); //DFS
    for (string seq : solution) {
        cout << seq << endl;
    }

}