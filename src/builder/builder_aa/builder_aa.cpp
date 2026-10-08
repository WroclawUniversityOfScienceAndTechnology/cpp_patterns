#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Field
{
    private:
    string name, type;
    public:
    Field(const string name, const string type) : name{name}, type{type}
    {
    }

    friend ostream& operator<<(ostream& os, const Field& obj)
    {
        return os << obj.type << " " << obj.name << ";";
    }
};

class Class
{
    public:
    string class_name;
    vector<Field> fields;

    friend ostream& operator<<(ostream& os, const Class& obj)
    {
        os << "class " << obj.class_name << " {\n";

        for(auto field : obj.fields)
        {
            os << "  " << field << "\n";
        }
        return os << "};\n";
    }
};

/**
 * @brief This pattern is used eg. i reactive programing to perform pipe-alike operation 
 */
class ClassBuilder
{
    vector<Class> the_classes;
    uint16_t class_pointer;

    public:
    ClassBuilder(const string& class_name) : class_pointer{0}
    {
        the_classes.emplace_back(Class());
        the_classes.at(class_pointer).class_name = class_name;    
    }

    ClassBuilder& add_field(const string& name, const string& type)
    {
        the_classes.at(class_pointer).fields.emplace_back(Field(name, type));
        return *this;
    }

    ClassBuilder& add_class(const string& class_name)
    {
        Class sub_class("sub-class");
        the_classes.emplace_back(sub_class);
        class_pointer++;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const ClassBuilder& obj)
    {
        for(auto i : obj.the_classes)
        {
            os << i;
        }
        return os;
    }
};

int main()
{
    ClassBuilder class_builder("root");

    class_builder.add_field("variable1", "field1").add_field("variable2", "field2");
    class_builder.add_field("variable3", "field3");

    class_builder.add_class("class2");
    class_builder.add_field("var1", "fi1");

    cout << class_builder << endl;
    return 0;
}