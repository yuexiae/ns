#ifndef NSHEADER_NS_DAMAGE_COUNTER_H_
#define NSHEADER_NS_DAMAGE_COUNTER_H_


#include <map>
#include "ns_header/ns_critical_section.h"



class CNSDamageCounter {
public:
	static const unsigned int _size = 0x49c;

	struct _Attacker {
		static const unsigned int _size = 0x24;
		unsigned long dwObjectId;//this+0x0
		char szUserAlias[0x19];//this+0x4
		unsigned long dwTotalDamage;//this+0x20
	};
	
	class std::map<unsigned long,CNSDamageCounter::_Attacker *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSDamageCounter::_Attacker *> > > m_mapAttacker;//this+0x4
	class std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,unsigned long> > > m_mapDamage;//this+0x24
	CNSDamageCounter(const CNSDamageCounter &);
	CNSDamageCounter();    PATCH_MEMBER(CNSDamageCounter &, Constructor, , 0x42A230);
	virtual ~CNSDamageCounter();    PATCH_MEMBER(void, Destructor, , 0x42A2F0);
	void SetParent(CNSCharacter *);    PATCH_MEMBER(void, SetParent, CNSCharacter *, 0x426A40);
	void Init();    PATCH_MEMBER(void, Init, , 0x42A370);
	unsigned long GetSize();
	unsigned long GetTotalDamage();
	unsigned long GetTotalBestDamage();
	unsigned long GetUserDamage(unsigned long);    PATCH_MEMBER(unsigned long, GetUserDamage, unsigned long, 0x44A9D0);
	void Add(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, Add, CNSCharacter * _COMMA unsigned long, 0x42A460);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x42A7A0);
	int _CheckTagetLength(unsigned long);    PATCH_MEMBER(int, _CheckTagetLength, unsigned long, 0x42A8C0);
	void MakeBestUser();    PATCH_MEMBER(void, MakeBestUser, , 0x42A990);
	void DivisionExp(unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(void, DivisionExp, unsigned long _COMMA unsigned long _COMMA unsigned short, 0x42ACA0);
	std::_Tree<std::_Tmap_traits<unsigned long,CNSDamageCounter::_Attacker *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSDamageCounter::_Attacker *> >,0> >::iterator GetBestUserIter(int);
	char * GetBestUserAlias(int);    PATCH_MEMBER(char *, GetBestUserAlias, int, 0x42B380);
	int CheckBestUserAlias(int, char *);    PATCH_MEMBER(int, CheckBestUserAlias, int _COMMA char *, 0x42B450);
	float GetUserAttackPer(unsigned long);    PATCH_MEMBER(float, GetUserAttackPer, unsigned long, 0x42B5C0);
	int IsBestUser(unsigned long);    PATCH_MEMBER(int, IsBestUser, unsigned long, 0x42A3E0);
	static void CalcDivisionExp(int, unsigned long, unsigned long, unsigned long &, unsigned long &);    PATCH_STATIC(void, CalcDivisionExp, int _COMMA unsigned long _COMMA unsigned long _COMMA unsigned long & _COMMA unsigned long &, 0x42B800);
	class CNSCriticalSection m_cs;//this+0x44
	class CNSCharacter * m_pParent;//this+0x460
	int m_bDead;//this+0x464
	unsigned long m_dwTotalDamage;//this+0x468
	unsigned long m_dwTotalBestDamage;//this+0x46C
	unsigned long m_dwTotalLowDamage;//this+0x470
	class std::_Tree<std::_Tmap_traits<unsigned long,CNSDamageCounter::_Attacker *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSDamageCounter::_Attacker *> >,0> >::iterator m_BestUser_IterArray[0x5];//this+0x474
	int _DivisionExp(unsigned long, unsigned long, unsigned long, unsigned short, std::_Tree<std::_Tmap_traits<unsigned long,CNSDamageCounter::_Attacker *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSDamageCounter::_Attacker *> >,0> >::iterator);    PATCH_MEMBER(int, _DivisionExp, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSDamageCounter::_Attacker * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSDamageCounter::_Attacker *> > _COMMA 0> >::iterator, 0x42B040);
	void _AddUserDamage(unsigned long, unsigned long);    PATCH_MEMBER(void, _AddUserDamage, unsigned long _COMMA unsigned long, 0x42B6D0);
	CNSDamageCounter & operator=(const CNSDamageCounter &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSDamageCounter &, CNSDamageCounter, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, SetParent, CNSCharacter *);
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, Init, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSDamageCounter, GetUserDamage, unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, Add, CNSCharacter * _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSDamageCounter, _CheckTagetLength, unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, MakeBestUser, );
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, DivisionExp, unsigned long _COMMA unsigned long _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(char *, CNSDamageCounter, GetBestUserAlias, int);
	PATCH_MEMBER_INVOKE(int, CNSDamageCounter, CheckBestUserAlias, int _COMMA char *);
	PATCH_MEMBER_INVOKE(float, CNSDamageCounter, GetUserAttackPer, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSDamageCounter, IsBestUser, unsigned long);
	PATCH_STATIC_INVOKE(void, CalcDivisionExp, int _COMMA unsigned long _COMMA unsigned long _COMMA unsigned long & _COMMA unsigned long &);
	PATCH_MEMBER_INVOKE(int, CNSDamageCounter, _DivisionExp, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSDamageCounter::_Attacker * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSDamageCounter::_Attacker *> > _COMMA 0> >::iterator);
	PATCH_MEMBER_INVOKE(void, CNSDamageCounter, _AddUserDamage, unsigned long _COMMA unsigned long);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSDamageCounter::Constructor(), 0x42A230);
	//DEFINE_NAKED_JMP(CNSDamageCounter::Destructor(), 0x42A2F0);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::SetParent(CNSCharacter *), 0x426A40);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::Init(), 0x42A370);
	//DEFINE_NAKED_JMP(unsigned long CNSDamageCounter::GetUserDamage(unsigned long), 0x44A9D0);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::Add(CNSCharacter * _COMMA unsigned long), 0x42A460);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::Clear(), 0x42A7A0);
	//DEFINE_NAKED_JMP(int CNSDamageCounter::_CheckTagetLength(unsigned long), 0x42A8C0);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::MakeBestUser(), 0x42A990);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::DivisionExp(unsigned long _COMMA unsigned long _COMMA unsigned short), 0x42ACA0);
	//DEFINE_NAKED_JMP(char * CNSDamageCounter::GetBestUserAlias(int), 0x42B380);
	//DEFINE_NAKED_JMP(int CNSDamageCounter::CheckBestUserAlias(int _COMMA char *), 0x42B450);
	//DEFINE_NAKED_JMP(float CNSDamageCounter::GetUserAttackPer(unsigned long), 0x42B5C0);
	//DEFINE_NAKED_JMP(int CNSDamageCounter::IsBestUser(unsigned long), 0x42A3E0);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::CalcDivisionExp(int _COMMA unsigned long _COMMA unsigned long _COMMA unsigned long & _COMMA unsigned long &), 0x42B800);
	//DEFINE_NAKED_JMP(int CNSDamageCounter::_DivisionExp(unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSDamageCounter::_Attacker * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSDamageCounter::_Attacker *> > _COMMA 0> >::iterator), 0x42B040);
	//DEFINE_NAKED_JMP(void CNSDamageCounter::_AddUserDamage(unsigned long _COMMA unsigned long), 0x42B6D0);
#endif
};






#endif