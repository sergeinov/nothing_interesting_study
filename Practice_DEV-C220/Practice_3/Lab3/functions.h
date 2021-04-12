#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<type_traits>


constexpr int factorial(int value)      // вычисление факториала числа
{
    //if ( value < 0 )                    // если пользователь ввел отрицательное число
    //{
    //    return 0;                       // возвращаем ноль
    //}
    //if ( value == 0 )                   // если пользователь ввел ноль,
    //{
    //    return 1;                       // возвращаем факториал от нуля
    //}
    //else
    //{
    //    return value * factorial(value - 1); // делаем рекурсию.
    //}

    return ( value <= 1 ) ? 1 : value * factorial(value - 1);
}

/*constexpr*/ long long convertDec(const char* v, long long res)
{
    return ( *v == 0 ) ? res : convertDec(v + 1, ( ( res << 1 ) | ( static_cast< char >( *v ) - '0' ) ));       // конверстация из двоичного представления в десятичное
}

/*constexpr*/ long long operator"" _convertToDec(const char* value)
{
    return convertDec(value, 0LL);
}


//std::string operator"" _toBinStr(unsigned long long value)
//{
//    int i= 0;
//    int mod = 0;
//    long result = 0;
//    for ( i = 0; value > 0; i++ )
//    {
//        mod = value % 2;
//        value = ( value - mod ) / 2;
//        result += mod * pow(( double ) 10, i);
//    }
//
//    std::string str = std::to_string(result);
//    return str;                                 //=> возвращаемое значение не может быть constexpr!
//}

std::string operator"" _toBinStr(unsigned long long value)
{
    std::string str;
    while( value != 0 )
    {
        str = static_cast< char >( ( value & 1 ) + '0' ) + str;
        value >>= 1;
    }
    str = "0b" + str ;
    return str;                                 //=> возвращаемое значение не может быть constexpr!
}


// печать любых последовательностей
template<typename T> void PrintAll(const T& data)
{
    for ( const auto& i : data )
    {
        if constexpr (std::is_pointer_v<std::remove_reference_t<decltype(i)>> )     // если входные данные указатель
        {
            std::cout << *i << " ";
        }
        else
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}


template<typename T, typename A> decltype( auto ) Sum(T& v1, const A& v2)
{
     if constexpr ( std::is_same_v<std::vector<A>, T> )     // если первое значение вектор а второй такого же типа данных
    {
         std::transform(v1.cbegin(), v1.cend(), v1.begin(),     // увеличиваем значение в векторе на значение v2
             [v2](auto& x)
             {
                 return x + v2;
             });
         return v1;
    }
    else
    {
         return v1 + v2;
    }
}


////template<typename T> const typename T::value_type& topAll(const T& adapter)
////{
////	return *(adapter.top());
////}
//


//template<typename A>void PrintAdapter(A adapter)
//{
//    if ( adapter.empty() )
//    {
//        std::cout << "\nEmpty!!!" << std::endl;
//    }
//
//    while ( !adapter.empty() )
//    {
//        if constexpr ( std::is_same<A, std::queue<typename A::value_type, typename A::container_type>> )
//        {
//            std::cout << adapter.front() << " ";
//        } 
//        else //if constexpr( std::is_same<A::value_type, std::priority_queue<A>::value_type>/* && std::is_same<A::value_type, std::stack<A>::value_type>*/  )
//        {
//            std::cout << adapter.top() << " ";
//        }
//        adapter.pop();
//    }
//    std::cout << std::endl;
//}


// возврщает разные типы
template<int N> constexpr auto Smth() 
{
    if constexpr ( N == 1 )
    {
        return 1;
        //std::cout << std::is_scalar<int>::value << std::endl;
    }
    else if constexpr ( N == 2 )
    {
        return 2.2;
        //std::cout << is_floating_point<value>::value << std::endl;
    } 
    else if constexpr ( N == 3 )
    {
        return "abc";
        //std::cout << std::is_scalar<value>::value << std::endl;
    }
    else
    {
        return NULL;
    }    
}