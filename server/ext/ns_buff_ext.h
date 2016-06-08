#ifndef SERVER_EXT_CNS_BUFF_EXT_H_
#define SERVER_EXT_CNS_BUFF_EXT_H_

#include "ns_header/ns.h"

class CNSBuffExt : public CNSBuff {
public:
	bool IsCanSave();

	//not malloc
};

#endif