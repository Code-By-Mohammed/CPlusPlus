// Deep copy
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
        speed = new int(*c.speed);
        // we create separte and store the resource
    }
    ~Car()
    {
        delete speed; 
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
