#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "14";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.05";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 4;
	static const long BUILD = 421;
	static const long REVISION = 2366;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1338;
	#define RC_FILEVERSION 1,4,421,2366
	#define RC_FILEVERSION_STRING "1, 4, 421, 2366\0"
	static const char FULLVERSION_STRING[] = "1.4.421.2366";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 21;
	

}
#endif //VERSION_H
