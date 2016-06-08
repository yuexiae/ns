#ifndef NSHEADER_NPC_STATE_H_
#define NSHEADER_NPC_STATE_H_


class CNSNpcState {
public:
    static const unsigned int _size = 0x10;

    CNSNpcState(const CNSNpcState &);
    CNSNpcState(CNSNpc *);    PATCH_MEMBER(CNSNpcState &, Constructor, CNSNpc *, 0x458310);
    virtual ~CNSNpcState();    PATCH_MEMBER(void, Destructor, , 0x458340);
    virtual void Action(unsigned long);
    class CNSNpc * m_pParent;//this+0x4
    int m_bFirst;//this+0x8
    unsigned long m_dwTraceTime;//this+0xC
    virtual int IsFirst();    PATCH_MEMBER(int, IsFirst, , 0x402210);
    virtual void Clear();    PATCH_MEMBER(void, Clear, , 0x458400);
    int TraceTarget(CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x458360);
    CNSNpcState & operator=(const CNSNpcState &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcState &, CNSNpcState, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcState, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSNpcState, IsFirst, );
PATCH_MEMBER_INVOKE(void, CNSNpcState, Clear, );
PATCH_MEMBER_INVOKE(int, CNSNpcState, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcState::Constructor(CNSNpc *), 0x458310);
//DEFINE_NAKED_JMP(CNSNpcState::Destructor(), 0x458340);
//DEFINE_NAKED_JMP(int CNSNpcState::IsFirst(), 0x402210);
//DEFINE_NAKED_JMP(void CNSNpcState::Clear(), 0x458400);
//DEFINE_NAKED_JMP(int CNSNpcState::TraceTarget(CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x458360);
#endif
};

class CNSNpcStateUnderground : public CNSNpcState {
public:
    static const unsigned int _size = 0x10;

    CNSNpcStateUnderground(const CNSNpcStateUnderground &);
    CNSNpcStateUnderground(CNSNpc *);    PATCH_MEMBER(CNSNpcStateUnderground &, Constructor, CNSNpc *, 0x45AC70);
    virtual ~CNSNpcStateUnderground();    PATCH_MEMBER(void, Destructor, , 0x45ACA0);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x45ACC0);
    CNSNpcStateUnderground & operator=(const CNSNpcStateUnderground &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateUnderground &, CNSNpcStateUnderground, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateUnderground, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateUnderground, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateUnderground::Constructor(CNSNpc *), 0x45AC70);
//DEFINE_NAKED_JMP(CNSNpcStateUnderground::Destructor(), 0x45ACA0);
//DEFINE_NAKED_JMP(void CNSNpcStateUnderground::Action(unsigned long), 0x45ACC0);
#endif
};

class CNSNpcStateStand : public CNSNpcState {
public:
    static const unsigned int _size = 0x14;

    CNSNpcStateStand(const CNSNpcStateStand &);
    CNSNpcStateStand(CNSNpc *);    PATCH_MEMBER(CNSNpcStateStand &, Constructor, CNSNpc *, 0x45A9F0);
    virtual ~CNSNpcStateStand();    PATCH_MEMBER(void, Destructor, , 0x45AA20);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x45AA40);
    unsigned long m_dwCheckTime;//this+0x10
    CNSNpcStateStand & operator=(const CNSNpcStateStand &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateStand &, CNSNpcStateStand, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateStand, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateStand, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateStand::Constructor(CNSNpc *), 0x45A9F0);
//DEFINE_NAKED_JMP(CNSNpcStateStand::Destructor(), 0x45AA20);
//DEFINE_NAKED_JMP(void CNSNpcStateStand::Action(unsigned long), 0x45AA40);
#endif
};

class CNSNpcStateSkill : public CNSNpcState {
public:
    static const unsigned int _size = 0x1c;

    CNSNpcStateSkill(const CNSNpcStateSkill &);
    CNSNpcStateSkill(CNSNpc *);    PATCH_MEMBER(CNSNpcStateSkill &, Constructor, CNSNpc *, 0x45A220);
    virtual ~CNSNpcStateSkill();    PATCH_MEMBER(void, Destructor, , 0x45A260);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x45A370);
    int m_nAttackCount;//this+0x10
    unsigned long m_dwAttackTime;//this+0x14
    unsigned long m_dwSkillStartTime;//this+0x18
    void SkillCancel();    PATCH_MEMBER(void, SkillCancel, , 0x45A280);
    void SkillFinish();    PATCH_MEMBER(void, SkillFinish, , 0x45A300);
    virtual void Clear();    PATCH_MEMBER(void, Clear, , 0x45A840);
    CNSNpcStateSkill & operator=(const CNSNpcStateSkill &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateSkill &, CNSNpcStateSkill, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateSkill, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateSkill, Action, unsigned long);
PATCH_MEMBER_INVOKE(void, CNSNpcStateSkill, SkillCancel, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateSkill, SkillFinish, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateSkill, Clear, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateSkill::Constructor(CNSNpc *), 0x45A220);
//DEFINE_NAKED_JMP(CNSNpcStateSkill::Destructor(), 0x45A260);
//DEFINE_NAKED_JMP(void CNSNpcStateSkill::Action(unsigned long), 0x45A370);
//DEFINE_NAKED_JMP(void CNSNpcStateSkill::SkillCancel(), 0x45A280);
//DEFINE_NAKED_JMP(void CNSNpcStateSkill::SkillFinish(), 0x45A300);
//DEFINE_NAKED_JMP(void CNSNpcStateSkill::Clear(), 0x45A840);
#endif
};

class CNSNpcStateRunaway : public CNSNpcState {
public:
    static const unsigned int _size = 0x10;

    CNSNpcStateRunaway(const CNSNpcStateRunaway &);
    CNSNpcStateRunaway(CNSNpc *);    PATCH_MEMBER(CNSNpcStateRunaway &, Constructor, CNSNpc *, 0x459FE0);
    virtual ~CNSNpcStateRunaway();    PATCH_MEMBER(void, Destructor, , 0x45A010);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x45A030);
    CNSNpcStateRunaway & operator=(const CNSNpcStateRunaway &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateRunaway &, CNSNpcStateRunaway, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateRunaway, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateRunaway, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateRunaway::Constructor(CNSNpc *), 0x459FE0);
//DEFINE_NAKED_JMP(CNSNpcStateRunaway::Destructor(), 0x45A010);
//DEFINE_NAKED_JMP(void CNSNpcStateRunaway::Action(unsigned long), 0x45A030);
#endif
};

class CNSNpcStateReturn : public CNSNpcState {
public:
    static const unsigned int _size = 0x10;

    CNSNpcStateReturn(const CNSNpcStateReturn &);
    CNSNpcStateReturn(CNSNpc *);    PATCH_MEMBER(CNSNpcStateReturn &, Constructor, CNSNpc *, 0x459DA0);
    virtual ~CNSNpcStateReturn();    PATCH_MEMBER(void, Destructor, , 0x459DD0);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x459DF0);
    CNSNpcStateReturn & operator=(const CNSNpcStateReturn &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateReturn &, CNSNpcStateReturn, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateReturn, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateReturn, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateReturn::Constructor(CNSNpc *), 0x459DA0);
//DEFINE_NAKED_JMP(CNSNpcStateReturn::Destructor(), 0x459DD0);
//DEFINE_NAKED_JMP(void CNSNpcStateReturn::Action(unsigned long), 0x459DF0);
#endif
};

class CNSNpcStateMove : public CNSNpcState {
public:
    static const unsigned int _size = 0x14;

    CNSNpcStateMove(const CNSNpcStateMove &);
    CNSNpcStateMove(CNSNpc *);    PATCH_MEMBER(CNSNpcStateMove &, Constructor, CNSNpc *, 0x4598C0);
    virtual ~CNSNpcStateMove();    PATCH_MEMBER(void, Destructor, , 0x4598F0);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x459910);
    unsigned long m_dwCounter;//this+0x10
    CNSNpcStateMove & operator=(const CNSNpcStateMove &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateMove &, CNSNpcStateMove, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateMove, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateMove, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateMove::Constructor(CNSNpc *), 0x4598C0);
//DEFINE_NAKED_JMP(CNSNpcStateMove::Destructor(), 0x4598F0);
//DEFINE_NAKED_JMP(void CNSNpcStateMove::Action(unsigned long), 0x459910);
#endif
};

class CNSNpcStateGlobal : public CNSNpcState {
public:
    static const unsigned int _size = 0x20;

    CNSNpcStateGlobal(const CNSNpcStateGlobal &);
    CNSNpcStateGlobal(CNSNpc *);    PATCH_MEMBER(CNSNpcStateGlobal &, Constructor, CNSNpc *, 0x459210);
    virtual ~CNSNpcStateGlobal();    PATCH_MEMBER(void, Destructor, , 0x4592A0);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x459400);
    unsigned long m_dwRecoveryTime;//this+0x10
    unsigned long m_dwCheckTime;//this+0x14
    unsigned long m_statPrev;//this+0x18
    int m_nStaPer;//this+0x1C
    void PetAction(unsigned long);    PATCH_MEMBER(void, PetAction, unsigned long, 0x4592C0);
    CNSNpcStateGlobal & operator=(const CNSNpcStateGlobal &);
    //void __dflt_ctor_closure();
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateGlobal &, CNSNpcStateGlobal, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateGlobal, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateGlobal, Action, unsigned long);
PATCH_MEMBER_INVOKE(void, CNSNpcStateGlobal, PetAction, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateGlobal::Constructor(CNSNpc *), 0x459210);
//DEFINE_NAKED_JMP(CNSNpcStateGlobal::Destructor(), 0x4592A0);
//DEFINE_NAKED_JMP(void CNSNpcStateGlobal::Action(unsigned long), 0x459400);
//DEFINE_NAKED_JMP(void CNSNpcStateGlobal::PetAction(unsigned long), 0x4592C0);
#endif
};

class CNSNpcStateDead : public CNSNpcState {
public:
    static const unsigned int _size = 0x14;

    CNSNpcStateDead(const CNSNpcStateDead &);
    CNSNpcStateDead(CNSNpc *);    PATCH_MEMBER(CNSNpcStateDead &, Constructor, CNSNpc *, 0x458CF0);
    virtual ~CNSNpcStateDead();    PATCH_MEMBER(void, Destructor, , 0x458D20);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x458D40);
    int m_bItemExist;//this+0x10
    CNSNpcStateDead & operator=(const CNSNpcStateDead &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateDead &, CNSNpcStateDead, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateDead, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateDead, Action, unsigned long);
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateDead::Constructor(CNSNpc *), 0x458CF0);
//DEFINE_NAKED_JMP(CNSNpcStateDead::Destructor(), 0x458D20);
//DEFINE_NAKED_JMP(void CNSNpcStateDead::Action(unsigned long), 0x458D40);
#endif
};

class CNSNpcStateAttack : public CNSNpcState {
public:
    static const unsigned int _size = 0x1c;

    CNSNpcStateAttack(const CNSNpcStateAttack &);
    CNSNpcStateAttack(CNSNpc *);    PATCH_MEMBER(CNSNpcStateAttack &, Constructor, CNSNpc *, 0x458450);
    virtual ~CNSNpcStateAttack();    PATCH_MEMBER(void, Destructor, , 0x458490);
    virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x4584B0);
    int m_nAttackCount;//this+0x10
    unsigned long m_dwAttackTime;//this+0x14
    unsigned long m_dwCheckTime;//this+0x18
    virtual void Clear();    PATCH_MEMBER(void, Clear, , 0x45A840);
    CNSNpcStateAttack & operator=(const CNSNpcStateAttack &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcStateAttack &, CNSNpcStateAttack, Constructor, CNSNpc *);
PATCH_MEMBER_INVOKE(void, CNSNpcStateAttack, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcStateAttack, Action, unsigned long);
PATCH_MEMBER_INVOKE(void, CNSNpcStateAttack, Clear, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcStateAttack::Constructor(CNSNpc *), 0x458450);
//DEFINE_NAKED_JMP(CNSNpcStateAttack::Destructor(), 0x458490);
//DEFINE_NAKED_JMP(void CNSNpcStateAttack::Action(unsigned long), 0x4584B0);
//DEFINE_NAKED_JMP(void CNSNpcStateAttack::Clear(), 0x45A840);
#endif
};




#endif