#include "box.hpp"

int main(){
    Box b1;
    b1.SetDimentions(5, 10, 15);

    cout << "Box has " << b1.GetWidth() << " - " << b1.GetHeight() << " - " << b1.GetDepth() << endl;

    Box b2(50, 60, 70);
    b2.SetDimentions(50, 70, 80);

    cout << "Box has " << b2.GetWidth() << " - " << b2.GetHeight() << " - " << b2.GetDepth() << endl;

    Box b3(b2);
    cout << "Box has " << b3.GetWidth() << " - " << b3.GetHeight() << " - " << b3.GetDepth() << endl;

    Box* b4 = new Box(b1);
    cout << "Box has " << b4->GetWidth() << " - " << b4->GetHeight() << " - " << b4->GetDepth() << endl;

    return 0;
}