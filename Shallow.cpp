// Shallow copy
#include <iostream>
using std::cout, std::endl, std::cin;
class Car
{
    private:
    int* speed;
    public:
    Car(int s)
    {
        speed = new int(s);
    }
    Car(const Car& c)
    {
        speed = c.speed;
        // issue is the copy of address here
    }
    ~Car()
    {
     //   delete speed; // if removed then we will get error/exception double deletion etc.
    }
    void setSpeed(int s)
    {
        *speed = s;
    }
    int getSpeed() const
    {
        return *speed;
    }
};

int main()
{
    Car car(20), sportsCar(car);
    cout << car.getSpeed() << endl;
    cout << sportsCar.getSpeed() << endl;
    sportsCar.setSpeed(30);
    cout << car.getSpeed() << endl;
    cout << sportsCar.getSpeed() << endl;
    return 0;
}
