#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "08";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.04";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 2;
	static const long BUILD = 226;
	static const long REVISION = 1259;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1026;
	#define RC_FILEVERSION 1,2,226,1259
	#define RC_FILEVERSION_STRING "1, 2, 226, 1259\0"
	static const char FULLVERSION_STRING[] = "1.2.226.1259";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 26;
	

}
#endif //VERSION_H
