#ifndef NSHEADER_NS_PC_STATE_H_
#define NSHEADER_NS_PC_STATE_H_


class CNSPcState {
public:
	static const unsigned int _size = 0x8;

	CNSPcState(const CNSPcState &);
	CNSPcState(CNSPc *);    PATCH_MEMBER(CNSPcState &, Constructor, CNSPc *, 0x4940B0);
	virtual ~CNSPcState();    PATCH_MEMBER(void, Destructor, , 0x4940E0);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481CD0);
	virtual void Action(unsigned long);
	class CNSPc * m_pParent;//this+0x4
	CNSPcState & operator=(const CNSPcState &);
	//void __dflt_ctor_closure();
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcState &, CNSPcState, Constructor, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcState, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcState, SetParent, CNSPc *);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcState::Constructor(CNSPc *), 0x4940B0);
	//DEFINE_NAKED_JMP(CNSPcState::Destructor(), 0x4940E0);
	//DEFINE_NAKED_JMP(void CNSPcState::SetParent(CNSPc *), 0x481CD0);
#endif
};



class CNSPcStateGlobal : public CNSPcState {
public:
	static const unsigned int _size = 0x1c;

	CNSPcStateGlobal(const CNSPcStateGlobal &);
	CNSPcStateGlobal(CNSPc *);    PATCH_MEMBER(CNSPcStateGlobal &, Constructor, CNSPc *, 0x494E80);
	virtual ~CNSPcStateGlobal();    PATCH_MEMBER(void, Destructor, , 0x494ED0);
	virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x495030);
	unsigned long m_dwRecoveryTime;//this+0x8
	unsigned long m_dwMoveTime;//this+0xC
	unsigned long m_dwPartySyncTime;//this+0x10
	unsigned long m_dwSteamRiderTime;//this+0x14
	unsigned long m_statPrev;//this+0x18
	int Recovery(unsigned long);    PATCH_MEMBER(int, Recovery, unsigned long, 0x494EF0);
	CNSPcStateGlobal & operator=(const CNSPcStateGlobal &);
	//void __dflt_ctor_closure();
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcStateGlobal &, CNSPcStateGlobal, Constructor, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcStateGlobal, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcStateGlobal, Action, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcStateGlobal, Recovery, unsigned long);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcStateGlobal::Constructor(CNSPc *), 0x494E80);
	//DEFINE_NAKED_JMP(CNSPcStateGlobal::Destructor(), 0x494ED0);
	//DEFINE_NAKED_JMP(void CNSPcStateGlobal::Action(unsigned long), 0x495030);
	//DEFINE_NAKED_JMP(int CNSPcStateGlobal::Recovery(unsigned long), 0x494EF0);
#endif
};



class CNSPcStateAttack : public CNSPcState {
public:
	static const unsigned int _size = 0x1c;

	CNSPcStateAttack(const CNSPcStateAttack &);
	CNSPcStateAttack(CNSPc *);    PATCH_MEMBER(CNSPcStateAttack &, Constructor, CNSPc *, 0x494130);
	virtual ~CNSPcStateAttack();    PATCH_MEMBER(void, Destructor, , 0x494190);
	void Init();    PATCH_MEMBER(void, Init, , 0x4941B0);
	virtual void Action(unsigned long);    PATCH_MEMBER(void, Action, unsigned long, 0x494BE0);
	int m_bFirstAttack;//this+0x8
	int m_bFirst;//this+0xC
	unsigned long m_dwAttackTime;//this+0x10
	unsigned long m_dwTraceTime;//this+0x14
	unsigned long m_dwPrevTargetObject;//this+0x18
	int TraceTarget(CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4941D0);
	void OnAttack(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, OnAttack, CNSCharacter * _COMMA unsigned long, 0x4942D0);
	void OnPickItem(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, OnPickItem, CNSCharacter * _COMMA unsigned long, 0x494500);
	int OnSkill(CNSCharacter *, unsigned long);    PATCH_MEMBER(int, OnSkill, CNSCharacter * _COMMA unsigned long, 0x4946E0);
	CNSPcStateAttack & operator=(const CNSPcStateAttack &);
	//void __dflt_ctor_closure();
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcStateAttack &, CNSPcStateAttack, Constructor, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcStateAttack, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcStateAttack, Init, );
	PATCH_MEMBER_INVOKE(void, CNSPcStateAttack, Action, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcStateAttack, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSPcStateAttack, OnAttack, CNSCharacter * _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSPcStateAttack, OnPickItem, CNSCharacter * _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcStateAttack, OnSkill, CNSCharacter * _COMMA unsigned long);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcStateAttack::Constructor(CNSPc *), 0x494130);
	//DEFINE_NAKED_JMP(CNSPcStateAttack::Destructor(), 0x494190);
	//DEFINE_NAKED_JMP(void CNSPcStateAttack::Init(), 0x4941B0);
	//DEFINE_NAKED_JMP(void CNSPcStateAttack::Action(unsigned long), 0x494BE0);
	//DEFINE_NAKED_JMP(int CNSPcStateAttack::TraceTarget(CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4941D0);
	//DEFINE_NAKED_JMP(void CNSPcStateAttack::OnAttack(CNSCharacter * _COMMA unsigned long), 0x4942D0);
	//DEFINE_NAKED_JMP(void CNSPcStateAttack::OnPickItem(CNSCharacter * _COMMA unsigned long), 0x494500);
	//DEFINE_NAKED_JMP(int CNSPcStateAttack::OnSkill(CNSCharacter * _COMMA unsigned long), 0x4946E0);
#endif
};





#endif