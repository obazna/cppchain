#include <string>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>

#include "blockchain.h"

int main() {
    std::cout << "Cppchain" << std::endl;
    Blockchain blockchain;

    std::cout << "Generation blocks..." << std::endl;
    std::cout << "Genesis block is " << blockchain.get_last_block().get_index() << " block(hash: " 
        << blockchain.get_last_block().get_hash() << ")" << std::endl;

    for (const auto& block_name : {"first", "second", "third", "fourth"})
    {
        std::stringstream block_data;
        block_data << "This is " << block_name << "block!";
        blockchain.add_new_block(block_data.str());
        std::cout << "Added " << blockchain.get_last_block().get_index() << " block(hash: " 
            << blockchain.get_last_block().get_hash() << ")" << std::endl;
    }
    blockchain.add_new_block("This is the last block!");

    std::cout << "Is blockchain successfully generated?" << std::endl << (blockchain.is_chain_valid() ? "Yes" : "No") << std::endl;

    std::cout << "Cppchain: to be continued..." << std::endl;
}