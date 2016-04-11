#ifndef COMPONENT_H
#define COMPONENT_H


class Mob;

namespace Component
{

class Component_Base
{
    public:
        Component_Base()
        {

        }

        virtual void
        logic ( const float dt ) = 0;

    private:
        Mob* mob;
};

} //Namespace Component

#endif // COMPONENT_H
