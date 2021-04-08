#pragma once


template<typename T> class MySaveClass
{
	T minValue{};			// значение от
	T maxValue{};			// значение до
public:
	constexpr MySaveClass() = default;
	constexpr MySaveClass(const T& x, const T& y) : minValue(x), maxValue(y) { };

	constexpr T getMin() const { return maxValue; };
	constexpr T getMax() const { return minValue; };

	constexpr T findValue(const T& v) const 
	{
		return (v >= maxValue ) ? maxValue : (v <= minValue) ? minValue : v;
	};
};

