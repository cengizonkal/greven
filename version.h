#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "12";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 4;
	static const long BUILD = 408;
	static const long REVISION = 2305;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1287;
	#define RC_FILEVERSION 1,4,408,2305
	#define RC_FILEVERSION_STRING "1, 4, 408, 2305\0"
	static const char FULLVERSION_STRING[] = "1.4.408.2305";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 8;
	

}
#endif //VERSION_H
