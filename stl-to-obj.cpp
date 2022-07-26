#include "iostream"
#include "sstream"
#include "vector"
#include "fstream"

using namespace std;

struct vertex {
    public:
    double x,y,z;
};

vertex strToVertex(const string &str) {
    stringstream ss (str);
    string item;
    vertex vert;
    string strArr[3];
    int i=0;
    while (getline (ss, item,' ')) {
        if(item=="")
            continue;
        else{
            strArr[i++]=item;
        }
    }
    vert.x=stod(strArr[0]);
    vert.y=stod(strArr[1]);
    vert.z=stod(strArr[2]);
    return vert;
}

vector<vertex> readFile(string& file_path) {
    vector<vertex> resultVector;
    vertex v;
    fstream inputFile;
    inputFile.open(file_path,ios::in);
    if(inputFile.is_open()) {
        string temp="";
        string temp1="      vertex";
        // string temp2="  facet";
        while(getline(inputFile,temp)) {
            if(temp.rfind(temp1,0)==0) {        // || temp.rfind(temp2,0)==0) {
                cout<<temp.erase();
                
            v=strToVertex(temp.substr(16));
            resultVector.push_back(v);
            }
        }
        inputFile.close();
    }
    return resultVector;
}

int main(int argc, char *argv[]) {
    string file_path=argv[1];
    vector<vertex> r=readFile(file_path);
    vector<vertex>::iterator ptr;
    for (ptr =r.begin(); ptr <r.end(); ptr++) {
        cout<<ptr->x<<" ";
        cout<<ptr->y<<" ";
        cout<<ptr->z<<endl;
    }
    return EXIT_SUCCESS;
}
