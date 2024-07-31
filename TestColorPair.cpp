#include <iostream>
#include"TestColorPair.h"

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert_msg(colorPair.getMajor() == expectedMajor,"Mismatch in the Major color");
    assert_msg(colorPair.getMinor() == expectedMinor,"Mismatch in the Minor color");
}

void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert_msg(pairNumber == expectedPairNumber,"Mismatch in pair number");
}

void TestPrintReferenceManual()
{
    // Redirect std::cout to a string stream
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    // Call the function to test
    TelCoColorCoder::PrintReferenceManual();

    // Restore original std::cout buffer
    std::cout.rdbuf(p_cout_streambuf);

    // Get the output as a string
    std::string output = oss.str();

    // Expected output
    std::string expectedOutput =
        "Color Pair Reference Manual\n"
        "1 White Blue\n"
        "2 White Orange\n"
        "3 White Green\n"
        "4 White Brown\n"
        "5 White Slate\n"
        "6 Red Blue\n"
        "7 Red Orange\n"
        "8 Red Green\n"
        "9 Red Brown\n"
        "10 Red Slate\n"
        "11 Black Blue\n"
        "12 Black Orange\n"
        "13 Black Green\n"
        "14 Black Brown\n"
        "15 Black Slate\n"
        "16 Yellow Blue\n"
        "17 Yellow Orange\n"
        "18 Yellow Green\n"
        "19 Yellow Brown\n"
        "20 Yellow Slate\n"
        "21 Violet Blue\n"
        "22 Violet Orange\n"
        "23 Violet Green\n"
        "24 Violet Brown\n"
        "25 Violet Slate\n";

    // Perform the assertion
    assert_msg(output == expectedOutput,"The reference manual is not as expected.");
}