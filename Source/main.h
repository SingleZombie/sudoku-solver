//*******************************************************
// Main.h
// Creator: ZhouYifan
// Create Date: 2020/1/1 20:39
// Description:
// The header of main. Provide the definition of class MainProcess which
// process all the information in the class rather than out of class.
//
// ******************************************************

#ifndef SUDO_MAIN_H
#define SUDO_MAIN_H

#include <iostream>

class MainProcess
{
public:
	static MainProcess mainProcess;
	int main(int argc, char* argv[]);
private:
	MainProcess()
	{

	}
};


#endif