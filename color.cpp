#include <iostream>
#include "color.h"

using namespace std;

TelCoColorCoder::colorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        TelCoColorCoder::MajorColor majorColor = 
            (TelCoColorCoder::MajorColor)(zeroBasedPairNumber / (TelCoColorCoder::numberOfMinorColors));
        TelCoColorCoder::MinorColor minorColor =
            (TelCoColorCoder::MinorColor)(zeroBasedPairNumber % (TelCoColorCoder::numberOfMinorColors));
      
        return TelCoColorCoder::colorPair(majorColor,minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor) {
        return major * TelCoColorCoder::numberOfMinorColors + minor + 1;
}

TelCoColorCoder::MajorColor TelCoColorCoder::colorPair::getMajorColor() {
           return majorColor;
}
       
TelCoColorCoder::MinorColor TelCoColorCoder::colorPair::getMinorColor() {
           return minorColor;
}
 std::string TelCoColorCoder::colorPair::ToString() {
                std::string colorPairStr = TelCoColorCoder::MajorColorNames[majorColor];
                colorPairStr += " ";
                colorPairStr += TelCoColorCoder::MinorColorNames[minorColor];
                return colorPairStr;
            }


