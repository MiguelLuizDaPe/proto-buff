#include <bit>
#include <array>
#include <cstdint>
#include <cstdio>


template<typename T> 
auto bytesOf(T const& data){
	auto bytes = std::bit_cast<std::array<std::uint8_t, sizeof(T)>>(data);
	// std::cout << "cu";
	return bytes;
}

bool isLittleEndian(){
	uint8_t a = 1;
	auto result = bytesOf(a);
	return result[0] == 1;
}

template<typename T> 
auto swapBytes(T const& data){
	auto bytes = bytesOf(data);
	if(isLittleEndian()){
		for(int i = 0; i < bytes.size() / 2; i++){
			auto temp = bytes[i];
			bytes[i] = bytes[bytes.size() - (i+1)];
			bytes[bytes.size() - (i+1)] = temp;
		}
	}
	return bytes;
}


template<typename T> 
void printBytes(const T& bytes){
	for(int i = 0; i < bytes.size(); i++){
		std::printf("%02x ", bytes[i]);
	}
	std::printf("\n");
}


int main(){
	const int32_t num = 9999;
	auto p = swapBytes(num);
	printBytes(p);
	
	// std::printf("%d", IsLittleEndian());
}

