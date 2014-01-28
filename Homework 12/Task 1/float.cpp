#include "float.h"

using namespace floatNS;

bool isSign(char symbol)
{
	return ((symbol == '+') || (symbol == '-'));
}

bool isNumber(char symbol)
{
	return ((symbol >= '0') && (symbol <= '9'));
}

bool isDot(char symbol)
{
	return (symbol == '.');
}

bool isE(char symbol)
{
	return symbol == 'E';
}

bool floatNS::isFloat(char *string, int &currentPosition)
{
	enum states { start, integer, dot, afterDot, e, signAfterE, numberAferE };
	states state = start;

	--currentPosition;
	
	while (true)
	{
		switch (state)
		{
		case start:
		{
					  ++currentPosition;

					  if (isSign(string[currentPosition]) || (isNumber(string[currentPosition])))
						  state = integer;
					  else
						  return false;

					  break;
		}

		case integer:
		{
						++currentPosition;

						if (isNumber(string[currentPosition]))
							break;

						if (isDot(string[currentPosition]))
						{
							state = dot;
							break;
						}

						if (isE(string[currentPosition]))
						{
							state = e;
							break;
						}

						return true;
		}

		case dot:
		{
					++currentPosition;

					if (isNumber(string[currentPosition]))
					{
						state = afterDot;
						break;
					}

					return false;
		}

		case afterDot:
		{
						 ++currentPosition;

						 if (isNumber(string[currentPosition]))
							 break;

						 if (isE(string[currentPosition]))
						 {
							 state = e;
							 break;
						 }

						 return true;
		}

		case e:
		{
				  ++currentPosition;

				  if (isSign(string[currentPosition]))
				  {
					  state = signAfterE;
					  break;
				  }

				  if (isNumber(string[currentPosition]))
				  {
					  state = numberAferE;
					  break;
				  }

				  return false;
		}

		case signAfterE:
		{
						   ++currentPosition;

						   if (isNumber(string[currentPosition]))
						   {
							   state = numberAferE;
							   break;
						   }

						   return false;
		}

		case numberAferE:
		{
							++currentPosition;

							if (isNumber(string[currentPosition]))
								break;

							return true;
		}

		}
	}
}