#pragma once
#ifndef TUPLE_HDR
#define TUPLE_HDR
#include <iostream>
#include<cmath>

using namespace std;
class Tuple{
    private:
        bool w;
    public:
        double x,y,z;
        Tuple();
        Tuple(double x, double y, double z);
        Tuple(double x, double y, double z, bool w);
        Tuple(const Tuple& source);
        bool isVector() const;
        bool isPoint() const;
        void add(const Tuple& otherTuple);
        void sub(const Tuple& otherTuple);
        void multScalar(double S);
        double magnitude() const;
        void normalize();
        double dot(const Tuple& otherTuple) const;
        void print() const;
        friend ostream& operator<<(ostream& os, const Tuple& T);
        friend Tuple operator+(const Tuple& a, const Tuple& b);
        friend bool operator==(const Tuple& a, const Tuple& b);
        friend Tuple operator-(const Tuple& a, const Tuple& b);
        friend Tuple operator*(const Tuple& a, double s);
        friend Tuple operator*(double s, const Tuple& a);
};



#endif
