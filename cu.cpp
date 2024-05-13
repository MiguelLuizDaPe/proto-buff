#include <bit>
#include <array>
// #include <cstdint>
#include <cstdio>

#include "types.hpp"

template<int N>
using Bytes = std::array<uint8, N>;

uint64 intPow(uint64 a, uint64 b){
	if(b == 0){
		return 1;
	}

    uint64 acc = 1;
    for(uint64 i = 0; i < b; i++){
        acc = acc * a;
    }
    return acc;
}

template<typename T>
constexpr
auto bytesOf(T const& data){
	auto bytes = std::bit_cast<std::array<uint8, sizeof(T)>>(data);
	// std::cout << "cu";
	return bytes;
}

constexpr
bool isLittleEndian(){
	uint16 a = 1;
	auto result = bytesOf(a);
	return result[0] == 1;
}

template<typename T> 
constexpr
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

template<int N>
uint64 bytesToNumberSlow(Bytes<N> bytes){
	uint64 num = 0;
	for(uint64 i = 0; i < N; i++){
		// std::printf("potencia: %ld \n", intPow(2, (((N - 1) - i)*8)));
		// std::printf("byte original: %02x \n", bytes[i]);
		num = num + (uint64)bytes[i] * intPow(2, ((N - (i+1))*8));
		// std::printf("byte mudado: %02lx \n", num);
	}
	return num;
}

template<int N>
uint64 bytesToNumber(Bytes<N> bytes){
	uint64 num = 0;
	for(uint64 i = 0; i < N; i++){
		uint64 p = (N - (i+1)) * 8;
		num |= uint64(bytes[i]) << p;
	}
	return num;
}

template<typename T> 
void printBytes(const T& bytes){
	for(int i = 0; i < bytes.size(); i++){
		std::printf("%02x ", bytes[i]);
	}
	std::printf("\n");
}

Bytes<1> encodeUint8(uint8 num){
	return {num};
}

 uint8 decodeUint8(Bytes<1> bytes){
	return bytes[0];
}

Bytes<1> encodeInt8(int8 num){
	return {std::bit_cast<uint8>(num)};
}

int8 decodeInt8(Bytes<1> num){
	return num[0];
}

Bytes<2> encodeUint16(uint16 num){
	auto bytes = swapBytes(num);
	return bytes;
}

 uint16 decodeUint16(Bytes<2> bytes){
	uint16 num = bytesToNumber<2>(bytes);
	return num;
}

Bytes<2> encodeInt16(int16 num){
	auto bytes = swapBytes(num);
	return bytes;
}

 int16 decodeInt16(Bytes<2> bytes){
	int16 num = bytesToNumber<2>(bytes);
	return num;
}

Bytes<4> encodeUint32(uint32 num){
	auto bytes = swapBytes(num);
	return bytes;
}

 uint32 decodeUint32(Bytes<4> bytes){
	uint32 num = bytesToNumber<4>(bytes);
	return num;
}

Bytes<8> encodeUint64(uint64 num){
	auto bytes = swapBytes(num);
	return bytes;
}

 uint64 decodeUint64(Bytes<8> bytes){
	uint64 num = bytesToNumber<8>(bytes);
	return num;
}


int main(){
	// const uint32 num = 99;
	// auto p = swapBytes(num);
	// printBytes(p);

	auto str = encodeUint64(999999999999999999);
	printBytes(str);
	auto num = decodeUint64(str);
	std::printf("%02lx \n", num);



	
	// std::printf("%d", IsLittleEndian());
}

