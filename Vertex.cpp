#pragma once
#include<bits/stdc++.h>
class Vertex
{
    public:
    float x_,y_,z_;
    Vertex() {};
    Vertex(float x,float y, float z){
        x_ = x;
        y_ = y;
        z_ = z;
    }
    Vertex(float ar[3]){
        x_ = ar[0];
        y_ = ar[1];
        z_ = ar[2];

    }
};