#ifndef SERVER_EXT_NS_ITEM_EXT_H_
#define SERVER_EXT_NS_ITEM_EXT_H_

#include "ns_header/ns.h"


class CNSItemExt : public CNSItem {
public:
	unsigned int GetOptionSize() {
		for (int i = 0; i < sizeof(this->m_Option) / sizeof(this->m_Option[0]); ++i) {
			if (!this->m_Option[i].btParam) {
				return sizeof(this->m_Option[0]) * i;
			}
		}

		return sizeof(this->m_Option);
	}

    static CNSItem * New() {
       return &reinterpret_cast<CNSItem *>(CNSItem::operator new(sizeof(CNSItem)))->Constructor();
    }
};



#endif