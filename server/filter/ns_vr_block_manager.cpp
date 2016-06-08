#include "server/server_pch.h"

#include "server/ext/ns_ext.h"

class NSVrBlockPcFilter : public NSVrBlockPc {
public:
    BOOL ObjectInfoNew(std::vector<CNSObject *>& vectorObject, std::map<unsigned long,CNSPc *>::iterator cur_Iter, unsigned short x1, unsigned short y1 , unsigned short x2, unsigned short y2) {
        __try {
            CNSObject *pTarget = cur_Iter->second;
            if (pTarget == NULL || !pTarget->m_dwObjectId) {
                throw 0;
            } else if (pTarget->m_cell.x >= x1 && pTarget->m_cell.x <= x2 && pTarget->m_cell.y >= y1 && pTarget->m_cell.y <= y2) {
                pTarget->IncRefCount();
                vectorObject.push_back(pTarget);
            }

            return TRUE;
        } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
            GameUtil::Output("Exception: NSVrBlockObject::ObjectInfo(%08x: %d/%d - %d/%d)",
                cur_Iter->second, x1, y1, x2, y2);
        }

        return FALSE;
    }

    void BlockInfoFilter(std::vector<CNSObject *>& vectorObject, unsigned short x1 , unsigned short y1 , unsigned short x2, unsigned short y2) {
        CNSCriticalSection::Owner lock(this->m_cs);
        if (this->m_mapObject.empty()) {
            return;
        }

        for (std::map<unsigned long,CNSPc *>::iterator iter = this->m_mapObject.begin();
            iter != this->m_mapObject.end();) {
                if (ObjectInfoNew(vectorObject, iter, x1, y1, x2, y2)) {
                    ++iter;
                } else {
                    this->m_mapObject.erase(iter++);
                }
        }
    }
};

class NSVrBlockObjectFilter : public NSVrBlockObject {
public:
    BOOL ObjectInfoNew(CNSObject::OBJECTTYPE typeObject, std::vector<CNSObject *>& vectorObject, std::map<unsigned long,CNSObject *>::iterator cur_Iter, unsigned short x1, unsigned short y1 , unsigned short x2, unsigned short y2) {
        __try {
            CNSObject *pTarget = cur_Iter->second;
            if (pTarget == NULL || !pTarget->m_dwObjectId) {
                throw 0;
            } else if ((typeObject == CNSObject::ObjectType_NULL || pTarget->GetType() == typeObject)
                && pTarget->m_cell.x >= x1 && pTarget->m_cell.x <= x2 && pTarget->m_cell.y >= y1 && pTarget->m_cell.y <= y2) {
                pTarget->IncRefCount();
                vectorObject.push_back(pTarget);
            }

            return TRUE;
        } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
            GameUtil::Output("Exception: NSVrBlockObject::ObjectInfo(%08x: %d/%d - %d/%d)",
                cur_Iter->second, x1, y1, x2, y2);
        }

        return FALSE;
    }

    void BlockInfoFilter(CNSObject::OBJECTTYPE typeObject, std::vector<CNSObject *>& vectorObject, unsigned short x1 , unsigned short y1 , unsigned short x2, unsigned short y2) {
        CNSCriticalSection::Owner lock(this->m_cs);
        if (this->m_mapObject.empty()) {
            return;
        }

        for (std::map<unsigned long,CNSObject *>::iterator iter = this->m_mapObject.begin();
            iter != this->m_mapObject.end();) {
                if (ObjectInfoNew(typeObject, vectorObject, iter, x1, y1, x2, y2)) {
                    ++iter;
                } else {
                    this->m_mapObject.erase(iter++);
                }
        }
    }
};

class CNSVrBlockManagerFilter : public CNSVrBlockManagerExt {
public:
    BOOL InitFilter();

    BOOL AddFilter(CNSObject *pObject, NSPOINT2& cell);

    BOOL RemoveFilter(CNSObject *pObject);

    void RemoveAllFilter(CNSObject *pObject);

    BOOL MoveFilter(CNSObject *pObject, NSPOINT2& cell);

    BOOL IsExistFilter(CNSObject *pObject) {
        if (this->VerifyNSVrBlock(pObject->m_block)) {
            if (pObject->IsPcClass()) {
                NSVrBlockPc &block = this->m_ppNSVrBlockPc[pObject->m_block.x][pObject->m_block.y];
                CNSCriticalSection::Owner lock(block.m_cs);
                return  block.m_mapObject.find(pObject->m_dwObjectId) != block.m_mapObject.end();
            } else {
                NSVrBlockObject &block = this->m_ppNSVrBlockObject[pObject->m_block.x][pObject->m_block.y];
                CNSCriticalSection::Owner lock(block.m_cs);
                return block.m_mapObject.find(pObject->m_dwObjectId) != block.m_mapObject.end();
            }
        } else {
            return FALSE;
        }
    }

    void BroadcastFilter(CNSObject *pObject, CPacket& packet, int bSendExcept, unsigned short wSight) {
        CNSCharacter *pChar = dynamic_cast<CNSCharacter *>(pObject);
        if (pChar == NULL) {
            GameUtil::Output("Error: Broadcast(ObjectId: %p) = Not NSCharacter\n", pObject);
            return;
        }

        _NSRANGE range;
        this->GetBroadcastRange(pObject->m_cell, range, wSight ? wSight : this->m_nBlockMaxSight);

        NSVrBlockPc *ppVrBlockPc[9];
        memset(ppVrBlockPc, 0, sizeof(ppVrBlockPc));
        int nBlockCount = this->GetVrBlockList(pObject->m_block, range, ppVrBlockPc);

        bool bEncode = false;
        for (int i = 0; i < nBlockCount; ++i) {
            if (!ppVrBlockPc[i]) {
                continue;
            }

            CNSCriticalSection::Owner lock(ppVrBlockPc[i]->m_cs);
            if (ppVrBlockPc[i]->m_mapObject.empty()) {
                continue;
            }

            for (std::map<unsigned long,CNSPc *>::iterator iter = ppVrBlockPc[i]->m_mapObject.begin();
                iter != ppVrBlockPc[i]->m_mapObject.end();) {
                    if (BroadcastPcNew(pChar, packet, iter->second, range, bSendExcept, bEncode)) {
                        ++iter;
                    } else {
                        ppVrBlockPc[i]->m_mapObject.erase(iter++);
                    }
            }
        }
    }

};



bool CNSVrBlockManagerFilterInit() {
    return NSVrBlockPc::_PatchBlockInfo(&NSVrBlockPcFilter::BlockInfoFilter)
        && NSVrBlockObject::_PatchBlockInfo(&NSVrBlockObjectFilter::BlockInfoFilter)
        
        && CNSVrBlockManager::_PatchIsExist(&CNSVrBlockManagerFilter::IsExistFilter)
        && CNSVrBlockManager::_PatchBroadcast(&CNSVrBlockManagerFilter::BroadcastFilter);
}