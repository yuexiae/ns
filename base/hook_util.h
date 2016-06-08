#ifndef BASE_HOOK_UTIL_H_
#define BASE_HOOK_UTIL_H_



#define PATCH_STATIC(_type, _name, _args, _addr) \
	static bool _Patch##_name(_type (*filter)(_args), _type (**invoke)(_args)) { \
		return base::HookUtil::PatchFunction(_addr, filter, invoke);\
	} \
	static bool _Patch##_name(_type (*filter)(_args)) { \
		return base::HookUtil::PatchFunction(_addr, filter);\
	}


#define PATCH_MEMBER(_type, _name, _args, _addr) \
	template <typename X, typename Y> \
	static bool _Patch##_name(_type (X::*filter)(_args), _type (Y::**invoke)(_args)) { \
		return base::HookUtil::PatchFunction(_addr, filter, invoke);\
	} \
	template <typename X> \
	static bool _Patch##_name(_type (X::*filter)(_args)) { \
		return base::HookUtil::PatchFunction(_addr, filter);\
	}

#define PATCH_STATIC_INVOKE(_type, _name, _args) _type (*_name)(_args)

#define PATCH_MEMBER_INVOKE(_type, _class, _name, _args) _type (_class::*_name)(_args)

namespace base {

template <typename T>
__declspec(naked) static void* GetDtor() {
    __asm mov  eax, T::~T __asm ret
}

class HookUtil {
public:
	static void PatchBytes(unsigned int address, unsigned char ch, unsigned int len);

	static void PatchBytes(unsigned int address, void *data, unsigned int len);
	
	static void PatchUChar(unsigned int address, unsigned char data);

	static void PatchUShort(unsigned int address, unsigned short data);

	static void PatchULong(unsigned int address, unsigned long data);

	template <typename F, typename X, typename N>
	static bool PatchFunction(F old_address, X filter_address, N new_address) {
		return PatchFunctionImpl((unsigned char *)old_address, (void *)*(unsigned int *)&filter_address, new_address);
	}

	template <typename F, typename X>
	static bool PatchFunction(F old_address, X filter_address) {
		unsigned int temp = NULL;
		return PatchFunctionImpl((unsigned char *)old_address, (void *)*(unsigned int *)&filter_address, &temp);
	}

    template <typename X>
    static bool PatchCtor(const char *dll, const char *name, X filter_address) {
        HMODULE handle = GetModuleHandleA(dll);
        if (handle) {
            void *addr = ::GetProcAddress(handle, name);
            return addr ? PatchFunction(addr, filter_address) : false;
        } else {
            return false;
        }
    }
    
    template <typename T, typename X>
    static bool PatchDtor(X filter_address) {
        return PatchFunction(GetDtor<T>(), filter_address);
    }

private:
	static bool PatchFunctionImpl(unsigned char *address, void *filter_address, void *new_address);
};


}//namespace base {


#endif