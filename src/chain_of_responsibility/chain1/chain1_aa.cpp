#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum Property{attact, defence, count};

struct Creature
{
    string name;
    int property[count];
    Creature(const string& name, const int attact, const int defence) : name{name}
    {
        property[Property::attact] = attact;
        property[Property::defence] = defence;
    }
    
    friend ostream &operator<<(ostream& os, const Creature& obj)
    {
        os << "Name: " << obj.name 
           << " attact:" << obj.property[Property::attact]
           << " defence:" << obj.property[Property::defence];

        return os;
    }
};

class CreatureModifier
{
    shared_ptr<CreatureModifier> next{nullptr};
    protected:
        Creature &creature;
    public:
        CreatureModifier(Creature &creature) : creature{creature}
        {
        }

        void add(shared_ptr<CreatureModifier> cm)
        {
            if(next)
            {
                next->add(cm);
            }
            else
            {
                next = cm;
            }
        }
        virtual void handle()
        {
            if(next)
            {
                next->handle();
            }
        }
};

class DoubleAttactModifier : public CreatureModifier
{
    public:
        DoubleAttactModifier(Creature &creature) : CreatureModifier{creature}
        {}
        void handle() override
        {
            creature.property[Property::attact] *= 2;
            CreatureModifier::handle();
        }
};

class AddDefenceModifier : public CreatureModifier
{
    public:
        AddDefenceModifier(Creature &creature) : CreatureModifier{creature}
        {}
        void handle() override
        {
            creature.property[Property::defence] += 2;
            CreatureModifier::handle();
        }
};

// int main()
// {
//     Creature goblin = Creature("Goblin", 1, 1);
//     CreatureModifier root(goblin);
//     shared_ptr<DoubleAttactModifier> modifier1 = make_shared<DoubleAttactModifier>(goblin);
//     shared_ptr<AddDefenceModifier> modifier2 = make_shared<AddDefenceModifier>(goblin);
//     shared_ptr<DoubleAttactModifier> modifier3 = make_shared<DoubleAttactModifier>(goblin);

//     root.add(modifier1);
//     root.add(modifier2);
//     root.add(modifier3);

//     root.handle();

//     cout << goblin << endl;
//     return 0;
// }