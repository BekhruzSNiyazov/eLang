// this function replaces each r in s1 with s2
char *replace(char *s1, char *r, char *s2)
{
	int length = (int) strlen(s1);
	int rLength = (int) strlen(r);
	int length2 = (int) strlen(s2);

	bool matched = false;

	char *returnString = malloc(1);
	strcpy(returnString, "");

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < rLength; j++)
		{
			if (s1[i + j] == r[j])
			{
				matched = true;
			}
			else
			{
				matched = false;
				break;
			}
		}

		if (matched)
		{
			int j = 0;

			for (; j < i; j++)
			{
				returnString = appendChar(returnString, s1[j]);
			}

			for (j = 0; j < length2; j++)
			{
				returnString = appendChar(returnString, s2[j]);
			}

			int index = i + rLength;
			for (j = index; j < length; j++)
			{
				returnString = appendChar(returnString, s1[j]);
			}
		}
	}

	return returnString;
}