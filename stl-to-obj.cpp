#include "iostream"
#include "sstream"
#include "Vertex.cpp"
#include "vector"
#include "FacetNormal.cpp"
#include "map"
#include "unordered_set"

using namespace std;

// Helper function to convert string to a Vertex object
Vertex strToFloat(string line) {
    stringstream ss;
    ss << line;
    string temp;
    float array[3];
    float flag;
    int index=0;
    while (!ss.eof()) {
        ss>>temp;
        if(stringstream(temp)>>flag)
            array[index++]=flag;
        temp="";
    }
    Vertex resultVertex(array);
    return resultVertex;
}

// Printer function for FacetNormal vector
void print(vector<FacetNormal> facetVector) {
    vector<FacetNormal> ::iterator itr;
    for(itr=facetVector.begin();itr<facetVector.end();++itr){
        cout<< itr->first_vertex.x_<<" "<<itr->second_vertex.y_<<" "<<itr->third_vertex.z_<<endl;
    }
}

// Printer function for Vertex vector
void print(vector<Vertex> vertices) {
    vector<Vertex> ::iterator itr;
    for(itr=vertices.begin();itr<vertices.end();++itr){
        cout<< itr->x_<<" "<<itr->y_<<" "<<itr->z_<<endl;
    }
}

// Printer function for map
void print(map<int,FacetNormal> facemap) {
    ofstream outputfile("output.obj");
    map<int,FacetNormal> ::iterator itr;
    for(itr=facemap.begin();itr!=facemap.end();++itr){
        outputfile<<"*************"<<itr->first<<"*************"<<endl;
        outputfile<<"\t"<<itr->second.i<<" "<<itr->second.j<<" "<<itr->second.k<<endl;
        outputfile<<"\t\t"<<itr->second.first_vertex.x_<<" "<<itr->second.first_vertex.y_<<" "<<itr->second.first_vertex.z_<<endl;
        outputfile<<"\t\t"<<itr->second.second_vertex.x_<<" "<<itr->second.second_vertex.y_<<" "<<itr->second.second_vertex.z_<<endl;
        outputfile<<"\t\t"<<itr->second.third_vertex.x_<<" "<<itr->second.third_vertex.y_<<" "<<itr->second.third_vertex.z_<<endl;
    }
}

//Vectors to Map conversion
map<int,FacetNormal> createMap(vector<Vertex> &vertices) {
    map<int,FacetNormal> resultMap;
    vector<FacetNormal> facetVector;
    for(vector<Vertex> :: iterator verticesitr=vertices.begin();verticesitr!=vertices.end();) {
        Vertex ar[4];
        for(int i=0;i<4;i++,++verticesitr) {
            ar[i]=*verticesitr;
        }
        FacetNormal facet(ar);
        facetVector.push_back(facet);
    }
    //print(facetVector);
    int i=1;
    for(vector<FacetNormal>::iterator itr=facetVector.begin();itr!=facetVector.end();++itr) {
        resultMap.insert(make_pair(i++,*itr));
    }
    print(resultMap);
   return resultMap;
}

// Read STL file in a Map
map<int,FacetNormal> readSTLCoordinates(string const& file_path) {
    ifstream inputFile(file_path);
    vector<Vertex> vertexVector;
    string line;
    while(getline(inputFile,line)) {
        if(line.find("vertex") != string::npos || line.find("facet normal") != string::npos)
            vertexVector.push_back(strToFloat(line));
    }
    map<int,FacetNormal> resultMap;
    resultMap=createMap(vertexVector);    
    return resultMap;
}

// Get set of vertices
vector<Vertex> getVertices(map<int,FacetNormal> facetMap) {
    vector<Vertex> resultVect;
    for(map<int,FacetNormal>::iterator it=facetMap.begin();it!=facetMap.end();++it) {
        resultVect.push_back(it->second.first_vertex);
        resultVect.push_back(it->second.second_vertex);
        resultVect.push_back(it->second.third_vertex);
    }
    return resultVect;
}


// Driver Code
int main()
{
    string file_path="./assets/asciistlcube.stl";
    
    map<int,FacetNormal> resultMap = readSTLCoordinates(file_path);
    vector<Vertex> vertexVect = getVertices(resultMap);
    vector<Vertex>::iterator it;
    auto a = unique(vertexVect.begin(),vertexVect.begin()+36);
    vertexVect.resize(distance(vertexVect.begin(),it));

    print(vertexVect);
    
    return 0;
}
