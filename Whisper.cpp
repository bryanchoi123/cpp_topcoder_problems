#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

class Whisper
{
public:
	string toWhom(vector<string> usernames, string typed)
	{
        if(typed.length() < 5 )
            return "not a whisper";
        
		// check to see if starts with "/msg"
		if (caseInsensitiveCompare(typed.substr(0, 4), "/msg") != 0)
			return "not a whisper";

		// index in usernames
		int usernameIndex = -1;

		for (int i = 5; i < typed.length(); i++)
		{
			// if I hit a space
			if (typed[i] == ' ')
			{
				string name = typed.substr(5, i - 5);

				for (int j = 0; j < usernames.size(); j++)
					if (caseInsensitiveCompare(name, usernames[j]) == 0)
					{
						usernameIndex = j;
						break;
					}
			}
		}

		// couldn't find the username
		if (usernameIndex == -1)
			return "user is not logged in";
		else
			return usernames[usernameIndex];
	}

private:
	int caseInsensitiveCompare(string first, string second)
	{
		if (first.length() != second.length())
			return first.length() - second.length();

		for (int i = 0; i < first.length(); i++)
		{
			char firstChar = tolower(first[i]);
			char otherChar = tolower(second[i]);

			if (firstChar != otherChar)
				return firstChar - otherChar;
		}

		return 0;
	}
};