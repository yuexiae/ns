#ifndef NSHEADER_NSPUBLIC_H_
#define NSHEADER_NSPUBLIC_H_

namespace NSPublic {


void PrintConsoleTitle();    PATCH_STATIC(void, PrintConsoleTitle, , 0x401030);



#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(void PrintConsoleTitle(), 0x401030);
#endif




};







#endif