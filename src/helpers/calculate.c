/// \param numbers A pointer to an array of variables of type double
/// \param currentNumberString A number or expression of type char *
/// \param numberOfNumbers Number of numbers in array of numbers numbers
/// \author Bekhruz Niyazov
void addNumber(double *numbers, char *currentNumberString, int *numberOfNumbers)
{
	currentNumberString = trim(currentNumberString);
	currentNumberString = getValue(currentNumberString);

	double number = toNumber(currentNumberString);

	numbers = realloc(numbers, ++*numberOfNumbers * sizeof(double));
	numbers[*numberOfNumbers - 1] = number;
}

/// \param expression An expression that needs to be calculated of type char *
/// \return Calculated result of the given expression of type double
/// \author Bekhruz Niyazov
double calculate(char *expression)
{
	size_t length = strlen(expression);

	char operators[count('+', expression) + count('-', expression) + count('*', expression) + count('/', expression)];

	int numberOfOperators = 0, numberOfNumbers = 0;

	double *numbers = calloc(1, sizeof(double));

	bool skipNext = false;

	char *currentNumberString = strdup("");

	int wait = 0;

	for (ui i = 0; i < length; i++)
	{
		char currentChar = expression[i];

		if (currentChar != '+' && currentChar != '-' && currentChar != '*' && currentChar != '/')
		{
			currentNumberString = appendChar(currentNumberString, currentChar);

			if (!insideQuotes((int) i, expression))
			{
				if (currentChar == '(')
				{
					wait++;
				}

				if (currentChar == ')')
				{
					if (wait)
						wait--;
					else
						skipNext = false;
				}
			}
		}

		else
		{
			if (!skipNext)
			{
				operators[numberOfOperators++] = currentChar;

				currentNumberString = strdup(trim(currentNumberString));

				if (numberOfNumbers > 0) currentNumberString = appendChar(currentNumberString, ')');

				addNumber(numbers, currentNumberString, &numberOfNumbers);
				free(currentNumberString);
				currentNumberString = strdup("");

				skipNext = true;
			}
			else
			{
				currentNumberString = appendChar(currentNumberString, currentChar);
			}
		}
	}

	addNumber(numbers, currentNumberString, &numberOfNumbers);
	free(currentNumberString);

	double returnValue = 0;

	for (int i = 0; i < numberOfOperators; i++)
	{
		switch (operators[i])
		{
			case '+':
				returnValue += numbers[i ? i + 1 : 0] + numbers[i ? i + 2 : 1];
				break;
			case '-':
				returnValue += numbers[i ? i + 1 : 0] - numbers[i ? i + 2 : 1];
				break;
			case '*':
				returnValue += numbers[i ? i + 1 : 0] * numbers[i ? i + 2 : 1];
				break;
			case '/':
				returnValue += numbers[i ? i + 1 : 0] / numbers[i ? i + 2 : 1];
				break;
		}
	}

	free(numbers);

	return returnValue;
}
