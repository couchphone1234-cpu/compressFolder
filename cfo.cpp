/*********************************************************************************
*
* File Name: C:\programs\cgUpgrade\noncode\scrap.cpp
*
* Date: November , 17 , 2024
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
* Program Shell Generated At: 8:06:57p.m.
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

	#ifndef fstream
	#include <fstream>
	#endif

	#ifndef stdlib_h
	#include <stdlib.h>
	#endif
	
	#include <regex>
	#ifndef __linux__
	#include <windows.h>
	#include <shlobj.h>
	#else
	#include <gtk/gtk.h>
	#endif
	
	#include <stdarg.h>
	#include <ctime> 

	using namespace std;
	
	#define COMPRESS_COMMAND "C:\\Program Files\\7-Zip\\7z\" a -p!@#$qwe -mhe=on"
	
	#include "date.cpp"
	#include "filePathClass.cpp"
	#define DEBUG
	//#pragma warning(disable : 4996) 

//################################### GLOBAL DATA ###################################



//##################################################################################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	bool compressFile ( string & fileName );
	bool readCLP ( int numArgs , char * args [ ] );
	string folderChooser (  );
	bool printDialog ( int numArgs , ... );
	

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//############## main function ############
int main ( int argc , char * argv [ ] ) 
{
	#ifdef __linux__
	gtk_init ( & argc, & argv );//initialize x windows api
	#endif
	
	string fileName = folderChooser ( );
	
	//test if a file has been selected #########
	if ( fileName == "" )
	{
		cerr << "No file selected...." << endl;
		return 0;
	}
	
	cerr << "*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cerr << "*Processing : " << fileName << endl;
	
	if ( readCLP ( argc , argv ) == false )
	{
		cerr << "Bad command invocation !!! " << endl;
		return 1;
	}
	
	cerr << "*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	
	//formatFile ( str , fileName , averageLineLength );
	compressFile ( fileName ); 

	return 0; 
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: readFileIntoString
*
* Parameters: string fileName
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
bool compressFile ( string & fileName ) 
{ 
	string command;
	date d;
	string dateString;
	time_t timestamp = time ( NULL );
	filePathClass fp;
	tm * ts;
	//define the seperator #########
	#ifdef __linux__	
	string seperator = "/";
	#else
	string seperator = "\\";
	#endif
	//debug code ####################
	#ifdef DEBUG
	ofstream debug;
	debug.open ( "debug.txt" );
	if ( debug.fail ( ) )
	{
		printDialog ( 1 , "debug file did not open ! " );
	}
	#endif
	
	//parse the path ##########
	fp.parseFilePath ( fileName );
	
	//Make the command ########
	#ifndef __linux__
	command += "\"\"";
	#endif
	command += COMPRESS_COMMAND;
	command += " \"";
	command += fileName;
	command += "_";
	dateString = d.appStr ( );
	command += dateString;
	command += ".7z";
	command += "\" \"";
	command += fileName;
	command += "\"";
	#ifndef __linux__
	command += "\"";
	#endif
	
	//debug code #############
	#ifdef DEBUG
	debug << command << endl;
	debug.close ( );
	#endif
	
	//run command #############
	int result = system ( command.c_str ( ) );
	//print dialog ############
	printDialog ( 4 , "Executing command: " , command.c_str ( ) , " result " , to_string ( result ).c_str ( ) );

	return true;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: readCLP
*
* Parameters: vector<string> & strings
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
bool readCLP ( int numArgs , char * args [ ] )
{ 
	
	return true;
	//Check for the right number of words
	if ( numArgs < 2 )
		return false;

	int i = 1;  

	//Get the options #############
	while ( i < numArgs )
	{
		//Newline option ###############      
		if ( strcmp ( args [ i ] , "-P" ) == 0 )  
		{
			//regexPatterns.push_back ( args [ i + 1 ] );
			i += 2;
		}
		else 
			i ++;
	}

   return true;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: setFileType
*
* Parameters: char * command
*             char * file
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
bool printDialog ( int numArgs , ... )
{
	va_list vl;
	int i = 0;
	int numVariables;
	string output;
	
	va_start( vl , numArgs );
	
	while ( i < numArgs )
	{
		output += va_arg( vl, char * );
		i ++;
	}
	
	cout << "printW: " << output << endl;
	

	#ifdef __linux__
	GtkWidget * dialog;

	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;

	dialog = gtk_message_dialog_new ( 0 , flags , GTK_MESSAGE_ERROR , GTK_BUTTONS_CLOSE , output.c_str ( ) , output.c_str ( ) , g_strerror ( errno ) );
	gtk_dialog_run ( GTK_DIALOG ( dialog ) );
	gtk_widget_destroy ( dialog );
	#else
	MessageBox ( 0 ,  output.c_str ( )  , "Windows Message....." ,  MB_ICONWARNING | MB_OK | MB_SYSTEMMODAL );
	#endif
	
	va_end ( vl );
	
	return true;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: setFileType
*
* Parameters: char * command
*             char * file
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
string folderChooser (  ) 
{ 
	int MAX_PATHz = 300;
	string fileName = "";
	
	#ifdef __linux__
	GtkWidget *dialog;
	GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
	gint res;

	dialog = gtk_file_chooser_dialog_new ("Open File" , 0 , action , "_Cancel" , GTK_RESPONSE_CANCEL , "_Open" , GTK_RESPONSE_ACCEPT, NULL );
    res = gtk_dialog_run ( GTK_DIALOG ( dialog ) );
	if ( res == GTK_RESPONSE_ACCEPT )
	{
		char * filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER ( dialog );
		filename = gtk_file_chooser_get_filename ( chooser );
		fileName = filename;
		g_free ( filename );
	}

	gtk_widget_destroy ( dialog );

	#else	
	TCHAR szDir [ MAX_PATHz ];
	BROWSEINFO bInfo;
	bInfo.hwndOwner = 0;
	bInfo.pidlRoot = NULL; 
	bInfo.pszDisplayName = szDir; // Address of a buffer to receive the display name of the folder selected by the user
	bInfo.lpszTitle = "Please, select a folder"; // Title of the dialog
	bInfo.ulFlags = 0 ;
	bInfo.lpfn = NULL;
	bInfo.lParam = 0;
	bInfo.iImage = -1;

	LPITEMIDLIST lpItem = SHBrowseForFolder ( & bInfo );
	
	if( lpItem != NULL )
	{
		SHGetPathFromIDList ( lpItem, szDir );
		//MessageBox( 0, szDir , szDir ,  MB_ICONWARNING | MB_OK| MB_SYSTEMMODAL );
		fileName = szDir;
	}

	#endif
	
	return fileName;
}
