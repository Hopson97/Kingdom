#ifndef COMPONENT_H
#define COMPONENT_H


class Mob;

namespace Component
{

class Component_Base
{
    public:
        Component_Base( Mob* mob )
        :   m_mob ( mob )
        {

        }

        virtual void
        logic ( const float dt ) = 0;

    protected:
        Mob* m_mob;
};

} //Namespace Component

#endif // COMPONENT_H
