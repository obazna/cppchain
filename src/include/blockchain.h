#ifndef CPPCHAIN_BLOCKCHAIN_H_
#define CPPCHAIN_BLOCKCHAIN_H_

#include <vector>
#include <string>

#include "block.h"


class Blockchain 
{
public:
    Blockchain();

    void add_new_block(std::string data);
    bool is_chain_valid() const;
    const Block& get_last_block() const;
    Block create_genesis_block() const;

private:
    std::vector<Block> chain;

};

#endif // CPPCHAIN_BLOCKCHAIN_H_