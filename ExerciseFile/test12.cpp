#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int cards[4]{};
    int hands[4];
    int price[] = {int(2.8), int(3.7), 5, 9};
    char direction[4]{'L', 82, 'U', '\0'};
    char title[] = "ChartGPT is an awesome tool.";
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[1]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;
    // Print the value and address of each element in cards and hands respectively.
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[1] = " << sizeof(cards[1]) << endl;
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[2] = " << sizeof(cards[2]) << endl;
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[3] = " << sizeof(cards[3]) << endl;
    cout << "sizeof(hands) = " << sizeof(hands) << ",sizeof of hands[0] = " << sizeof(hands[0]) << endl;
    cout << "sizeof(hands) = " << sizeof(hands) << ",sizeof of hands[1] = " << sizeof(hands[1]) << endl;
    cout << "sizeof(hands) = " << sizeof(hands) << ",sizeof of hands[2] = " << sizeof(hands[2]) << endl;
    cout << "sizeof(hands) = " << sizeof(hands) << ",sizeof of hands[3] = " << sizeof(hands[3]) << endl;
    return 0;
}