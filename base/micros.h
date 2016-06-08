#ifndef BASE_MICROS_H_
#define BASE_MICROS_H_

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#define STRUCT_OFFSET(classname, member) ((size_t)&(((classname*)0)->member))

#define _COMMA	,

#define DEFINE_NAKED_JMP(function, addr) __declspec(naked) function { static const unsigned int saddr = addr; __asm { jmp saddr }; }

#define DEFINE_STATIC_MEMBER(type, name, addr) static inline type name() { return reinterpret_cast<type>(addr); }

#define DEFINE_NAKED_VTABLE(name, function, num) __declspec(naked) function { static const unsigned int saddr = name::_vtable + 4 * num;__asm mov eax, dword ptr[saddr]  __asm jmp dword ptr[eax] }

template <typename T, unsigned int ADDR>
struct DefineInstance {
    static T* Instance() {
        return *reinterpret_cast<T **>(ADDR); 
    }
};

#endif