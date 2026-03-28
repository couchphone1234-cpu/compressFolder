/*********************************************************************************
*
* File Name: /home/user/programs/cgWin/noncode/scrap.cpp
*
* Date: March , 2 , 2024
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
* Program Shell Generated At: 8:60:02p.m.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
//#define string
#ifndef iostream
	#include <iostream>
	using namespace std;
#endif

#ifndef ctime
	#include <ctime>
#endif

#ifndef string
	#include <string>
#endif

#ifndef sstream
	#include <sstream>
#endif
/*
struct tm 
{
   int tm_sec;   // seconds of minutes from 0 to 61
   int tm_min;   // minutes of hour from 0 to 59
   int tm_hour;  // hours of day from 0 to 24
   int tm_mday;  // day of month from 1 to 31
   int tm_mon;   // month of year from 0 to 11
   int tm_year;  // year since 1900
   int tm_wday;  // days since sunday
   int tm_yday;  // days since January 1st
   int tm_isdst; // hours of daylight savings time
}
*/


//################################### GLOBAL DATA ###################################

class date
{
	public:
	
		date ( );
		tm getTimeStruct ( ) { return gmtm; };
		string getDateString ( ) { return dateStr; };
		string appStr ( );

	private:
		
		time_t now;
		string dateStr;
		tm gmtm;

};

//##################################################################################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


	void generateText ( char ch ); 


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifdef DEBUG
int main ( int argc, char *argv[] ) 
{
	date d;

	cout << "dates " << endl;
	cout << d.getTimeStruct ( ).tm_hour << endl;
	cout << d.getDateString ( ) << endl;
	cout << d.appStr ( ) << endl;

	return 0; 
}
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: generateText
*
* Parameters: char ch
*
* Modifications: 
*
*
*
*
*
* Returns: void
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
date::date (  ) 
{ 

	// current date/time based on current system
	time_t now = time ( 0 );
   
   	// convert now to string form
   	dateStr = ctime ( & now );
	
	// convert now to tm struct for UTC
	gmtm = * localtime ( & now );
   
	return;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=- FUNCTION DEFINITION -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*
* Function Name: generateText
*
* Parameters: char ch
*
* Modifications: 
*
*
*
*
*
* Returns: void
*
* Comments:
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
string date::appStr (  ) 
{ 
	stringstream s;
	string str;
	bool pm = false;
	int hour;

	s << gmtm.tm_mon + 1;
	s << ".";
	s << gmtm.tm_mday;
	s << ".";
	s << gmtm.tm_year + 1900;
	s << "(";
	
	if ( gmtm.tm_hour > 12 )
	{
		pm = true;
		hour = gmtm.tm_hour - 12;
	}
	else 
		hour = gmtm.tm_hour;
	
	s << hour;
	s << ".";
	s << gmtm.tm_min;
	s << ".";
	s << gmtm.tm_sec;
	
	if ( pm )
		s << "p.m.";
	else 
		s << "a.m.";
	
	s << ")";
	s >> str;

	return str;
}
