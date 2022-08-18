#pragma once
#include<bits/stdc++.h>
#include "Vertex.cpp"

class FacetNormal
{
    public:
    float i, j, k;
    Vertex first_vertex,second_vertex,third_vertex;
    FacetNormal(){}
    
    FacetNormal(Vertex vertices[4]) {
        i=vertices[0].x_;
        j=vertices[0].y_;
        k=vertices[0].z_;
        first_vertex=vertices[1];
        second_vertex=vertices[2];
        third_vertex=vertices[3];
    }
    FacetNormal(float normal_x_coordinate,float normal_y_coordinate,float normal_z_coordinate){
        i = normal_x_coordinate;
        j = normal_y_coordinate;
        k = normal_z_coordinate;
    }
};