#include <iostream>
#include <vector>

int Decrypt(int, int);
int Encrypt(int, int);

int main() {
	std::cout << Decrypt(924083900, -731769801) << std::endl;
	std::cout << Encrypt(1000, -731769801) << std::endl;
	return 0;
}

int Decrypt(int encryptedValue, int key) {
	static int ret;
	static std::vector<unsigned char> v1(4);
	static std::vector<unsigned char> v2(4);

	memcpy(v1.data(), &encryptedValue, 4);
	memcpy(v2.data(), &key, 4);
	std::reverse(v2.begin(), v2.end());

	for (auto i = 0; i < 4; ++i) v1[i] ^= v2[i];

	ret = *(int*) v1.data();

	return ret;
}

int Encrypt(int value, int key) {
	static int ret;
	static std::vector<unsigned char> result(4);
	
	memcpy(result.data(), &key, 4);
	std::reverse(result.begin(), result.end());

	ret = *(int*)result.data() ^ value;
	return ret;
}