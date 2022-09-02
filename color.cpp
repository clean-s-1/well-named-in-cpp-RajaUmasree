#include <iostream>
#include "color.h"
#include <assert.h>

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

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::colorPair colorPairobj =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPairobj.ToString() << std::endl;
    assert(colorPairobj.getMajorColor() == expectedMajor);
    assert(colorPairobj.getMinorColor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    return 0;
}

