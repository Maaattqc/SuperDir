#pragma once
#include "FileInfo_Base.h"

class FileInfo_Text : public FileInfo_Base {

public:
	virtual void DisplayInformation() const;
	virtual void RetrieveInformation();

protected:
	FileInfo_Text();

private:
	unsigned int LCount;

};