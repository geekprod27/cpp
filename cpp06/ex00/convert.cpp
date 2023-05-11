#include "convert.hpp"
#include <cmath>
#include <limits.h>
#include <float.h>

char toChar(convert *data)
{
	switch (data->type)
	{
	case 0:
		if (!isprint(data->charval))
			throw NonDiplayException();
		else
			return (data->charval);
		break;
	case 1:
		data->charval = static_cast<char>(data->intval);
		if (data->intval > SCHAR_MAX || data->intval < SCHAR_MIN)
			throw ImpossibleException();
		if (!isprint(data->charval))
			throw NonDiplayException();
		else
			return (data->charval);
		break;
	case 2:
		if (std::isnan(data->floatval) || std::isinf(data->floatval) || data->floatval > SCHAR_MAX || data->floatval < SCHAR_MIN)
			throw ImpossibleException();
		else
		{
			data->charval = static_cast<char>(data->floatval);
			if (!isprint(data->charval))
				throw NonDiplayException();
			else
				return (data->charval);
		}
		break;
	case 3:
		if (std::isnan(data->doubleval) || std::isinf(data->doubleval) || data->doubleval > SCHAR_MAX || data->doubleval < SCHAR_MIN)
			throw ImpossibleException();
		else
		{
			data->charval = static_cast<char>(data->doubleval);
			if (!isprint(data->charval))
				throw NonDiplayException();
			else
				return (data->charval);
		}
		break;
	default:
		break;
	}
	return ('0');
}

int toInt(convert *data)
{
	switch (data->type)
	{
	case 0:
		return (static_cast<int>(data->charval));
		break;
	case 1:
		return (data->intval);
		break;
	case 2:
		if (std::isnan(data->floatval) || std::isinf(data->floatval) || data->floatval > static_cast<float>(INT_MAX) || data->floatval < INT_MIN)
			throw ImpossibleException();
		else
			return (static_cast<int>(data->floatval));
		break;
	case 3:
		if (std::isnan(data->doubleval) || std::isinf(data->doubleval) || data->doubleval > INT_MAX || data->doubleval < INT_MIN)
			throw ImpossibleException();
		else
			return (static_cast<int>(data->doubleval));
		break;
	default:
		break;
	}
	return (0);
}

float toFloat(convert *data)
{
	switch (data->type)
	{
	case 0:
		return (static_cast<float>(data->charval));
		break;
	case 1:
		return (static_cast<float>(data->intval));
		break;
	case 2:
		return (data->floatval);
		break;
	case 3:
		if (data->doubleval == INFINITY || std::isnan(data->doubleval)|| data->doubleval == -INFINITY)
			return (static_cast<float>(data->doubleval));
		if (std::isnan(data->doubleval) || std::isinf(data->doubleval) || static_cast<float>(data->doubleval) == -INFINITY || data->doubleval > FLT_MAX)
			throw ImpossibleException();
		else
			return (static_cast<float>(data->doubleval));
		break;
	default:
		break;
	}
	return (0);
}

double toDouble(convert *data)
{
	switch (data->type)
	{
	case 0:
		return (static_cast<double>(data->charval));
		break;
	case 1:
		return (static_cast<double>(data->intval));
		break;
	case 2:
		return (static_cast<double>(data->floatval));
		break;
	case 3:
		return (data->doubleval);
		break;
	default:
		break;
	}
	return (0);
}