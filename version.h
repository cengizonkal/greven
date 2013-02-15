#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "14";
	static const char MONTH[] = "02";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.02";
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 1;
	static const long BUILD = 152;
	static const long REVISION = 859;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 891;
	#define RC_FILEVERSION 1,1,152,859
	#define RC_FILEVERSION_STRING "1, 1, 152, 859\0"
	static const char FULLVERSION_STRING[] = "1.1.152.859";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 52;
	

}
#endif //VERSION_H
