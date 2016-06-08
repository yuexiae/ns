#ifndef SERVER_EXT_NS_SKILL_EXT_H_
#define SERVER_EXT_NS_SKILL_EXT_H_



#include "ns_header/ns.h"

class CNSSkillExt : public CNSSkill {
public:
    static CNSSkill * New() {
       return &reinterpret_cast<CNSSkill *>(new char[sizeof(CNSSkill)])->Constructor();
    }

    BOOL UseNew(CNSCharacter *pChar, CNSCharacter *pTarget, unsigned long dwTime);
};






#endif