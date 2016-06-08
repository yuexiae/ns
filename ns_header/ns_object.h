#ifndef NSHEADER_NS_OBJECT_H_
#define NSHEADER_NS_OBJECT_H_

#include <windows.h>
#include "ns_header/ns_point2.h"


class CNSObject {
public:
	static const unsigned int _size = 0x1c;

	enum OBJECTTYPE {
		ObjectType_NULL = 0x0,
		ObjectType_Pc = 0x1,
		ObjectType_Npc = 0x2,
		ObjectType_Mob = 0x3,
		ObjectType_Item = 0x4,
		ObjectType_Party = 0x5,
		ObjectType_Object = 0x6,
		ObjectType_Pet = 0x7,
		ObjectType_Guild = 0x8,
		ObjectType_End = 0x9,
	};

	enum REGIONTYPE {
		RegionType_NULL = 0x0,
		RegionType_Mystery = 0x1,
		RegionType_Technic = 0x2,
		RegionType_Nature = 0x3,
		RegionType_RopeIsle = 0x4,
		RegionType_End = 0x5,
		RegionType_Instance = 0x50,
	};

	enum HITTYPE {
		HitType_Normal = 0x0,
		HitType_Critical = 0x1,
		HitType_Skill = 0x2,
		HitType_MachieAblity = 0x3,
		HitType_Direct = 0x4,
	};


	template <typename T>
	class Owner {
	public:
		static const unsigned int _size = 0x4;

		Owner() : m_pObject(NULL) {}

		explicit Owner(T *pObject) : m_pObject(pObject) { }

		Owner(const Owner& rhs) {
			this->m_pObject = rhs.m_pObject;
			rhs.m_pObject = NULL;
		}

		Owner & operator=(Owner& rhs) {
			if (this->m_pObject) {
				this->m_pObject->DecRefCount();
			}
			this->m_pObject = rhs.m_pObject;
			rhs.m_pObject = NULL;
			return *this;
		}

		~Owner() {
			if (m_pObject) {
				m_pObject->DecRefCount();
				m_pObject = NULL;
			}
		}

		inline T *Get() const { return m_pObject; }

		inline operator T*() const { return m_pObject; }


		inline T& operator*() const { return *m_pObject; }


		T * operator->() const { return m_pObject; }

		inline Owner<T> Copy() {
			m_pObject->IncRefCount();
			return Owner<T>(m_pObject);
		}

        T * Strip() {
            T *pObject = m_pObject;
            m_pObject = NULL;
            return pObject;
        }

        template <typename X>
        Owner<X> Convert() {
            T *pObject = m_pObject;
            m_pObject = NULL;
            return Owner<X>(reinterpret_cast<X *>(pObject));
        }

		inline bool operator==(T* ptr) const {
			return (m_pObject == ptr);
		}

		inline bool operator!=(T* ptr) const {
			return (m_pObject != ptr);
		}

		inline bool operator==(const Owner& ptr) const {
			return (m_pObject == ptr);
		}

		inline bool operator!=(const Owner& ptr) const {
			return (m_pObject != ptr);
		}

	private:
		T *m_pObject;
	};

	/*
	struct Owner {
		static const unsigned int _size = 0x4;

		Owner(CNSObject *pObject) : m_pObject(pObject) {}   PATCH_MEMBER(CNSObject::Owner &, Constructor, CNSObject *, 0x45AFF0);
		~Owner() { if (m_pObject) m_pObject->DecRefCount(); }    PATCH_MEMBER(void, Destructor, , 0x45B010);
		class CNSObject * m_pObject;//this+0x0
		//void * __vecDelDtor(unsigned int);

		struct _Invoke {
		PATCH_MEMBER_INVOKE(CNSObject::Owner &, CNSObject::Owner, Constructor, CNSObject *);
		PATCH_MEMBER_INVOKE(void, CNSObject::Owner, Destructor, );
		};
	private:
		Owner(Owner&);
		Owner& operator=(Owner&);
	};
	*/

	CNSObject(const CNSObject &);
	CNSObject();    PATCH_MEMBER(CNSObject &, Constructor, , 0x45AEB0);
	virtual ~CNSObject();    PATCH_MEMBER(void, Destructor, , 0x45AF50);
	void Register(CNSObject::OBJECTTYPE, unsigned long, CNSObject *);    PATCH_MEMBER(void, Register, CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *, 0x45AFC0);
	void Register(CNSObject::OBJECTTYPE, CNSObject *);    PATCH_MEMBER(void, Register, CNSObject::OBJECTTYPE _COMMA CNSObject *, 0x45AF90);
	void IncRefCount();    PATCH_MEMBER(void, IncRefCount, , 0x419B70);
	void DecRefCount();    PATCH_MEMBER(void, DecRefCount, , 0x419C70);
	unsigned long GetRefCount();    PATCH_MEMBER(unsigned long, GetRefCount, , 0x402210);
	static unsigned long GetTotalObjectCount();
	unsigned long GetObjectId();    PATCH_MEMBER(unsigned long, GetObjectId, , 0x402B90);
	CNSObject::OBJECTTYPE GetType();   PATCH_MEMBER(CNSObject::OBJECTTYPE, GetType, , 0x4235C0);
	unsigned long GetId();
	unsigned long GetIndex();
	unsigned long GetLongIndex();
	NSPOINT2 & GetCell();    PATCH_MEMBER(NSPOINT2 &, GetCell, , 0x423AB0);
	NSPOINT2 & GetCellDest();    PATCH_MEMBER(NSPOINT2 &, GetCellDest, , 0x458C30);
	NSPOINT2 & GetVrBlock();    PATCH_MEMBER(NSPOINT2 &, GetVrBlock, , 0x4DF2A0);
	unsigned char GetSize();    PATCH_MEMBER(unsigned char, GetSize, , 0x423AD0);
	unsigned char GetRegion();    PATCH_MEMBER(unsigned char, GetRegion, , 0x482A20);
	void SetCell(NSPOINT2 &);    PATCH_MEMBER(void, SetCell, NSPOINT2 &, 0x482790);
	void SetCellDest(NSPOINT2 &);    PATCH_MEMBER(void, SetCellDest, NSPOINT2 &, 0x44C3D0);
	void SetVrBlock(NSPOINT2 &);    PATCH_MEMBER(void, SetVrBlock, NSPOINT2 &, 0x4DF1C0);
	void SetRegion(unsigned char);    PATCH_MEMBER(void, SetRegion, unsigned char, 0x4502E0);
	void SetSize(unsigned char);
	int IsNpcClass();    PATCH_MEMBER(int, IsNpcClass, , 0x423AF0);
	int IsPcClass();    PATCH_MEMBER(int, IsPcClass, , 0x4236B0);
	unsigned long m_dwObjectId;//this+0x4
	long m_nRefCount;//this+0x8
	static long ms_nObjects;//[0x55CC70]  [0015CC70:0003:0003CC70]
	class NSPOINT2 m_cell;//this+0xC
	class NSPOINT2 m_cellDest;//this+0x10
	class NSPOINT2 m_block;//this+0x14
	unsigned char m_btRegion;//this+0x18
	unsigned char m_btSize;//this+0x19
	CNSObject & operator=(const CNSObject &);    //PATCH_MEMBER(CNSObject &, operator=, const CNSObject &, 0x41ABD0);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSObject &, CNSObject, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSObject, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSObject, Register, CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *);
	PATCH_MEMBER_INVOKE(void, CNSObject, Register, CNSObject::OBJECTTYPE _COMMA CNSObject *);
	PATCH_MEMBER_INVOKE(void, CNSObject, IncRefCount, );
	PATCH_MEMBER_INVOKE(void, CNSObject, DecRefCount, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSObject, GetRefCount, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSObject, GetObjectId, );
	PATCH_MEMBER_INVOKE(CNSObject::OBJECTTYPE, CNSObject, GetType, );
	PATCH_MEMBER_INVOKE(NSPOINT2 &, CNSObject, GetCell, );
	PATCH_MEMBER_INVOKE(NSPOINT2 &, CNSObject, GetCellDest, );
	PATCH_MEMBER_INVOKE(NSPOINT2 &, CNSObject, GetVrBlock, );
	PATCH_MEMBER_INVOKE(unsigned char, CNSObject, GetSize, );
	PATCH_MEMBER_INVOKE(unsigned char, CNSObject, GetRegion, );
	PATCH_MEMBER_INVOKE(void, CNSObject, SetCell, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(void, CNSObject, SetCellDest, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(void, CNSObject, SetVrBlock, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(void, CNSObject, SetRegion, unsigned char);
	PATCH_MEMBER_INVOKE(int, CNSObject, IsNpcClass, );
	PATCH_MEMBER_INVOKE(int, CNSObject, IsPcClass, );
	//PATCH_MEMBER_INVOKE(CNSObject &, CNSObject, operator=, const CNSObject &);
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSObject::Constructor(), 0x45AEB0);
	//DEFINE_NAKED_JMP(CNSObject::Destructor(), 0x45AF50);
	//DEFINE_NAKED_JMP(void CNSObject::Register(CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *), 0x45AFC0);
	//DEFINE_NAKED_JMP(void CNSObject::Register(CNSObject::OBJECTTYPE _COMMA CNSObject *), 0x45AF90);
	DEFINE_NAKED_JMP(void CNSObject::IncRefCount(), 0x419B70);
	DEFINE_NAKED_JMP(void CNSObject::DecRefCount(), 0x419C70);
	DEFINE_NAKED_JMP(unsigned long CNSObject::GetRefCount(), 0x402210);
	DEFINE_NAKED_JMP(unsigned long CNSObject::GetObjectId(), 0x402B90);
	DEFINE_NAKED_JMP(CNSObject::OBJECTTYPE CNSObject::GetType(), 0x4235C0);
	DEFINE_NAKED_JMP(NSPOINT2 & CNSObject::GetCell(), 0x423AB0);
	DEFINE_NAKED_JMP(NSPOINT2 & CNSObject::GetCellDest(), 0x458C30);
	DEFINE_NAKED_JMP(NSPOINT2 & CNSObject::GetVrBlock(), 0x4DF2A0);
	DEFINE_NAKED_JMP(unsigned char CNSObject::GetSize(), 0x423AD0);
	DEFINE_NAKED_JMP(unsigned char CNSObject::GetRegion(), 0x482A20);
	DEFINE_NAKED_JMP(void CNSObject::SetCell(NSPOINT2 &), 0x482790);
	DEFINE_NAKED_JMP(void CNSObject::SetCellDest(NSPOINT2 &), 0x44C3D0);
	DEFINE_NAKED_JMP(void CNSObject::SetVrBlock(NSPOINT2 &), 0x4DF1C0);
	DEFINE_NAKED_JMP(void CNSObject::SetRegion(unsigned char), 0x4502E0);
	DEFINE_NAKED_JMP(int CNSObject::IsNpcClass(), 0x423AF0);
	DEFINE_NAKED_JMP(int CNSObject::IsPcClass(), 0x4236B0);
	//DEFINE_NAKED_JMP(CNSObject & CNSObject::operator=(const CNSObject &), 0x41ABD0);
#endif





/*
class __declspec(align(4)) CNSObject {
public:
enum OBJECTTYPE {
ObjectType_NULL = 0x0,
ObjectType_Pc = 0x1,
ObjectType_Npc = 0x2,
ObjectType_Mob = 0x3,
ObjectType_Item = 0x4,
ObjectType_Party = 0x5,
ObjectType_Object = 0x6,
ObjectType_Pet = 0x7,
ObjectType_Guild = 0x8,
ObjectType_End = 0x9,
};


enum HITTYPE {
HitType_Normal = 0x0,
HitType_Critical = 0x1,
HitType_Skill = 0x2,
HitType_MachieAblity = 0x3,
HitType_Direct = 0x4,
};

enum REGIONTYPE {
RegionType_NULL = 0x0,
RegionType_Mystery = 0x1,
RegionType_Technic = 0x2,
RegionType_Nature = 0x3,
RegionType_RopeIsle = 0x4,
RegionType_End = 0x5,
RegionType_Instance = 0x50,
};

//use new vtable
CNSObject() {
this->m_dwObjectId = -1;
this->m_nRefCount = 0;
m_btRegion = 0;
m_cell.y = 0;
m_cell.x = 0;
m_cellDest.y = 0;
m_cellDest.x = 0;
m_block.y = 0;
m_block.x = 0;
InterlockedIncrement((volatile LONG *)0x0055CC70); //CNSObject::ms_nObjects
}

virtual ~CNSObject() {
Destructor();
}


void IncRefCount() {
InterlockedIncrement((volatile LONG *)&this->m_nRefCount);
}

OBJECTTYPE GetType() {
return static_cast<OBJECTTYPE>((this->m_dwObjectId >> 16) >> 20);
}

BOOL IsNpcClass(){
OBJECTTYPE type = GetType();
return type == ObjectType_Npc
|| type == ObjectType_Mob
|| type == ObjectType_Object
|| type == ObjectType_Pet;
}

BOOL IsPcClass() {
return GetType() == ObjectType_Pc;
}

unsigned int m_dwObjectId;
int m_nRefCount;
NSPOINT2 m_cell;
NSPOINT2 m_cellDest;
NSPOINT2 m_block;
unsigned char m_btRegion;
unsigned char m_btSize;


//void __thiscall CNSObject::IncRefCount(void);
void __thiscall CNSObject::DecRefCount(void);
CNSObject & __thiscall CNSObject::operator=(CNSObject const &);
CNSObject::OBJECTTYPE __thiscall CNSObject::GetType(void)const ;
int __thiscall CNSObject::IsPcClass(void);
NSPOINT2 & __thiscall CNSObject::GetCell(void);
unsigned char __thiscall CNSObject::GetSize(void)const ;
int __thiscall CNSObject::IsNpcClass(void);
void __thiscall CNSObject::SetCellDest(NSPOINT2 &);
void __thiscall CNSObject::SetRegion(unsigned char);
NSPOINT2 & __thiscall CNSObject::GetCellDest(void);
__thiscall CNSObject::CNSObject(void);
void __thiscall CNSObject::Destructor(void);
void __thiscall CNSObject::Register(CNSObject::OBJECTTYPE,CNSObject *);
void __thiscall CNSObject::Register(CNSObject::OBJECTTYPE,unsigned long,CNSObject *);
virtual void * __thiscall CNSObject::`vector deleting destructor'(unsigned int);
void __thiscall CNSObject::SetCell(NSPOINT2 &);
void __thiscall CNSObject::SetVrBlock(NSPOINT2 &);
NSPOINT2 & __thiscall CNSObject::GetVrBlock(void);
};
*/


#endif