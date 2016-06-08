#ifndef BASE_FILE_UTIL_H_
#define BASE_FILE_UTIL_H_

#include <stdlib.h>
#include <boost/uuid/sha1.hpp>

namespace base {

class FileReader {
public:
	FileReader(const char *path) {
		is_success_ = false;
		data_ = NULL;
		size_ = 0;

		FILE *fp = fopen(path, "rb");
		if (fp) {
			fseek(fp, 0, SEEK_END);
			size_ = ftell(fp);
			fseek(fp, 0, SEEK_SET);

			data_ = new char[size_ + 1];
			data_[size_] = '\0';

			if (fread(data_, 1, size_, fp) == size_) {
				is_success_ = true;
			}

			fclose(fp);
		}
	}

	~FileReader() {
		if (data_) {
			delete []data_;
		}
	}

	inline bool IsSuccess() {
		return is_success_;
	}

	inline const char * Get() {
		return data_;
	}

	inline unsigned int Size() {
		return size_;
	}

	std::string sha1() {
		boost::uuids::detail::sha1 sha;
		sha.process_bytes(data_, size_);

		unsigned int digest[5];
		sha.get_digest(digest);

		char temp[256];
		sprintf(temp, "%08x%08x%08x%08x%08x", digest[0], digest[1], digest[2], digest[3], digest[4]);
		return std::string(temp);
	}

private:
	bool is_success_;
	char *data_;
	unsigned int size_;
};




}







#endif