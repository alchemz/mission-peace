bool is_valid_number(const std::string& number)
{
    static const std::string AllowedChars = "0123456789";
    for(auto numberChar = number.begin(); 
        numberChar != number.end(); ++numberChar)

        if(AllowedChars.end() == std::find(
            AllowedChars.begin(), AllowedChars.end(), *numberChar))
        {
            return false;
        }

    return true;
}

// client code
std::string  number = "091283019823";

bool isMobileNumber = is_valid_number(number) 
                      && number.size() == 10 
                      && number[0] == '9';
bool isLandLineNumber = false; // left as an exercise to the reader ;)