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

bool isEnd(char *string, int position)
{
	return ((string[position] == '\0') || ((string[position] == '+') && (string[position - 1] != 'E')) || ((string[position] == '-') && (string[position - 1] != 'E')) || (string[position] == '*') || (string[position] == '/') || (string[position] == '(') || (string[position] == ')'));
}

bool isE(char symbol)
{
	return symbol == 'E';
}

bool floatNS::isFloat(char *string, int &currentPosition)
{
	enum states { start, integer, dot, afterDot, e, signAfterE, numberAferE, finish, fail };
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
						  state = fail;

					  break;
		}

		case integer:
		{
						++currentPosition;

						if (isNumber(string[currentPosition]))
						{
							state = integer;
							break;
						}

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

						if (isEnd(string, currentPosition))
						{
							state = finish;
							break;
						}

						state = fail;
						break;
		}

		case dot:
		{
					++currentPosition;

					if (isNumber(string[currentPosition]))
					{
						state = afterDot;
						break;
					}

					state = fail;
					break;
		}

		case afterDot:
		{
						 ++currentPosition;

						 if (isNumber(string[currentPosition]))
						 	 break;
						 
						 if (isEnd(string, currentPosition))
						 {
							 state = finish;
							 break;
						 }

						 if (isE(string[currentPosition]))
						 {
							 state = e;
							 break;
						 }

						 state = fail;
						 break;
		}

		case e:
		{
				  ++currentPosition;

				  if (isSign(string[currentPosition]))
				  {
					  state = finish;
					  break;
				  }

				 if (isNumber(string[currentPosition]))
				  {
					  state = numberAferE;
					  break;
				  }

				  state = fail;
				  break;
		}

		case numberAferE:
		{
							++currentPosition;

							if (isNumber(string[currentPosition]))
								break;
							
							if (isEnd(string, currentPosition))
							{
								state = finish;
								break;
							}

							state = fail;
							break;
		}

		case finish:
		{
					   return true;
		}

		case fail:
		{
					 return false;
		}

		}
	}
}

