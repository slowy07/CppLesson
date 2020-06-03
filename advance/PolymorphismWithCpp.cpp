#include <iostream>
using namespace std;

class Animal
{
    public:
        void animalSound()
        {
            cout<<"sound of animal be different"<<endl;
        }
};

class pig: public Animal
{
    public:
        void animalSound()
        {
            cout<<"pig say: we we we"<<endl;
        }
};

class dog: public Animal
{
    public:
        void animalSound()
        {
            cout<<"dog say: gug gug "<<endl; 
        }
}

int main()
{
    Animal AnimalClass;
    pig AnimalPig;
    dog AnimalDog;
    
    AnimalClass.animalSound();
    AnimalPig.animalSound();
    AnimalDog.animalSound();
    
    return 0;
}
