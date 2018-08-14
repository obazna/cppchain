#ifndef CPPCHAIN_BLOCK_H_
#define CPPCHAIN_BLOCK_H_

#include <cstdint>
#include <string>

class Block 
{
public:
    Block(const uint32_t& index, const time_t& timestamp, const std::string& data, const std::string& previous_hash = "");

    const std::string& get_hash() const;
    const std::string& get_previous_hash() const;
    uint32_t get_index() const;
    std::string calculate_hash() const;

private:
    uint32_t index;
    std::string previous_hash;
    time_t timestamp;
    std::string data;
    std::string hash;
    int64_t nonce;
};

#endif // CPPCHAIN_BLOCK_H_