#include "Headers.h"

#define FILEPATH "test/lengthTest/length50/data5.xml"

void traverseGraph(Graph& p, string& curSeq, string seq, int length, int curPos, vector<string>& ans) {
    if (static_cast<int>(curSeq.length()) == length) {
        ans.push_back(curSeq);
        return;
    }
    vertex* curVertex = &p.vertices[seq];
    curVertex->visited = true;
    for (vertex* oligonucleotide : curVertex->adj) {
        if (oligonucleotide->visited == false && curPos >= oligonucleotide->posL && curPos <= oligonucleotide->posH) {
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

bool matchSequence(vector<oligonucleotid> oligonucleotides, string curSeq, int probeLength,  int curPos) {
    for (oligonucleotid seq : oligonucleotides) {
        if (curSeq.compare(curSeq.length(), 0, seq.sequence) && curPos >= seq.posL && curPos <= seq.posH)
            return true;
    }
    return false;
}

void testResult(vector<string> toTest, vector<oligonucleotid> oligonucleotides, int probeLength, int length) {
    for (string seq : toTest) {
        int pos = 1;
        string curSeq = seq.substr(0, probeLength);
        while (pos <= length - probeLength && matchSequence(oligonucleotides, curSeq, probeLength, pos)) {
            pos += 1;
            curSeq = seq.substr(pos, probeLength);
        }
        if (pos == length - probeLength + 1) {
            cout << "Rozwiazanie " << seq << " jest poprawne\n";
        } 
        else {
            cout << "Rozwiazanie " << seq << " nie jest poprawne\n";
        }
    }
}

int main()
{
    vector<oligonucleotid> oligonucleotids;
    FileLoader xml(FILEPATH); //read data from xml file

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    Graph p = Graph(xml.seq); //generate graph
    vector<string> solution;
    traverseGraph(p, xml.start, xml.start, xml.length, 1, solution); //DFS

    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    for (string seq : solution) {
       cout << seq << endl;
       cout << "===================================================" << endl;
    }

    std::cout << "Czas wykonywania = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Czas wykonywania = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << "Czas wykonywania = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;

    testResult(solution, xml.seq, xml.start.length(), xml.length);
}