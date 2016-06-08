#ifndef SERVER_EXT_NS_OBJECT_MANAGER_EXT_H_
#define SERVER_EXT_NS_OBJECT_MANAGER_EXT_H_


#include "ns_header/ns.h"

class CNSObjectManagerExt : public CNSObjectManager {
public:
    template <typename T>
    CNSObject::Owner<T> Get(CNSObject::OBJECTTYPE type, unsigned long id) {
        return CNSObject::Owner<T>(static_cast<T*>(CNSObjectManager::_GetObjectA(type, id)));
    }

    template <typename T>
    CNSObject::Owner<T> Get(unsigned long id) {
        CNSObject *pObject = CNSObjectManager::_GetObjectA(id);
        if (pObject) {
            if (dynamic_cast<T *>(pObject)) {
                return CNSObject::Owner<T>(static_cast<T*>(pObject));
            } else {
                pObject->DecRefCount();
                return CNSObject::Owner<T>(NULL);
            }
        } else {
            return CNSObject::Owner<T>(NULL);;
        }
    }

    template <>
    CNSObject::Owner<CNSPcExt> Get(unsigned long id) {
        CNSObject *pObject = CNSObjectManager::_GetObjectA(CNSObject::ObjectType_Pc, id);
        return CNSObject::Owner<CNSPcExt>(static_cast<CNSPcExt *>(pObject));
    }
};









#endif