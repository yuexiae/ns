#ifndef SERVER_NSINVENTORY_EXT_H_
#define SERVER_NSINVENTORY_EXT_H_


class CNSInventoryExt : public CNSInventory {
public:
    static int __cdecl ItemComparePos(const void *arg1, const void *arg2) {
        return (*(CNSItem **)arg1)->m_wPos - (*(CNSItem **)arg2)->m_wPos;
    }

    void SortPos() {
        qsort(this->m_ItemArray, this->m_dwCount, sizeof(CNSItem *), ItemComparePos);
    }
};



#endif