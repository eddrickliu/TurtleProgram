//
//  TurtleProgram.cpp
//  Ass #1
//
//  Created by Eddrick Liu on 1/8/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include "turtleprogram.h"

/*
 Empty Constructor for when no arguments are added, automatically assumes the
 array will be at 0 size for the time being.
 */
TurtleProgram::TurtleProgram(){
    dataItem = new string[0];
    length = 0;
}

/*
 Argument Constructor for when 2 arguments are added, after passing validation tests,
 the array is set to a size of 2 and then the arguments are set into the array
 */
TurtleProgram::TurtleProgram(string dir, string len){
    if ((dir == "F" || dir == "R" ||dir == "L" || dir == "B")){
        dataItem = new string[2];
        dataItem[0] = dir;
        dataItem[1] = len;
        length = 2;
    }
    return;
}

/*
 Copy Constructor for TurtleProgram, goes through the whole array and
 copies each item individually. Takes in another turtle program
 */
TurtleProgram::TurtleProgram(const TurtleProgram &tur){
    dataItem = new string[tur.getLength()];
    for (int i = 0; i < tur.getLength(); i++){
        dataItem[i] = tur.dataItem[i];
    }
    length = tur.getLength();
    
}

/*
 Deconstructor for Turtle Program, deletes the dataItem array.
 */
TurtleProgram::~TurtleProgram(){
    delete [] dataItem;
}

/*
 Method to get the length of this turtle program, returning an
 int to represent that.
 */
int TurtleProgram::getLength() const{
    return length;
}

/*
 Method to get a string given a specific index, takes in
 an index for the position and returns a string for the string
 in that position.
 */
string TurtleProgram::getIndex(int index) const{
    if ( index >= length || index < 0){
        //return false;
        return NULL;
    }
    string retValue = dataItem[index];
    return retValue;
}

/*
 Method to set the index of a particular value inside the array.
 Takes both the index and the string and returns a true or false
 indicating if settable
 */
bool TurtleProgram::setIndex(int index, string value){
    if ( index >= length || index < 0){
        return false;
    }
    dataItem[index] = value;
    return true;
}



/*
 Operator overload for == to determine whether two Turtle programs are the same.
 Takes in another turtle program to compare
 */
bool TurtleProgram::operator==(const TurtleProgram &tur) const
{
    if (this->getLength() != tur.getLength()){
        return false;
    }
    for ( int i = 0; i < tur.getLength(); i++){
        if(this->dataItem[i] != tur.dataItem[i]){
            return false;
        }
    }
    return true;
}

/*
 Operator overload for != to determine whether two Turtle programs are different.
 Takes in another turtle program to compare
 */
bool TurtleProgram::operator!=(const TurtleProgram &tur) const
{
    if (this->getLength() != tur.getLength()){
        return true;
    }
    for ( int i = 0; i < tur.getLength(); i++){
        if(this->dataItem[i] != tur.dataItem[i]){
            return true;
        }
    }
    return false;
}

/*
 Operator Overload for =, to set this turtle program to another turtle program,
 sort of like how the copy constructor works but without having to worry about
 the initialization of the array
 */
TurtleProgram& TurtleProgram::operator=(const TurtleProgram &tur)
{
    string* temp = new string[tur.getLength()];
    for (int i = 0; i < tur.getLength(); i++){
        temp[i] = tur.dataItem[i];
    }
    length = tur.getLength();
    delete [] this->dataItem;
    this->dataItem = temp;
    return *this;
}

/*
 Operator overload for +, to add two turtle programs together, this method takes
 in another turtle to add. and then returns the new added together value
 */
TurtleProgram TurtleProgram::operator+(const TurtleProgram &tur) const
{
    TurtleProgram result = *this;
    result += tur;
    return result;
}

/*
 Operator overload for +=, to add two turtle programs together, this method takes
 in another turtle to add. and then changes the data of this turtle program.  
 */
TurtleProgram& TurtleProgram::operator+=(const TurtleProgram &tur)
{
    string *temp = new string[length+tur.getLength()];
    for (int i = 0; i < length; i++){
        temp[i] = dataItem[i];
    }
    int j = 0;
    for (int i = length; i < (length+tur.getLength()); i++){
        temp[i] = tur.dataItem[j++];
    }
    length += tur.getLength();
    delete [] this->dataItem;
    this->dataItem = temp;
    return *this;
}

/*
 Operator overload for *=, takes a turtleprogram and times it by
 an integer, which will repeat it however many times it is multiplied by,
 and then return the new data.
 */
TurtleProgram TurtleProgram::operator*( int multiplier)const{
    TurtleProgram result = *this;
    result *= multiplier;
    return result;
}

/*
 Operator overload for *=, takes a turtleprogram and times it by
 an integer, which will repeat it however many times it is multiplied by,
 and then change this turtle programs data.
 */
TurtleProgram& TurtleProgram::operator*=( int multiplier){
    string* temp = new string[length*multiplier];
    int j = 0;; //Original indexes of small array
    for (int i = 0; i < length*multiplier; i++){
        if(j >= getLength()){
            j = 0;
        }
        temp[i] = dataItem[j++];
    }
    length *= multiplier;
    delete[] this->dataItem;
    this->dataItem = temp;
    return *this;
}

/*
 Overator overload for << to output a string to console when called.
 */
ostream& operator<<(ostream &out, const TurtleProgram &tur)
{
    out << "[ ";
    for(int i = 0; i < tur.getLength(); i ++){
        out << tur.dataItem[i] << " " ;
    }
    out << "]";
    return out;
}
