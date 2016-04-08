#ifndef COMPONENT_H
#define COMPONENT_H

namespace Component
{


class Component_Base
{
    public:
        virtual void
        logic ( const float dt ) = 0;
};

} //Namespace Component

#endif // COMPONENT_H
