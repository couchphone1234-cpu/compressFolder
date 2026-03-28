/*********************************************************************************
*
* File Name: /home/user/programs/cgUpgrade/noncode/scrap.cpp
*
* Date: June , 9 , 2025
* Comments: 
* Compiler/Assembler:
* Modifications:
*
*
*
*
*
*
*
* Program Shell Generated At: 10:43:56p.m.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


	#ifndef iostream
	#include <iostream>
	#endif

	#ifndef string
	#include <string>
	#endif

	#ifndef string_h
	#include <string.h>
	#endif

	#ifndef ctype_h
	#include <ctype.h>
	#endif

	#ifndef ifstream
	#include <fstream>
	#endif

	#ifndef stdlib_h
	#include <stdlib.h>
	#endif

	using namespace std;

//################################### GLOBAL DATA ###################################


//##################################################################################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	//###########################################################################################
	//Class Definition: filePathClass ##########################
	//###########################################################################################
	class filePathClass
	{
		public:

			filePathClass ( ); 
			~filePathClass ( ); 
			bool parseFilePath ( string inputPath );
			bool genericPath ( string suffix );
			bool debug ( );
			
			string fileName;
			string fileExtention;
			string fileNameAndExtention;
			string path;
			string scratchPath;
			 
		private:
			
			string internalDir;

	};
#ifdef DEBUG
int main ( int argc , char * argv [ ] ) 
{

	filePathClass fp;
	
	fp.parseFilePath ( "/home/programs/muffet/muffetDog.exe" );
	fp.genericPath ( "New" );
	fp.debug ( );

	return 0; 
}
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- CONSTRUCTOR DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
 Function Name: 
*
* Parameters:
*
* Modifications:
*
*
*
*
*
* Returns:
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
filePathClass::filePathClass ( )
{



}
/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- DESTRUCTOR DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+
*
 Function Name: 
*
* Parameters:
*
* Modifications:
*
*
*
*
*
* Returns:
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
filePathClass::~filePathClass ( )
{



}
/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: directoryClass::parseFilePath
*
* Parameters: string inputPath
*
* Modifications: 
*
*
*
*
*
* Returns: bool
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
bool filePathClass::parseFilePath ( string inputPath ) 
{ 
	int dirLength = inputPath.size ( );
	int i = dirLength - 1;
	
	scratchPath = inputPath;
	
	#ifdef __linux__
	char pathDivider = '/';
	#else
	char pathDivider = '\\';
	#endif
	
	fileExtention.clear ( );
	
	//extension #####################
	while ( i >= 0 and inputPath [ i ] != '.' )
	{
		//add the char to the extension ########
		fileExtention.insert ( 0 , 1 , inputPath [ i ] );
		i --;
	}
	
	//incomplete path ###############
	if ( i < 0 )
		return false;
	
	i --;
	
	fileName.clear ( );
	
	//get the file name #############
	while ( i >= 0 and inputPath [ i ] != pathDivider )
	{
		fileName.insert ( 0 , 1 , inputPath [ i ] );
		i --;
	}
	
	fileNameAndExtention.clear ( );
	
	//make file name and extention #######
	fileNameAndExtention = fileName;
	fileNameAndExtention += ".";
	fileNameAndExtention += fileExtention;
	
	//no path listed ###############
	if ( i < 0 )
		return false;
	
	path.clear ( );
	
	//get the path #######################
	path = inputPath.substr ( 0 , i );
	
	return true;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: loadDirs
*
* Parameters:  
*
* Modifications: 
*
*
*
*
*
* Returns: bool
*
* Comments:
			string internalDir;
			string fileName;
			string fileExtention;
			string fileNameAndExtention;
			string path;
			string scratchPath;
			vector < string > files;
			vector < string > directories;
			vector < string > filters;
			bool deepSearch = false; 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
bool filePathClass::debug ( ) 
{ 

	cout << endl << "Debug ###############################################" << endl;
	cout << "# internalDir: " << internalDir << endl;
	cout << "# fileName: " << fileName << endl;
	cout << "# fileExtention: " << fileExtention << endl;
	cout << "# fileNameAndExtention: " << fileNameAndExtention << endl;
	cout << "# path: " << path << endl;
	cout << "# scratchPath: " << scratchPath << endl;
	cout << "End #################################################################" << endl;
	
	return true;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: directoryClass::parseFilePath
*
* Parameters: string inputPath
*
* Modifications: 
*
*
*
*
*
* Returns: bool
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
bool filePathClass::genericPath ( string suffix ) 
{ 
	#ifdef __linux__
	char pathDivider = '/';
	#else
	char pathDivider = '\\';
	#endif
	
	scratchPath = path + pathDivider + fileName + suffix + ".";
	scratchPath += fileExtention;
	
	return true;

}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: directoryClass::parseFilePath
*
* Parameters: string inputPath
*
* Modifications: 
*
*
*
*
*
* Returns: bool
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
bool filePathClass::debug (  ) 
{
	cout << "************** Debug Output *******************" << endl;
	cout << "file name: " <<  fileName << endl;
	cout << "file extention: " <<  fileExtention << endl;
	cout << "file name and extention: " <<  fileNameAndExtention << endl;
	cout << "path: " <<  path << endl;
	cout << "scratch path:" <<  scratchPath << endl;
	cout << "***********************************************" << endl;
}*/
