
bool isCharacter(const char Character)
{
	return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
	//Checks if a Character is a Valid A-Z, a-z Character, based on the ascii value
}
bool isNumber(const char Character)
{
	return ( Character >= '0' && Character <= '9');
	//Checks if a Character is a Valid 0-9 Number, based on the ascii value
}
bool isValidEmailAddress(const char * EmailAddress)
{
	if(!EmailAddress) // If cannot read the Email Address...
		return 0;
	if(!isCharacter(EmailAddress[0])) // If the First character is not A-Z, a-z
		return 0;
	int AtOffset = -1;
	int DotOffset = -1;
	unsigned int Length = strlen(EmailAddress); // Length = StringLength (strlen) of EmailAddress
	for(unsigned int i = 0; i < Length; i++)
	{
		if(EmailAddress[i] == '@') // If one of the characters is @, store it's position in AtOffset
			AtOffset = (int)i;
		else if(EmailAddress[i] == '.') // Same, but with the dot
			DotOffset = (int)i;
	}
	if(AtOffset == -1 || DotOffset == -1) // If cannot find a Dot or a @
		return 0;
	if(AtOffset > DotOffset) // If the @ is after the Dot
		return 0;
	return !(DotOffset >= ((int)Length-1)); //Chech there is some other letters after the Dot
}

