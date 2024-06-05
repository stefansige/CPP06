#include "Serializer.hpp"

int main()
{
    Data originalData(1, "example");

    std::cout << "Original Data address: " << &originalData << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return 0;
}
