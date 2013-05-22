#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "22";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 6;
	static const long BUILD = 648;
	static const long REVISION = 3572;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1892;
	#define RC_FILEVERSION 1,6,648,3572
	#define RC_FILEVERSION_STRING "1, 6, 648, 3572\0"
	static const char FULLVERSION_STRING[] = "1.6.648.3572";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 48;
	

}
#endif //VERSION_H
