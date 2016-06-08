#ifndef NSHEADER_NS_CSV_READER_H_
#define NSHEADER_NS_CSV_READER_H_


class CCsvReader {
public:
	static const unsigned int _size = 0x19510;

	CCsvReader(const CCsvReader &);
	CCsvReader(char *);    PATCH_MEMBER(CCsvReader &, Constructor, char *, 0x415D10);
	virtual ~CCsvReader();    PATCH_MEMBER(void, Destructor, , 0x415D50);
	int Open();    PATCH_MEMBER(int, Open, , 0x415D70);
	void Close();    PATCH_MEMBER(void, Close, , 0x415DB0);
	int ReadLine();    PATCH_MEMBER(int, ReadLine, , 0x415DE0);
	unsigned long GetHex();    PATCH_MEMBER(unsigned long, GetHex, , 0x415FA0);
	unsigned char GetBYTE();    PATCH_MEMBER(unsigned char, GetBYTE, , 0x454180);
	unsigned short GetWORD();    PATCH_MEMBER(unsigned short, GetWORD, , 0x454180);
	unsigned long GetDWORD();    PATCH_MEMBER(unsigned long, GetDWORD, , 0x416010);
	char * GetString();    PATCH_MEMBER(char *, GetString, , 0x4541A0);
	struct _iobuf * m_fp;//this+0x4
	char m_szFilename[0x100];//this+0x8
	char m_szLine[0x400];//this+0x108
	char m_szItemArray[100][1024];//this+0x508
	unsigned long m_dwItem;//this+0x19508
	unsigned long m_dwPos;//this+0x1950C
	CCsvReader & operator=(const CCsvReader &);
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CCsvReader &, CCsvReader, Constructor, char *);
	PATCH_MEMBER_INVOKE(void, CCsvReader, Destructor, );
	PATCH_MEMBER_INVOKE(int, CCsvReader, Open, );
	PATCH_MEMBER_INVOKE(void, CCsvReader, Close, );
	PATCH_MEMBER_INVOKE(int, CCsvReader, ReadLine, );
	PATCH_MEMBER_INVOKE(unsigned long, CCsvReader, GetHex, );
	PATCH_MEMBER_INVOKE(unsigned char, CCsvReader, GetBYTE, );
	PATCH_MEMBER_INVOKE(unsigned short, CCsvReader, GetWORD, );
	PATCH_MEMBER_INVOKE(unsigned long, CCsvReader, GetDWORD, );
	PATCH_MEMBER_INVOKE(char *, CCsvReader, GetString, );
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CCsvReader::Constructor(char *), 0x415D10);
	//DEFINE_NAKED_JMP(CCsvReader::Destructor(), 0x415D50);
	//DEFINE_NAKED_JMP(int CCsvReader::Open(), 0x415D70);
	//DEFINE_NAKED_JMP(void CCsvReader::Close(), 0x415DB0);
	//DEFINE_NAKED_JMP(int CCsvReader::ReadLine(), 0x415DE0);
	//DEFINE_NAKED_JMP(unsigned long CCsvReader::GetHex(), 0x415FA0);
	//DEFINE_NAKED_JMP(unsigned char CCsvReader::GetBYTE(), 0x454180);
	//DEFINE_NAKED_JMP(unsigned short CCsvReader::GetWORD(), 0x454180);
	//DEFINE_NAKED_JMP(unsigned long CCsvReader::GetDWORD(), 0x416010);
	//DEFINE_NAKED_JMP(char * CCsvReader::GetString(), 0x4541A0);
#endif
};



#endif