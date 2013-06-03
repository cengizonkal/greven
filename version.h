#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.06";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 7;
	static const long BUILD = 784;
	static const long REVISION = 4361;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 2207;
	#define RC_FILEVERSION 1,7,784,4361
	#define RC_FILEVERSION_STRING "1, 7, 784, 4361\0"
	static const char FULLVERSION_STRING[] = "1.7.784.4361";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 84;
	

}
#endif //VERSION_H
