#ifndef BASE_STRING_SPLIT_H_
#define BASE_STRING_SPLIT_H_

#include <stdlib.h>
#include <string.h>

namespace base {

class StringSplit {
public:
	StringSplit(unsigned int count, const char *buffer, char *seps) {
		token_ = (char **)malloc(sizeof(char *) * count);
		string_ = _strdup(buffer);


		char *pNext = NULL;
		char *tokenPtr = strtok_s(string_, seps, &pNext);

		unsigned int i = 0;
		while (tokenPtr != NULL) {
			token_[i] = tokenPtr;
			if (i >= count)
				break;

			tokenPtr = strtok_s(NULL, seps, &pNext);
			++i;
		}

		count_ = i;
	}

	~StringSplit() {
        free(token_);
		free(string_);
	}

	unsigned int Count() { return count_; }

	const char *GetString(unsigned int pos) {
		if (pos < count_) {
			return token_[pos];
		}

		return NULL;
	}

    template <typename T, bool Signed>
    struct convert_integer_sign;

    template <typename T>
    struct convert_integer_sign<T, true> {
        static inline T as(const char *str) {
            return strtol(str, (char**)NULL,10);
        }
    };

    template <typename T>
    struct convert_integer_sign<T, false> {
        static inline T as(const char *str) {
            return static_cast<T>(strtoul(str, (char**)NULL,10));
        }
    };

	template <typename T> 
	T Get(unsigned int pos) {
        return static_cast<T>(convert_integer_sign<T, std::numeric_limits<T>::is_signed>::as(GetString(pos)));
	}
	
	template <>
	const char *Get(unsigned int pos) {
		return GetString(pos);
	}

    template <>
	char *Get(unsigned int pos) {
		return const_cast<char *>(GetString(pos));
	}


	unsigned int GetUINTForHex(unsigned int pos) {
		char *stop;
		return strtol(GetString(pos), &stop, 16);
	}

	bool Icmp(unsigned int pos, char *str) {
		return _stricmp(GetString(pos), str) == 0;
	}

	bool Ncmp(unsigned int pos, char *str, int len) {
		return strncmp(GetString(pos), str, len) == 0;
	}

	bool IsInteger(unsigned int pos) {
		if (pos < count_) {
			char *string = token_[pos];
			if (*string == '\0') {
				return false;
			}

			while (*string != '\0') {
				if (*string < '0' || *string > '9') {
					return false;
				}

				++string;
			}

			return true;
		}

		return false;
	}

private:
	unsigned int count_;
	char *string_;
	char **token_;
};

}//namespace base

#endif