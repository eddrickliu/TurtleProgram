//
//  TurtleProgram.h
//  Ass #1
//
//  Created by Eddrick Liu on 1/8/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#ifndef turtleprogram_h
#define turtleprogram_h

#include <iostream>
#include <string>

using namespace std;

class TurtleProgram{
    friend ostream& operator<<(ostream &out, const TurtleProgram &tur);
private:
    string* dataItem = NULL;
    int length = 0;
public:
    //Constructors/Destructors
    TurtleProgram();
    TurtleProgram(string direction, string length);
    TurtleProgram(const TurtleProgram &tur);
    ~TurtleProgram();
    
    int getLength() const;
    string getIndex(int index) const;
    bool setIndex(int index, string value);
    
    //Operator Overloads
    bool operator==(const TurtleProgram &tur) const;
    bool operator!=(const TurtleProgram &tur) const;
    TurtleProgram& operator=(const TurtleProgram &tur);
    TurtleProgram operator+(const TurtleProgram &tur) const;
    TurtleProgram& operator+=(const TurtleProgram &tur);
    TurtleProgram operator*( int multiplier)const;
    TurtleProgram& operator*=( int multiplier);
    
    
};
#endif /* turtleprogram_h */

