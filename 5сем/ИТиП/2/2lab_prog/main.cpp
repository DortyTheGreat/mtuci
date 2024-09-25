#include <iostream>

using namespace std;

/// Лев, дельфин, птица, синица, животное

class animal{
public:
    virtual void make_sound() = 0;
    virtual bool can_fly() = 0;

    double weight;

};

class bird : public animal{
    bool can_fly(){return true;}
};

class titmouse : public bird{
    void make_sound(){cout << "pin-pin-pin" << endl;}
};

class lion : public animal{
    void make_sound(){cout << "roar" << endl;}
    bool can_fly(){return false;}
};

class dolphin : public animal{
    void make_sound(){cout << "viiii" << endl;}
    bool can_fly(){return false;}
};

int main()
{
    animal* an = new titmouse();
    an->make_sound();
    cout << "Can Fly: " << an->can_fly() << endl << endl;

    an = new lion();
    an->make_sound();
    cout << "Can Fly: " << an->can_fly() << endl << endl;

    an = new dolphin();
    an->make_sound();
    cout << "Can Fly: " << an->can_fly() << endl << endl;

    return 0;
}
