//*******************************************************
// Main.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/1 20:38
// Description:
// The entry of the program.
//
// ******************************************************

#include "main.h"
Sudo::CmdInteraction cmdInteraction;
int main(int argc, char* argv[])
{
	cmdInteraction.inputCmd(argc, argv);
	system("pause");
	return 0;
}

