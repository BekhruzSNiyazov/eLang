// this function returns an array of lines generated by parsing the provided code
strArray splitIntoLines(char *code)
{
	strArray lines;
	char **array = calloc(count('\n', code), sizeof(char *));

	ui numberOfLines = 0;
	char *ln = malloc(1);
	strcpy(ln, "");
	for (ui i = 0, l = (int) strlen(code); i < l; i++)
	{
		if (code[i] != '\n')
		{
			ln = appendChar(ln, code[i]);
		}

		if (code[i] == '\n' || i == l - 1)
		{
			array[numberOfLines] = strdup(ln);
			numberOfLines++;
			free(ln);
			ln = malloc(1);
			strcpy(ln, "");
		}
	}
	free(ln);

	lines.array = array;
	lines.length = numberOfLines;

	return lines;
}