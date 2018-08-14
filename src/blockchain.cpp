    #include "blockchain.h"
    
    Blockchain::Blockchain()
    {
        chain.push_back(create_genesis_block());
    }

    void Blockchain::add_new_block(std::string data)
    {
        const Block& previous_block = get_last_block();
        uint_fast32_t index = previous_block.get_index() + uint_fast32_t(1);

        Block new_block(index, time_t(nullptr), data, previous_block.get_hash());
        chain.push_back(new_block);
    }

    const Block& Blockchain::get_last_block() const
    {
        return chain.back();
    }

    Block Blockchain::create_genesis_block() const
    {
        return Block(0, time_t(nullptr), "Genesis Block: Created by Oleksandr Bazna");
    }

    bool Blockchain::is_chain_valid() const
    {
        for (auto block_index = 1; block_index < chain.size(); ++block_index)
        {
            const auto& current_block = chain[block_index];
            if (current_block.get_hash() != current_block.calculate_hash())
            {
                return false;
            }

            const auto& previous_block = chain[block_index - 1];
            if (current_block.get_previous_hash() != previous_block.get_hash())
            {
                return false;
            }
        }

        return true;
    }