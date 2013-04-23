#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "23";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.04";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 3;
	static const long BUILD = 348;
	static const long REVISION = 1974;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1170;
	#define RC_FILEVERSION 1,3,348,1974
	#define RC_FILEVERSION_STRING "1, 3, 348, 1974\0"
	static const char FULLVERSION_STRING[] = "1.3.348.1974";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 48;
	

}
#endif //VERSION_H
