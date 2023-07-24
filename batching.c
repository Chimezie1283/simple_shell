#include "header.h"
/**
 * batching - function that treats batch
 * @argv: pointer to array of arguments
 * Return: void
 */
void batching(char *argv[])
{
	char *input = NULL;
	size_t token = 0;
	ssize_t wrn;
/**	int exitstatus;**/
	/**int status;**/

	/**wrn = 0;**/
	while ((wrn = getline(&input, &token, stdin)) != -1)
	{
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else
		{
			/**exitstatus = **/
			execute_input(input, argv[0]);
		/**	exit(exitstatus);**/
		}
	}
	free(input);
}
