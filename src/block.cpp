#include "block.h"
#include <sstream>
#include <picosha2.h>

Block::Block(const uint32_t& index, const time_t& timestamp, const std::string& data, const std::string& previous_hash/* = "" */)
    : index(index), previous_hash(previous_hash), timestamp(timestamp), data(data), nonce(0)
{
    hash = calculate_hash();
}

std::string Block::calculate_hash() const
{
    std::stringstream block_data;
    block_data << index << timestamp << data << nonce << previous_hash;
    std::string hash;
    picosha2::hash256_hex_string(block_data.str(), hash);
    return hash;
}

const std:: string& Block::get_hash() const
{
    return hash;
}

const std::string& Block::get_previous_hash() const
{
    return previous_hash;
}

uint32_t Block::get_index() const
{
    return index;
}