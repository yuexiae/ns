#ifndef NSHEADER_NS_PRODUCT_H_
#define NSHEADER_NS_PRODUCT_H_



class CNSProduct {
public:
	static const unsigned int _size = 0x38;

	CNSProduct();    PATCH_MEMBER(CNSProduct &, Constructor, , 0x4995B0);
	unsigned short GetSkillId();    PATCH_MEMBER(unsigned short, GetSkillId, , 0x4C82D0);
	unsigned short m_wItemId;//this+0x0
	unsigned short m_wSkillId;//this+0x2
	unsigned char m_btSkillLevel;//this+0x4
	unsigned short m_wMaterialIdArray[0x6];//this+0x6
	unsigned char m_btCountArray[0x6];//this+0x12
	unsigned short m_wNs;//this+0x18
	unsigned char m_btSuccessRate;//this+0x1A
	unsigned char m_btLimitLevel;//this+0x1B
	unsigned char m_btRare;//this+0x1C
	unsigned char m_btKind;//this+0x1D
	char m_szItemName[0x19];//this+0x1E

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSProduct &, CNSProduct, Constructor, );
	PATCH_MEMBER_INVOKE(unsigned short, CNSProduct, GetSkillId, );
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSProduct::Constructor(), 0x4995B0);
	//DEFINE_NAKED_JMP(unsigned short CNSProduct::GetSkillId(), 0x4C82D0);
#endif
};




class CNSProductList {
public:
	static const unsigned int _size = 0x1c18;

	CNSProductList(const CNSProductList &);
	CNSProductList();    PATCH_MEMBER(CNSProductList &, Constructor, , 0x4978E0);
	virtual ~CNSProductList();    PATCH_MEMBER(void, Destructor, , 0x497930);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481CD0);
	void SetActiveItem(unsigned short, unsigned char);    PATCH_MEMBER(void, SetActiveItem, unsigned short _COMMA unsigned char, 0x4C82F0);
	void SetActiveItemObjectId(unsigned long, unsigned char);    PATCH_MEMBER(void, SetActiveItemObjectId, unsigned long _COMMA unsigned char, 0x4C8320);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x497950);
	CNSProduct * Add(unsigned short);    PATCH_MEMBER(CNSProduct *, Add, unsigned short, 0x497980);
	CNSProduct * Get(unsigned short, int);    PATCH_MEMBER(CNSProduct *, Get, unsigned short _COMMA int, 0x497AA0);
	int Check(unsigned short);    PATCH_MEMBER(int, Check, unsigned short, 0x497BC0);
	int Check(CNSProduct *);    PATCH_MEMBER(int, Check, CNSProduct *, 0x497B10);
	int Make(CNSSkill *);    PATCH_MEMBER(int, Make, CNSSkill *, 0x497C30);
	int Resolution(int, CNSSkill *, unsigned char);    PATCH_MEMBER(int, Resolution, int _COMMA CNSSkill * _COMMA unsigned char, 0x498210);
	int CalcExpPoint();
	unsigned short PacketProductList(CPacket &, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(unsigned short, PacketProductList, CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x498690);
	int GetProductDescription(unsigned short, char *);    PATCH_MEMBER(int, GetProductDescription, unsigned short _COMMA char *, 0x498AB0);
	class CNSPc * m_pPc;//this+0x4
	unsigned short m_wActiveItemId;//this+0x8
	unsigned long m_dwActiveObjectId;//this+0xC
	unsigned long m_dwCount;//this+0x10
	unsigned char m_btActiveOption;//this+0x14
	class CNSProduct m_productList[0x80];//this+0x16
	CNSProductList & operator=(const CNSProductList &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSProductList &, CNSProductList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSProductList, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSProductList, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSProductList, SetActiveItem, unsigned short _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(void, CNSProductList, SetActiveItemObjectId, unsigned long _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(void, CNSProductList, Clear, );
	PATCH_MEMBER_INVOKE(CNSProduct *, CNSProductList, Add, unsigned short);
	PATCH_MEMBER_INVOKE(CNSProduct *, CNSProductList, Get, unsigned short _COMMA int);
	PATCH_MEMBER_INVOKE(int, CNSProductList, Check, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSProductList, Check, CNSProduct *);
	PATCH_MEMBER_INVOKE(int, CNSProductList, Make, CNSSkill *);
	PATCH_MEMBER_INVOKE(int, CNSProductList, Resolution, int _COMMA CNSSkill * _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(unsigned short, CNSProductList, PacketProductList, CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSProductList, GetProductDescription, unsigned short _COMMA char *);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSProductList::Constructor(), 0x4978E0);
	//DEFINE_NAKED_JMP(CNSProductList::Destructor(), 0x497930);
	//DEFINE_NAKED_JMP(void CNSProductList::SetParent(CNSPc *), 0x481CD0);
	//DEFINE_NAKED_JMP(void CNSProductList::SetActiveItem(unsigned short _COMMA unsigned char), 0x4C82F0);
	//DEFINE_NAKED_JMP(void CNSProductList::SetActiveItemObjectId(unsigned long _COMMA unsigned char), 0x4C8320);
	//DEFINE_NAKED_JMP(void CNSProductList::Clear(), 0x497950);
	//DEFINE_NAKED_JMP(CNSProduct * CNSProductList::Add(unsigned short), 0x497980);
	//DEFINE_NAKED_JMP(CNSProduct * CNSProductList::Get(unsigned short _COMMA int), 0x497AA0);
	//DEFINE_NAKED_JMP(int CNSProductList::Check(unsigned short), 0x497BC0);
	//DEFINE_NAKED_JMP(int CNSProductList::Check(CNSProduct *), 0x497B10);
	//DEFINE_NAKED_JMP(int CNSProductList::Make(CNSSkill *), 0x497C30);
	//DEFINE_NAKED_JMP(int CNSProductList::Resolution(int _COMMA CNSSkill * _COMMA unsigned char), 0x498210);
	//DEFINE_NAKED_JMP(unsigned short CNSProductList::PacketProductList(CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x498690);
	//DEFINE_NAKED_JMP(int CNSProductList::GetProductDescription(unsigned short _COMMA char *), 0x498AB0);
#endif
};






#endif