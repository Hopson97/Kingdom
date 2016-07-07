#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#include <cmath>

namespace Math
{

    constexpr static double PI = 3.14159265359;

    template < typename T >
    const T toRads ( const T degrees )
    {
        return degrees * ( PI / 180 );
    }

    template < typename T >
    const T toDeg ( const T degrees )
    {
        return degrees * ( 180 / PI );
    }

    template <typename T>
    const float getRot ( T dx, T dy )
    {
        return toDeg ( atan2 ( dy,dx ) ) + 180;
    }

    template <typename T, typename V>
    const T getDistance   ( const sf::Vector2<V>& vect1, const sf::Vector2<V>& vect2)
    {
        int dy = abs ( vect1.y - vect2.y );
        int dx = abs ( vect1.x - vect2.x );

        return  (T)sqrt( pow ( dx, 2 ) + pow ( dy, 2 ) );
    }

} //Namespace Math

#endif // MATHS_H_INCLUDED
