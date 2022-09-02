#include <iostream>
#include "color.h"

using namespace std;

color::colorPair color::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        color::MajorColor majorColor = 
            (color::MajorColor)(zeroBasedPairNumber / (color::numberOfMinorColors));
        color::MinorColor minorColor =
            (color::MinorColor)(zeroBasedPairNumber % (color::numberOfMinorColors));
      
        return color::colorPair(majorColor,minorColor);
}

int color::GetPairNumberFromColor(color::MajorColor major, color::MinorColor minor) {
        return major * color::numberOfMinorColors + minor + 1;
}

color::MajorColor color::colorPair::getMajorColor() {
           return majorColor;
}
       
color::MinorColor color::colorPair::getMinorColor() {
           return minorColor;
}
 std::string color::colorPair::ToString() {
                std::string colorPairStr = color::MajorColorNames[majorColor];
                colorPairStr += " ";
                colorPairStr += color::MinorColorNames[minorColor];
                return colorPairStr;
            }


int main() {
    int y = color::GetPairNumberFromColor(color::WHITE,color::ORANGE);
}
