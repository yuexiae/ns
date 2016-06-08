#ifndef SERVER_NS_WAREHOUSE_EXT_H_
#define SERVER_NS_WAREHOUSE_EXT_H_


class CNSWareHouseExt : public CNSWareHouse {
public:
    static int __cdecl ItemComparePos(const void *arg1, const void *arg2) {
		return (*(CNSItem **)arg1)->m_wPos - (*(CNSItem **)arg2)->m_wPos;
	}

	void SortPos() {
		qsort(this->m_ItemArray, this->m_dwCount, 4u, ItemComparePos);
	}

};



#endif