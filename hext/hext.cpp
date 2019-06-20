#include <iostream>
using std::cin;
using std::cout;
using str = std::string;

// char sets
const str asciiChars{
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~"
};
const str hexChars[] = {
"41 ","42 ","43 ","44 ","45 ","46 ","47 ","48 ","49 ","4A ","4B ","4C ","4D ","4E ","4F ","50 ",
"51 ","52 ","53 ","54 ","55 ","56 ","57 ","58 ","59 ","5A ","61 ","62 ","63 ","64 ","65 ","66 ",
"67 ","68 ","69 ","6A ","6B ","6C ","6D ","6E ","6F ","70 ","71 ","72 ","73 ","74 ","75 ","76 ",
"77 ","78 ","79 ","7A ","20 ","21 ","22 ","23 ","24 ","25 ","26 ","27 ","28 ","29 ","2A ","2B ",
"2C ","2D ","2E ","2F ","30 ","31 ","32 ","33 ","34 ","35 ","36 ","37 ","38 ","39 ","3A ","3B ",
"3C ","3D ","3E ","3F ","40 ","5B ","5C ","5D ","5E ","5F ","60 ","7B ","7C ","7D "
};

// mini-config
unsigned bytesPerLine = 16;
bool isLowerCase = 0;

// funcs
str getText()
{
	str tmp;
	str inputText;
	cout << "USAGE: Press Ctrl+D(linux) or Ctrl+Z(windows) to convert to hex\x0A";
	cout << "-------------------------------------------------------------\x0A";
	cout << "Input Text\x0A~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\x0A";
	while (cin >> tmp)
	{
		inputText += tmp + char(0x20);	
	}
	cout << "\x0A~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return inputText;
}

str convertToHex(str text)
{
	str hexString;
	for (auto c : text)
	{
		for (unsigned j=0; j != asciiChars.size(); ++j)
		{
			if (c == asciiChars[j])
			{
				if (isLowerCase)
				{
					str tmp;
					for (auto m : hexChars[j])
					{
						tmp += tolower(m);
					}
					hexString += tmp;
				}
			    else 
			    {
				    hexString += hexChars[j];
				}
			}
		}
	}
	return hexString;
}

void printHexText(str text)
{
	bytesPerLine = bytesPerLine*2+15;
	unsigned cntr = 0;
	cout << "\x0A\x0AOutput Hex\x0A~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << char(0xA);
	for (auto c : text)
	{
		if (cntr != bytesPerLine)
		{
			cout << c;	
			++cntr;
		}
		else
		{
			cout << char(0x0A);
			cntr = 0;
		}
	}
	cout << "\x0A~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\x0A";
}

int main(void)
{
	printHexText(convertToHex(getText()));

	return 0;
}

	
