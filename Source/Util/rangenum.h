#ifndef RANGENUM_H
#define RANGENUM_H

template < typename T >
struct Ranged_Num
{
    public:
        Ranged_Num( const T low, const T high, const T initial )
        :   m_lowVal    ( low )
        ,   m_highVal   ( high )
        {
            if ( high < low || low > high)
                throw std::runtime_error ( "The 'high' is less than 'low', invalid.");
        }

        void
        operator =( const T other )
        {
            if ( other > m_highVal ) m_currVal = m_highVal;
            else if ( other < m_lowVal )  m_currVal = m_lowVal;
            else m_currVal = other;

        }

        const T
        getVal  () { return m_currVal; }

    private:
        T m_lowVal;
        T m_highVal;
        T m_currVal;
};

#endif // RANGENUM_H
