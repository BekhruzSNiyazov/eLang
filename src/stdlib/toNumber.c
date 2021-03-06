// this function converts the given string to a number
double toNumber(char *string)
{
    if (numberable(trim(string)))
	{
		double number;
		char *ptr;
		number = strtod(trim(string), &ptr);
		return number;
	}

	char error[] = "Couldn't convert \"";
	strcat(error, string);
	strcat(error, "\" to a Number");
	raiseError(INV, error, LINES.array[lineNumber - 1], lineNumber, FILENAME);
	
	return 0;
}
