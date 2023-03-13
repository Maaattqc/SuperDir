#pragma once
#include "FileInfo_Base.h"

class FileInfo_Binary : public FileInfo_Base{

public:
	virtual void DisplayInformation() const;
	virtual void RetrieveInformation();

protected:

	FileInfo_Binary();

private:

	uint64_t Size;
};