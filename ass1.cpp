//
//  main.cpp
//  Assignment1
//
//  Created by Eddrick Liu on 1/14/18.
//  Copyright © 2018 Eddrick Liu. All rights reserved.
//

#include <iostream>
#include "turtleprogram.h"

using namespace std;

/*
 Comprehensive tests for the Turtle Program, tests all required
 points in the assignment
 */
int main(/*int argc, const char * argv[]*/) {
    TurtleProgram tp1;
    cout << "tp1: " << tp1 << endl;
    TurtleProgram tp2("F", "10");
    cout << "tp2: " << tp2 << endl;
    TurtleProgram tp3("R", "90");
    cout << "tp3: " << tp3 << endl;
    tp1 = tp2 + tp3;
    cout << "tp1 now as tp2+tp3: " << tp1 << endl;
    tp1 = tp2 * 3;
    cout << "tp1 now as tp2 * 3: " << tp1 << endl;
    TurtleProgram tp4 (tp1);
    cout << "tp4 is a copy of tp1: " << tp4 << endl;
    TurtleProgram tp5("F", "10");
    cout << "tp5: " << tp5 << endl;
    cout << boolalpha;
    cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
    cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
    cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
    tp2.setIndex(0, "R");
    tp2.setIndex(1, "90");
    cout << "tp2 after 2 calls to setindex: " << tp2 << endl;
    cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
    tp1.setIndex(0,"R");
    cout << "Check to see if tp4 changes after tp1 changes" << tp4 << endl;
    // need to write additional tests for += *=
    TurtleProgram tp6 ("L", "30");
    tp6 += tp1;
    cout << "tp6 += tp1: " << tp6 << endl;
    tp6 *= 2;
    cout << "tp6 *= 2: " << tp6 << endl;
    cout << "done." << endl;
        return 0;
}
