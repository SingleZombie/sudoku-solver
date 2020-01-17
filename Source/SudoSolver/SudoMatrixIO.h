//*******************************************************
// SudoMatrixIO.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 14:14
// Description:
// Provide the definition of class SudoMatrixIO.
// The class read and write SudoMatrix by using a file pointer.
//
// ******************************************************

#ifndef SUDO_MATRIX_IO_H
#define SUDO_MATRIX_IO_H

#include "SudoMatrix.h"
#include <cstdio>

namespace Sudo
{
	class SudoMatrixIO
	{
	public:
		// Read a matrix from file pointer
		// return -1(EOF) if the file is end
		// return -2 if format is wrong
		// return 0 if success
		static int readMatrix(std::FILE* fp, SudoMatrix& matrix);
		// Write matrices to a file pointer
		// return the count of matrices that are successfully written.
		static int writeMatrices(std::FILE* fp, const SudoMatrix* matricesArray, int count);
	private:
		SudoMatrixIO();
		virtual ~SudoMatrixIO();
	};

}
#endif

